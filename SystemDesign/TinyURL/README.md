# Feature Requirements
Before diving into any details, we need to clarify the feature requirements.

Here, we have two main functional requirements. First, given a URL, the service should generate a shortened alias for it using numbers (0-9) and letters (a-z, A-Z). Second, When queried with a shortened alias, the service should fetch the corresponding long URL and redirect the user to that original URL.

Moreover, we have two non-functional requirements. First, the service must be highly available so that users can access original URLs by providing short IDs whenever they want. Second, the service should respond to requests in a timely manner.  

  
# Scale Estimation
Next step, we should take back of envelope calculation to have a rough idea about the scale of our system.

Let's first estimate the scale of our traffic. Assume we have 10M tiny URLs generated every day, and the ratio of read and write requests is 100 to 1. This implies that the Writes-per-Second (WPS) is 10M / 24/ 3600, which is approximately 100. Besides, it also implies that the Reads-per-Second (RPS) is 100 x 100, equal to 10K. 

Moreover, let's go through the storage estimation. Assume we plan to run the service for 10 years, and the size of each long-and-short URL pair stored in the database is 200 bytes. This shows that the total storage consumption is 10M x 365 x 10 x 200 = 7.3 TB. For reliability, we should double the storage capacity to maintain these URL pairs.


# API Design

### POST /shortend
| Parameters / Return Values    | Data Types    | Input / Output    |
|-------------------------------|---------------|-------------------|
| api_key                       | string        | in                |
| user_id                       | integer       | in                |
| long_url                      | string        | in                |
| short_url                     | string        | out               |

### GET /<short_id>
| Parameters / Return Values    | Data Types    | Input / Output    |
|-------------------------------|---------------|-------------------|
| api_key                       | string        | in                |
| user_id                       | integer       | in                |
| short_id                      | string        | in                |
| long_url                      | string        | out               |
+ `long_url` is specified in the location header.
+ The service returns the status code either 301 or 302.

The response status code 301 means permanent redirection, and the browser will cache the response. For the subsequent queries, the browser will redirect the user to the original URL directly. On the other hand, status code 302 means temporary redirection. For the subsequent queries, the browser will still access TinyURL to retrieve the original URL and redirect the user.

Whether we should use 301 or 302 depends on the business requirements. If we plan to reduce the workload of TinyURL, we can choose 301. On the contrary, if we emphasize analytics, we should use 302 since it helps track the pattern of requests.

# High Level System Design
Now, it is time to have an architectural overview. 

As shown in the picture, the first component is **WebServer**, which serves as a gateway or proxy to distribute requests to internal services including **ID Generation Service** and **URL Service**. Second, ID Generation Service is responsible for generating a short ID for a long URL. Depending on different implementation details, the service may need to integrate another data store to ensure that each short ID is unique. Third, we have URL Service that inserts the long URL and short ID pairs into URL Database and fetches the long URLs using the specified short IDs.

For the write path, a POST request first goes through WebServer, which then requests ID Generation Service using the long URL to create a unique short ID. Once obtaining the short ID, WebServer then requests URL Service to store the long URL and short ID pair.

For the read path, a GET request first goes through WebServer, which then requests URL Service to fetch the long URL using the short ID. Once acquiring the short ID, WebServer responds to the client with the long URL specified in the location header and the status code either 301 or 302.

<p align="center">
  <img src="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/SystemDesign/TinyURL/photos/HighLevelSystemDesign.jpg" size=850/>
</p>

# Database Schema
So far, we have talked about the mappings of long URLs and short IDs. The next question is: how do we store these pairs? We probably need a database since a simple data structure like a hash table is not feasible to serve this volume of traffic. Yet, what is our data model?

As a start, we can choose relational databases, such as MySQL or PostgreSQL as they are relatively mature and widely-used technology. In this application, we use PostgreSQL to build a database that maintains two tables: **User** and **URLMap**.

The first table, User, stores users' account information including name, email, encrypted password, and account creation date. In the second table, URLMap, each row stores the short ID and long URL mapping, its creation dates, and who creates the mapping, which is associated with User table using the foreign key. Additionally, to enhance search performance, we build two indexes on the columns, `short_id`, and `long_url`. 

<p align="center">
  <img src="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/SystemDesign/TinyURL/photos/DatabaseShema.jpg" width=800/>
</p>

# Design Details
## Length of Short IDs
The first detail we should discuss is the length of a short ID. Let's recap the design requirements. First, we plan to run the service for 10 years and we have 10M new tiny URLs generated daily, thus indicating that we will generate 36.5B URLs in 10 years. Second, we use numbers (0-9) and letters (a-z, A-Z), a total of 62 combinations, to encode IDs. Combining these two requirements, if we use the so-called Base62 to generate IDs, the IDs must be at least 6-characters long because 62^6 is around 56.8B, which is greater than 36.5B, and cover the total number of URLs.

## ID Generation Service
Next, we should deep dive into how we create the short IDs. 

### Hash and Conflict Resolution
The idea of the first approach is to hash a given long URL into a Base62-encoded string with 6 characters. It is comprised of 5 steps.
1. First, append the long URL with a random seed.
2. Second, feed this extended string into hash functions like MD5 or SHA1 to generate a hash value.
3. Third, encode the hash value using Base62.
4. Forth, randomly extract a 6-characters-long substring from the encoded string generated above as the ID.
5. Finally, check if the ID already exists or not. If the answer is yes, we need to loop back to the first step. Otherwise, we store the ID and return it.  

To efficiently test whether an ID already exists, BloomFilter is an ideal choice.
In general, the drawback of this approach is that it takes longer to resolve conflicts and generate new and unique IDs as we have stored more and more IDs.

<p align="center">
  <img src="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/SystemDesign/TinyURL/photos/IdGenerationServiceApproach1.jpg" width="350"/>
</p>

### Counter and Ticket Pulling
The idea of the second approach is to simulate the behavior of a ticket machine. In this approach, we maintain a global counter and an array of ID generators. These ID generators take turns to draw an ID from the counter, and the counter accumulates itself after serving a ticket drawing request. Once acquiring an ID, a generator encodes the ID using Base62 and returns it.

Note that we can apply the auto-increment field of the SQL database to implement the counter so that we can maintain atomic transactions for ID pulling requests. The benefit of this approach is that we do not need to resolve ID conflicts, but the downside is that the global counter is our performance bottleneck and may suffer from single-point-of-failure. Besides, if we generate 64-bits integer IDs, the encoded strings will have more than 6 bytes.
<p align="center">
  <img src="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/SystemDesign/TinyURL/photos/IdGenerationServiceApproach2.jpg" width="800"/>
</p>

### Twitter Snowflake ID
To resolve the bottleneck of the second approach, we borrow the idea from Twitter Snowflake, a method for unique ID generation in a distributed system. This time, each ID generator maintains a local counter and generates 64-bits integer IDs in the format shown below.
1. The leading X bits represent timestamp, with the precision to milliseconds. To cover 10 years, we can configure X to 40 bits.
2. The middle Y bits stand for machine ID. To run a sufficient number of ID generators at our scale, we can configure Y to 5 bits.
3. The last Z bits represent the local counter. Once an ID generator produces an ID, it should increment the counter and must reset it when the counter overflows or there is an internal server error.
Like the previous approach, we need to encode the integer IDs using Base62.
<p align="center">
  <img src="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/SystemDesign/TinyURL/photos/IdGenerationServiceApproach3.jpg" width="800"/>
</p>

### Range Partition
The idea of Snowflake ID is range partition, meaning each ID generator only produces IDs within a predefined range, for example, timestamp or machine IDs. By extending this idea, we come up with the fourth approach. This time, the service coordinator partitions the value space of the total amount of numeric IDs into multiple ranges. Plus, the ID generators take turns to pull unused ranges from the coordinator. Also, each generator only consumes IDs within the pulled range and should pull another range once the old one runs out. Take our case as an example, we can partition 36.5B into 365K ranges, each of which contains 10M IDs.
<p align="center">
  <img src="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/SystemDesign/TinyURL/photos/IdGenerationServiceApproach4.jpg" width="800"/>
</p>
