# Design NewsFeed
This problem may be asked in various ways such as designing Facebook newsfeed, designing Instagram, or designing Twitter.  
Here, I use Instagram as the example to illustrate my thinking steps.


## Feature Requirement

### Functional Requirement
1. Users should be able to upload photos.
2. Users should be able to access the newsfeed which consists of the top contents from all the people the user follows.

### Non-Functional Requirement
1. The maximum latency seen by users must be less than 0.5 second.
2. Maintain high availability.
3. Maintain high reliability, which means photos should never be lost.


## Capacity Estimation

### Traffic
Assume 1B daily active users with each user fetching his newsfeed on average 10 times a day. This implies 10B requests/day, 100K requests/second. Plus, let's assume a user posts photos every 10 days. Then this implies 100M new photos generated every day. 

### Storage
Assume the photo size is on average 1MB. Since we have 100M new photos generated every day, this implies the daily data generation pace would be 100TB/day. If we plan to host the service for 5 years, then storage consumption would be 100TB * 5 *365 = 182.5PB.


## High Level Design

### Push Model

#### Write Path
<p align="center">
  <img src="https://github.com/ZSShen/HackingTechInterview/blob/main/SystemDesign/NewsFeed/photos/PushModelWrite.jpg"/>
</p>

#### Read Path
<p align="center">
  <img src="https://github.com/ZSShen/HackingTechInterview/blob/main/SystemDesign/NewsFeed/photos/PushModelRead.jpg"/>
</p>


## Database Schema
<p align="center">
  <img src="https://github.com/ZSShen/HackingTechInterview/blob/main/SystemDesign/NewsFeed/photos/PushModelSchema.jpg"/>
</p>


## API Design

### POST /upload
| Parameters       | Data type | Example |
|------------------|-----------|---------|
| api_key [in]     | string    |         |
| user_id [in]     | int       |         |
| description [in] | string    |         |
| photo [in]       | blob      |         |

### GET /newsfeed
| Parameters              | Data type | Example |
|-------------------------|-----------|---------|
| api_key [in]            | string    |         |
| user_id [in]            | int       |         |
| last_timestamp [in]     | timestamp |         |
| page_size [in]          | int       |         |
| feed_array [out]        | [blob]    |         |


## Detailed Component Design

### NewsFeed Service
The main disadvantage of the **push model** is that if a user has many followers, it may take a lot of time to synchronize the new posts to the followers. To solve this celebrity issue, we can use the hybrid approach to offload the pressure of the newsfeed service. For a celebrity user, the system will not trigger the fan-out-on-write task, and instead, it simply writes the new posts to the post table. This way, the **`FeedItem`** store does not contain the feed items created by celebrity users. 

Once a user accesses the newsfeed feature, the `NewsFeed` service will check if this user has celebrity followers and will launch the fan-out-on-read task to collect post items created by those celebrities if necessary. Plus, it queries the `FeedItem` store to get the top-ranked posts created by ordinary users and then merge all these posts together.


### Push and Pull Hybrid Model
#### Read Path
<p align="center">
  <img src="https://github.com/ZSShen/HackingTechInterview/blob/main/SystemDesign/NewsFeed/photos/HybridMode.jpg"/>
</p>

## Scale-Out

### Database Sharding
We can shard `PostItem`, `FeedItem`, and `User` tables using UserId as the sharding key. Moreover, we should apply consistent hash to avoid unbalanced load distribution.

### Cache
For the database, we must turn on its caching mechanism. Plus, we should use a caching system like Memcached to serve the `Photo` storage. Furthermore, we deploy CDN to cache hot photos for fast access in different geolocations. 

### Fault Tolerance
For each service, such as `PostService` and `NewsFeedService`, we launch multiple servers and prepare load balancers in front of them to evenly distribute the workload.

For the database sub-system, we should avoid single-point-of-failure by implementing the master-slave architecture; the master handles write requests, while the slaves handle read requests. Besides, once the master is down, the zookeeper should organize the election process to promote a new master among the remaining slaves.

