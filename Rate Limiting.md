TO READ - https://engineering.ramp.com/rate-limiting-with-redis

Rate limiting is a technique in computer systems to control the rate at which requests are sent or processed in order to maintain system stability and security.

In web apps, rate limiting restricts the number of requests that a client can make to a server within a given time period to prevent abuse and ensure fair usage of resources among multiple clients.

Rate limiting can keep cyber threats like DDoS attacks, brute force attacks, credential stuffing, inventory hoarding attacks, and data scraping at bay and maintain the security, reliability and stability of the system. It is also used to protect your servers from unwanted bursts.

Rate limiting can be handled both on the server and client-side. On the server-side, rate limiting can be implemented with

1. Proxy servers like Nginx
2. An in-memory high-performance database like Redis
3. Third-party services like AWS API Gateway,
4. Using your data structure and algorithms in your code.

It is commonly used in various apps, including web APIs, web servers and network infrastructure.

#### The difficulties of rate limiting

Rate limiting is one of those classic computer science problems that people like to ask candidates in interviews. What makes it a good interview question—the nuanced edge cases and numerous design decisions—makes for tricky implementations in the real world.

Imagine, for example, a rate limit of 2 requests per second. This limit is not equal to 120 requests every minute, despite the latter averaging out to the former. This is because the latter supports burst uses (e.g. a user can exhaust all 120 requests in the first second, and then wait 59 seconds with no successful requests).


---

## Types of Rate limiting

1. IP-Based
	This restricts access based on the source IP address of the request. It can help prevent attacks from a small number of IP addresses, but it can be less effective against distributed attacks.

2. User-Based
	It restricts access based on the user account making the request. It can help prevent credential stuffing attacks, but it requires identifying unique users across different sessions, which can be challenging.

3. Application-Based
	It restricts access based on the type of apps making the request. It can help prevent inventory hoarding and data scraping attacks, but it may not be effective against attacks coming from legitimate apps.

4. Token Bucket
	It's a popular approach that regulates the flow of requests using a token number. Each request consumes a token from the bucket, and once the bucket is empty, no more requests are allowed until the bucket is refilled.

---

## How does rate limiting work?

Rate limiting is something like a bouncer at a nightclub. A bouncer assess the flow of people into the club and stops entry if things are becoming overcrowded and unsafe. Similarly, rate limiting controls the number of requests to an application to prevent it from becoming overwhelmed or crashing. Just as the bouncer may limit entry to a certain number of people per hour, rate limiting can limit requests to a certain number per second or minute.

Rate limiting normally is based on tracking IP addresses and measures the time between each request. When a user makes a request, the system tracks it and compares the number of requests made to a predefined threshold. If the number of requests exceeds the threshold, rate limiting kicks in and the system will not fulfill the user’s requests for a certain amount of time.

---
---

## Algorithms used for rate limiting

**Fixed-window rate limiting:** This is a straightforward algorithm that counts the number of requests received within a fixed time window, such as one minute. Once the maximum number of requests is reached, additional requests are rejected until the next window begins. This algorithm is easy to implement and effective against DDoS attacks but may limit legitimate users.

In this algorithm, we use fixed window intervals to count requests. For 100 req/min, we use 1 minute/60 second interval windows. Each incoming request increments the counter for the currently active window (windows are defined by the floor of the current timestamp), so with a 1 minute/60 second window, if the current time is 10:00:27, the current window would be 10:00:00 and if time is 10:01:27, the window would be 10:01:00.

For each request a user makes,

1. Check if the user has exceeded the limit in the current window.
2. If the user has exceeded the limit, the request is dropped
3. Otherwise, we increment the counter

```
// RateLimitUsingFixedWindow .
func RateLimitUsingFixedWindow(userID string, intervalInSeconds int64, maximumRequests int64) bool {
	// userID can be apikey, location, ip
	currentWindow := strconv.FormatInt(time.Now().Unix()/intervalInSeconds, 10)
	key := userID + ":" + currentWindow // user userID + current time window
	// get current window count
	value, _ := redisClient.Get(ctx, key).Result()
	requestCount, _ := strconv.ParseInt(value, 10, 64)
	if requestCount >= maximumRequests {
		// drop request
		return false
	}

	// increment request count by 1
	redisClient.Incr(ctx, key) // if the key is not available, value is initialised to 0 and incremented to 1

	// handle request
	return true
	// delete all expired keys at regular intervals
}
```

At regular intervals, say every 10 min or every hour, delete all the expired window keys (instead of setting the current window to expire at the start next window using EXPIRE command in Redis, which is another command/load on Redis for every request).

## Pros

- Easy to implement.

## Cons

- A burst of requests at the end of the window causes server handling more requests than the limit since this algorithm will allow requests for both current and next window requests within a short time. For example, for 100 req/min, if the user makes 100 requests at 55 to 60 seconds window and then 100 requests from 0 to 5 seconds in the next window, this algorithm handles all the requests. Thus, ends up handling 200 requests in 10 seconds for this user, which is above the limit of 100 req/min

---

### Sliding Logs:
In this algorithm, we log every request a user makes into a sorted list(sorted with time).

For each request a user makes,

1. Check if the user has exceeded the limit in the current window by getting the count of all the logs in the last window in the sorted set. If current time is 10:00:27 and rate is 100 req/min, get logs from previous window(10:00:27–60= 09:59:28) to current time(10:00:27).
2. If the user has exceeded the limit, the request is dropped.
3. Otherwise, we add the unique request ID (you can get from the request or you can generate a unique hash with userID and time) to the sorted sets(sorted by time).

```
// RateLimitUsingSlidingLogs .
func RateLimitUsingSlidingLogs(userID string, uniqueRequestID string, intervalInSeconds int64, maximumRequests int64) bool {
	// userID can be apikey, location, ip
	currentTime := strconv.FormatInt(time.Now().Unix(), 10)
	lastWindowTime := strconv.FormatInt(time.Now().Unix()-intervalInSeconds, 10)
	// get current window count
	requestCount := redisClient.ZCount(ctx, userID, lastWindowTime, currentTime).Val()
	if requestCount >= maximumRequests {
		// drop request
		return false
	}

	// add request id to last window
	redisClient.ZAdd(ctx, userID, &redis.Z{Score: float64(time.Now().Unix()), Member: uniqueRequestID}) // add unique request id to userID set with score as current time

	// handle request
	return true
	// remove all expired request ids at regular intervals using using ZRemRangeByScore from -inf to last window time
}
```

At regular intervals, say every 10 min or every hour, delete all the expired request IDs from sorted sets using ZRemRangeByScore from -inf to last window time.

## Pros

- Overcomes cons of the fixed window by not imposing a fixed window limit and thus unaffected by bursts of requests at the end of the window

## Cons

- It is not memory-efficient since we store a new entry for every request made.
- It is very expensive because we count the user’s last window requests in each request, which doesn’t scale well when large bursts of attacks happen.

---

**Sliding-window rate limiting:** This algorithm tracks the number of requests received in the recent past using a sliding window that moves over time. This algorithm is more flexible than fixed-window rate limiting and can adjust to spikes in traffic, making it a better choice for applications with varying usage patterns. However, it may not be as effective against sustained attacks.

In this algorithm, we combine both the fixed window and the sliding log algorithm. We maintain a counter for each fixed window and we account for the weighted counter value of previous window request count along with current window request count.

For each request a user makes,

1. Check if the user has not exceeded the limit in the current window.
2. If the user has exceeded, the request is dropped
3. Otherwise, we calculate the weighted count of the previous window, for example, if the current window time has been elapsed by 30%, then we weight the previous window’s count by 70%
4. Check if the previous window weighted count and current window count has exceeded the limit.
5. If the user has exceeded, the request is dropped.
6. Otherwise, we increment the counter by 1 in the current window and handle the incoming request.

```
  
// RateLimitUsingSlidingWindow .
func RateLimitUsingSlidingWindow(userID string, uniqueRequestID string, intervalInSeconds int64, maximumRequests int64) bool {
	// userID can be apikey, location, ip
	now := time.Now().Unix()

	currentWindow := strconv.FormatInt(now/intervalInSeconds, 10)
	key := userID + ":" + currentWindow // user userID + current time window
	// get current window count
	value, _ := redisClient.Get(ctx, key).Result()
	requestCountCurrentWindow, _ := strconv.ParseInt(value, 10, 64)
	if requestCountCurrentWindow >= maximumRequests {
		// drop request
		return false
	}

	lastWindow := strconv.FormatInt(((now - intervalInSeconds) / intervalInSeconds), 10)
	key = userID + ":" + lastWindow // user userID + last time window
	// get last window count
	value, _ = redisClient.Get(ctx, key).Result()
	requestCountlastWindow, _ := strconv.ParseInt(value, 10, 64)

	elapsedTimePercentage := float64(now%intervalInSeconds) / float64(intervalInSeconds)

	// last window weighted count + current window count
	if (float64(requestCountlastWindow)*(1-elapsedTimePercentage))+float64(requestCountCurrentWindow) >= float64(maximumRequests) {
		// drop request
		return false
	}

	// increment request count by 1 in current window
	redisClient.Incr(ctx, userID+":"+currentWindow)

	// handle request
	return true
}
```

At regular intervals, say every 10 min or every hour, delete all the expired window keys.

## Pros

- Overcomes the cons of the fixed window by not imposing a fixed window limit and thus unaffected by a burst of requests at the end of the window.
- Overcomes the cons of sliding logs by not storing all the requests and avoiding counting for every request and thus memory and performance efficient.
- Overcomes the cons of leaky bucket starvation problem by not slowing requests, not traffic shaping.

## Cons

- Not a con, but you need to delete expired window keys, an extra command/load on Redis, which you can overcome in the next algorithm.

---

**Token bucket rate limiting:** This maintains a token bucket that is refilled at a fixed rate. Each request consumes a token, and additional requests are denied once the bucket is empty. Token bucket rate limiting is suitable for handling bursts of traffic, as it can allow a certain number of requests to be processed simultaneously. However, it may not be as effective against sustained traffic.

In this algorithm, we maintain a counter which shows how many requests a user has left and time when the counter was reset.

For each request a user makes,

1. Check if window time has been elapsed since the last time counter was reset. For rate 100 req/min, current time 10:00:27, last reset time 9:59:00 is not elapsed and 9:59:25(10:00:27–9:59:25 > 60 sec) is elapsed.
2. If window time is not elapsed, check if the user has sufficient requests left to handle the incoming request.
3. If the user has none left, the request is dropped.
4. Otherwise, we decrement the counter by 1 and handle the incoming request.
5. If the window time has been elapsed, i.e., the difference between last time counter was reset and the current time is greater than the allowed window(60s), we reset the number of requests allowed to allowed limit(100)

```
// RateLimitUsingTokenBucket .
func RateLimitUsingTokenBucket(userID string, intervalInSeconds int64, maximumRequests int64) bool {
	// userID can be apikey, location, ip
	value, _ := redisClient.Get(ctx, userID+"_last_reset_time").Result()
	lastResetTime, _ := strconv.ParseInt(value, 10, 64)
	// if the key is not available, i.e., this is the first request, lastResetTime will be set to 0 and counter be set to max requests allowed
	// check if time window since last counter reset has elapsed
	if time.Now().Unix()-lastResetTime >= intervalInSeconds {
		// if elapsed, reset the counter
		redisClient.Set(ctx, userID+"_counter", strconv.FormatInt(maximumRequests, 10), 0)
	} else {
		value, _ := redisClient.Get(ctx, userID+"_counter").Result()
		requestLeft, _ := strconv.ParseInt(value, 10, 64)
		if requestLeft <= 0 { // request left is 0 or < 0
			// drop request
			return false
		}
	}

	// decrement request count by 1
	redisClient.Decr(ctx, userID+"_counter")

	// handle request
	return true
}
```

In this algorithm, there is no need for background code to check and delete expired keys.

## Pros

- Overcomes all the above algorithms cons, no fixed window limit, memory and performance efficient, no traffic shaping.
- No need for background code to check and delete expired keys.

---

**Leaky bucket rate limiting:** Similar to token bucket rate limiting but puts requests into a “bucket” that gradually empties over time, allowing more requests to be processed. This algorithm is effective against bursts of traffic and helps to prevent overload, but it may not be as effective against sustained attacks.

In this algorithm, we use limited sized queue and process requests at a constant rate from queue in First-In-First-Out(FIFO) manner.

For each request a user makes,

1. Check if the queue limit is exceeded.
2. If the queue limit has exceeded, the request is dropped.
3. Otherwise, we add requests to queue end and handle the incoming request.

```
// RateLimitUsingLeakyBucket .
func RateLimitUsingLeakyBucket(userID string, uniqueRequestID string, intervalInSeconds int64, maximumRequests int64) bool {
	// userID can be apikey, location, ip
	requestCount := redisClient.LLen(ctx, userID).Val()
	if requestCount >= maximumRequests {
		// drop request
		return false
	}

	// add request id to the end of queue
	redisClient.RPush(ctx, userID, uniqueRequestID)

	// handle request
	return true
}
```

Requests are processed at a constant rate from the queue in a FIFO manner(removed from the start of the queue and handled) from a background process. (you can use LPOP command in Redis at a constant rate, for example for 60 req/min, you can remove 1 element per second and handle the removed request)

## Pros

- Overcomes the cons of the fixed window by not imposing a fixed window limit and thus unaffected by a burst of requests at the end of the window.
- Overcomes the cons of sliding logs by not storing all the requests(only the requests limited to queue size) and thus memory efficient.

## Cons

- Bursts of requests can fill up the queue with old requests and most recent requests are slowed from being processed and thus gives no guarantee that requests are processed in a fixed amount of time.
- This algorithm causes traffic shaping(handling requests at a constant rate, which prevents server overload, a plus point), which slows user’s requests and thus affecting your application.

---


Choosing the right rate-limiting algorithm depends on several factors, including the application’s traffic patterns and the desired level of protection against malicious activity. Organizations must strike a balance between protecting their systems and providing a good user experience.

---
---

## Rate limiting real-life use cases

- Google Maps API
- Github API
- Twitter API
- Cloudflare

##### 1. Limiting requests to third-party APIs globally

Ramp uses many different third-party APIs throughout the app, everything from Finicity and Teller for bank linking to Zendesk and Salesforce for support and sales. Each of these APIs comes with its own rate limiting requirements: some have a daily quota, others have a per-second (“peak”) quota for spikes, and still others have a quota per user or business for various time periods.

##### 2. Rate limiting Celery tasks globally

Periodically, Ramp takes action across our entire user set (e.g., sending all businesses a summary of their spend on Ramp in the last week). When we do this, we need to avoid overburdening our systems and negatively impacting other tasks. Each product use case may have different configurations, and our rate limiting approach must support them.

##### 3. Inbound traffic rate limiting for our application API

As we scale, we expect that there will be either accidental or intentional misuse of our API. To combat this, we currently have Cloudflare [rate limit](https://www.cloudflare.com/rate-limiting/) API usage by route, user IP, and other attributes. However, since IPs can easily be changed by an attacker, it's more effective to rate limit by app-level identities, such as an authenticated user’s ID. This level of granularity can be achieved only if we handle it as an app-level rate limit, since Cloudflare cannot authenticate our users.


#### What we did before

[Celery](https://github.com/celery/celery), a popular task queue we use at Ramp, provides basic rate limiting functionality for tasks via decorators. By placing actions we wish to rate limit inside tasks and rate limiting the tasks themselves, we can indirectly rate limit the action.

This approach is limited. For one, not all actions we want to rate limit can be placed in tasks, and even for those that could we needed to write supplemental code to handle 429 responses from third parties. More broadly, Celery rate limiting is per-worker and not global. It's possible to hack around this constraint, but that requires a task author to know…

- What queue the task is running on
- How many Celery workers are running for a given queue
- Worker autoscaling behavior

…and then set the per-worker rate limit to be `(desired global rate limit)/(max # of queue workers)`, which still might rate limit too aggressively. If any of these variables changes, the rate limit must be changed as well. Additionally, in certain Celery queue configurations (e.g., with [pre-fetching](https://docs.celeryq.dev/en/stable/userguide/optimizing.html#prefetch-limits) turned on), rate-limited tasks could eventually block a worker from taking on more tasks, grinding queues to a halt.

#### Goals and requirements

We set out to build a global rate limiter that could be adapted to fit these use cases. We had two initial goals:

1. Create a general rate limiting framework in which we could test various rate limiting algorithms.
2. Select an initial rate limiting algorithm that works well for most use cases.

Rate limiting is, luckily, a common (and solved) problem, so there are a lot of existing approaches that other companies have implemented. For example, [Cloudflare's implementation](https://blog.cloudflare.com/counting-things-a-lot-of-different-things/) modifies a sliding time window to approximate rate limits while [GitHub's approach](https://github.blog/2021-04-05-how-we-scaled-github-api-sharded-replicated-rate-limiter-redis/) uses a fixed-window approach.

Ultimately we realized that their approaches were tailored to their problems and weren't the best fit for us, so we decided to do more research on other algorithms that might fit us.


---

## Redis Rate Limiting Best Practices

Building a rate limiter with Redis is easy because of two commands [INCR](https://redis.io/commands/incr) and [EXPIRE](https://redis.io/commands/expire).

The basic concept is that you want to limit requests to a particular service in a given time period. Let’s say we have a service that has users identified by an API key. This service states that it is limited to 20 requests in any given minute.

To achieve this we want to create a Redis key for every minute per API key. To make sure we don’t fill up our entire database with junk, expire that key after one minute as well. Visualize it like this:

_User API Key = zA21X31, Green represents unlimited and red represents limited._

  

|   |   |   |   |   |   |
|---|---|---|---|---|---|
|Redis Key|zA21X31:0|zA21X31:1|zA21X31:2|zA21X31:3|zA21X31:4|
|Value|3|8|20|>2|20|
|Expires at|Latest 12:02|Latest 12:03|Latest 12:04|Latest 12:05|Latest 12:06|
|Time|12:00|12:01|12:02|12:03|12:04|

The key is derived from the User API key concatenated with the minute number by a colon. Since we’re always expiring the keys, we only need to keep track of the minute—when the hour rolls around from 59 to 00 we can be certain that another 59 don’t exist (it would have expired 58 minutes prior).

With pseudocode, let’s see how this would work.

|   |   |
|---|---|
|1|>[GET](https://redis.io/commands/get) [user-api-key]:[current minute number]|
|2|If the result from line 1 is less than 20 (or unset) go to 4 otherwise line 3|
|3|Show error message and end connection. Exit.|
|4|>[MULTI](https://redis.io/commands/multi)OK > INCR [user-api-key]:[current minute number] QUEUED > EXPIRE [user-api-key]:[current minute number] 59 QUEUED >[EXEC](https://redis.io/commands/exec)OK|
|5|Do service stuff|

Two key points to understand from this routine:

1. INCR on a non-existent key will always be 1. So, the first call of the minute will be result the value of 1
2. EXPIRE is inside a MULTI transaction along with the INCR, which means form a single atomic operation.

The worse-case failure situation is if, for some very strange and unlikely reason, the Redis server dies between the INCR and the EXPIRE. When restoring either from an AOF or in-memory replication, the INCR will not be restored since the transaction was not complete.

With this pattern, it’s possible that anyone one user will have two limiting keys, one that is being currently used and the one that will expire during the same minute window, but it is otherwise very efficient.












