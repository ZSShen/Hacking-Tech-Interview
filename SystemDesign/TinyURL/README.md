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

As shown in the picture, the first component is WebServer, which serves as a gateway or proxy to distribute requests to internal services including ID Generation Service and URL Service. Second, ID Generation Service is responsible for generating a short ID for a long URL. Depending on different implementation details, the service may need to integrate another data store to ensure that each short ID is unique. Third, we have URL Service that inserts the long URL and short ID mappings into URL Database and fetches the long URLs using the specified short IDs.

For the write path, a POST request first goes through WebServer, which then requests ID Generation Service using the long URL to create a unique short ID. Once obtaining the short ID, WebServer then requests URL Service to store the long URL and short ID mapping.

For the read path, a GET request first goes through WebServer, which then requests URL Service to fetch the long URL using the short ID. Once acquiring the short ID, WebServer responds to the client with the long URL specified in the location header and the status code either 301 or 302.

<p align="center">
  <img src="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/SystemDesign/TinyURL/photos/HighLevelSystemDesign.jpg"/>
</p>
