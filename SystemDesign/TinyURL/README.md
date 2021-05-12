# Feature Requirements

### Functional Requirements
1. Given a URL, the service should create a shortened alias of it using numbers (0-9) and letters (a-z, A-Z).
2. When queried with a shortened alias, the service should redirect the user to the original URL.

### Non-Functional Requirements
1. The service must be highly available.
2. The service should respond in a timely manner.

  
# Scale Estimation

### Traffic Estimation
Assume we have 10M tiny URLs generated every day, and the ratio of read and write is 100 : 1. This implies:
+ Writes-per-second (WPS): 10M / 24 / 3600 = 115.7.. ~= 100
+ Reads-per-second (RPS): 100 * 100 = 10K

Besides, let's assume on average the peak QPS is 3 times higher than the regular QPS.


### Storage Estimation
Assume we plan to run the service by 10 years, and the size of each long-and-short URL pair is 200 bytes.
+ Total size: 10M * 365 * 10 * 200 = 10G * 730 = 7.3 TB

For reliability, we should double the capacity to store these URL pairs.


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

  
# High Level System Design
<p align="center">
  <img src="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/SystemDesign/TinyURL/photos/HighLevelSystemDesign.jpg"/>
</p>
