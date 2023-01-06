# Intro (`REDIS` - `RE`mote `DI`ctionary `S`erver)

- Redis is an in-memory `data structure store` used as a DB, cache, message broker, and streaming engine.

- Redis provides data structures such as `strings`, `hashes`, `lists`, `sets`, `sorted sets` with range queries, `bitmaps`, `hyperloglogs`, `geospatial indexes`, and `streams`.

- Redis has built-in `replication`, `Lua scripting`, `LRU eviction`, `transactions`, and different levels of `on-disk persistence`, and provides `high availabilty via. Redis Sentinel` and `automatic partitioning with Redis Clusters`.

- We can run **atomic operations** on these types, like `appending to a string`, `incrementing the value in a hash`, `pushing an element to a list`, `computing set intersection`, `union` and `difference`; or `getting the member with highest ranking in a sorted set`.

- Depending on your use case, Redis can persist your data either by periodically `dumping the dataset to disk` or by `appending each command to a disk-based log`. You can also disable persistence if you just need a feature-rich, networked, in-memory cache.

- Redis supports asynchronous replication, with fast non-blocking synchronization and auto-reconnection with partial resynchronization on net split.

Redis also includes: 

- Transactions
- Pub/Sub
- Lua Scripting
- Keys with a limited time-to-live.
- LRU eviction of keys
- Automatic failover.

- Redis has support for most programming languages.

- Redis is written in `ANSI C` and works on most POSIX systems like `Linux (recommended)`, *BSD, and Mac OS X, without external dependencies.



## How is Redis different from other key-value stores?

- Redis has a different evolution path in the key-value DBs where values can contain more complex data types, with atomic operations defined on those data types. Redis data types are closely related to fundamental data structures and are exposed to the programmer as such, without additional abstraction layers.

- Redis is an in-memory but persistent on disk database, so it represents a different trade off where very high write and read speed is achieved with the limitation of data sets that can't be larger than memory. Another advantage of in-memory databases is that the memory representation of complex data structures is much simpler to manipulate compared to the same data structures on disk, so Redis can do a lot with little internal complexity. At the same time the two on-disk storage formats (RDB and AOF) don't need to be suitable for random access, so they are compact and always generated in an append-only fashion (Even the AOF log rotation is an append-only operation, since the new version is generated from the copy of data in memory). However this design also involves different challenges compared to traditional on-disk stores. Being the main data representation on memory, Redis operations must be carefully handled to make sure there is always an updated version of the data set on disk.



## What's the Redis memory footprint?

Examples (all obtained using 64-bit instances):

- An empty instance uses ~ 3MB of memory.
- 1 Million small Keys -> String Value pairs use ~ 85MB of memory.
- 1 Million Keys -> Hash value, representing an object with 5 fields, use ~ 160 MB of memory.

Testing your use case is trivial. 
- Use the `redis-benchmark` utility to generate random data sets then check the space used with the `INFO memory` command.

- 64-bit systems will use considerably more memory than 32-bit systems to store the same keys, especially if the keys and values are small. This is because pointers take 8 bytes in 64-bit systems. But of course the advantage is that you can have a lot of memory in 64-bit systems, so in order to run large Redis servers a 64-bit system is more or less required. The alternative is sharding.

## Can we use Redis with a disk-based database?

- Yes, a common design pattern involves taking very write-heavy small data in Redis (and data you need the Redis data structures to model your problem in an efficient way), and big blobs of data into an SQL or eventually consistent on-disk database. Similarly sometimes Redis is used in order to take in memory another copy of a subset of the same data stored in the on-disk database. This may look similar to caching, but actually is a more advanced model since normally the Redis dataset is updated together with the on-disk DB dataset, and not refreshed on cache misses.

## How can I reduce Redis' overall memory usage?

- If you can, use Redis 32 bit instances. Also make good use of small hashes, lists, sorted sets, and sets of integers, since Redis is able to represent those data types in the special case of a few elements in a much more compact way. There is more info in the [Memory Optimization page](https://redis.io/topics/memory-optimization/).


## How can Redis use multiple CPUs or cores?

- It's not very frequent that CPU becomes your bottleneck with Redis, as usually Redis is either memory or network bound. For instance, when using pipelining a Redis instance running on an average Linux system can deliver 1 million requests per second, so if your application mainly uses O(N) or O(log(N)) commands, it is hardly going to use too much CPU.

- However, to maximize CPU usage you can start multiple instances of Redis in the same box and treat them as different servers. At some point a single box may not be enough anyway, so if you want to use multiple CPUs you can start thinking of some way to shard earlier.

- You can find more information about using multiple Redis instances in the [Partitioning page](https://redis.io/docs/manual/scaling/).

- As of version 4.0, Redis has started implementing threaded actions. For now this is limited to deleting objects in the background and blocking commands implemented via Redis modules. For subsequent releases, the plan is to make Redis more and more threaded.


## What is the maximum number of keys a single Redis instance can hold? What is the maximum number of elements in a Hash, List, Set, and Sorted Set?

- Redis can handle up to 2^32 keys, and was tested in practice to handle at least 250 million keys per instance.

- Every hash, list, set, and sorted set, can hold 2^32 elements.

- In other words your limit is likely the available memory in your system.


## Why does my replica have a different number of keys its master instance?

If you use keys with limited time to live (Redis expires) this is normal behavior. This is what happens:

- The primary generates an RDB file on the first synchronization with the replica.
- The RDB file will not include keys already expired in the primary but which are still in memory.
- These keys are still in the memory of the Redis primary, even if logically expired. They'll be considered non-existent, and their memory will be reclaimed later, either incrementally or explicitly on access. While these keys are not logically part of the dataset, they are accounted for in the INFO output and in the DBSIZE command.
- When the replica reads the RDB file generated by the primary, this set of keys will not be loaded.

Because of this, it's common for users with many expired keys to see fewer keys in the replicas. However, logically, the primary and replica will have the same content.


