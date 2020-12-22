# Design Pastebin
Pastebin is a service where users can store text contents such as plaintext or code snippets. Users upload a text snippet and can get an encoded URL to access it.


## Feature Requirement

### Functional Requirement
1. Users can upload their data and get a unique URL to access it.
2. Users can only upload text.

### Non-Functional Requirement
1. The service should be highly available.

### Extended Features
1. User can specify custom URLs.


## Capacity Estimation

### Traffic
Assume we have 1M text upload requests every day, and assume a 5:1 ratio between read and write.  
Hence, the WPS is 1M / 86400 = 12 requests/second, or approximately 10 requests/second.  
Plus, the RPS is 5M / 86400 = 58 requests/second, or approximately 60 requests/second.

### Storage
Let's assume the average size of a text file is 10KB. With the traffic rate mentioned above, the data generation pace per day is 10KB * 1M = 10GB/day. In 10 years, the total storage consumption will be 36.5TB.  

In 10 years, we will have 3.65B text files uploaded. If we use Base62 encoding to generate a unique URL for each text file, we should take 6 bytes, 62^6~=5.6B, to cover this amount of total uploaded files.


## API Design
### POST /paste_bin
| Parameters       | Data type | Example |
|------------------|-----------|---------|
| api_key [in]     | string    |         |
| user_id [in]     | int       |         |
| content [in]     | string    |         |
| url     [out]    | string    |         |

### GET /paste_bin
| Parameters              | Data type | Example |
|-------------------------|-----------|---------|
| api_key [in]            | string    |         |
| user_id [in]            | int       |         |
| url     [in]            | string    |         |
| content [out]           | string    |         |


## High Level Design

### Write Path
<p align="center">
  <img src="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/SystemDesign/Pastebin/photos/WritePath.jpg"/>
</p>

### Read Path
<p align="center">
  <img src="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/SystemDesign/Pastebin/photos/ReadPath.jpg"/>
</p>


## Database Schema
<p align="center">
  <img src="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/SystemDesign/Pastebin/photos/DatabaseSchema.jpg"/>
</p>


## Detailed Component Design

### Key Generation Service

#### Random Number Generator
This way, the service uses the user IP address, the current timestamp, and a random integer as the input to generate a SHA256 hash value. Based on the storage estimation discussed above, we pick the 6-characters long prefix of the hash value as the URL key. If there is any conflict, we need to rerun the key generation algorithm until the conflict is resolved. Besides, we store URL keys in a key database, which can be simply a hash table. 

**Pros**
1. Easy to implement and no cold start issue.

**Cons**
1. As there are more and more keys, the time needed to deduplicate may become longer.

### Unique Id Counter

This way, the service maintains a unique id counter which increases from the minimum integer to the maximum integer. For each unique integer, the service converts it to a Base62-encoded string, which then will be stored in a key database. Note that to avoid the cold start issue, the service may need to pre-populate a certain amount of keys before serving user requests.

**Pros**
1. No deduplication issue.

**Cons**
1. Need to pre-populate the key database.


## Scale-Out

### Database Sharding
We can shard `UserDB` using `UserId` as the sharding key and shard `PasteMetadataDB` using `ObjectId` as the sharding key. Moreover, we should apply consistent hash to avoid unbalanced load distribution.

### Cache
For the database, we must turn on its caching mechanism.

### Fault Tolerance
For each service, such as `ContentService`, we launch multiple servers and prepare load balancers in front of them to evenly distribute the workload.  

For the database sub-system, we should avoid single-point-of-failure by implementing the master-slave architecture; the master handles write requests, while the slaves handle read requests. Besides, once the master is down, the zookeeper should organize the election process to promote a new master among the remaining slaves.

