# Redis Strings
`LIMIT`: `512 MB`

Redis strings store sequence of bytes, including text, serialized objects, and binary arrays.   
They are often used for caching, but they support additional functionality that lets you implement counters and perform bitwise operations, too.

Examples:

- Store and then retrieve a string in Redis:

```
> SET user:1 salvatore
OK
> GET user:1
"salvatore"
```

- Store a serialized JSON string and set it to expire in 100 seconds from now:

```
> SET ticket:27 "\"{'username': 'priya', 'ticket_id': 321}\"" EX 100
```

- Increment a counter:

```
> INCR views:page:2
(integer) 1
> INCRBY views:page:2 10
(integer) 11
```

## Basic Commands

### Getting and setiing Strings
- `SET` stores a string value.
- `SETNX` stores a string value only if the key doesn't already exists. Useful for implementing locks.
- `GET` retrieves a string value.
- `MGET` retrieves multiple string values in a single operation.

### Managing counters
- `INCRBY` atomically increments (and decrements when passing a negative number) counters stored at a given key.
- Another command exists for floating point counters: `INCRBYFLOAT`.

### BITWISE OPERATIONS
- To perform bitwise ops. on a string, see the [bitmaps data type](https://redis.io/docs/data-types/bitmaps) docs.

### [COMPLETE LIST OF STRING COMMANDS](https://redis.io/commands/?group=string)

#### PERFORMANCE
Most string ops. are O(1), which means they're highly efficient.
However be careful with the SUBSTR, GETRANGE, and SETRANGE commands, which can be O(n).
These random-access string commands may cause performance issues when dealing with large strings.

## Alternatives

If you're storing structured data as a serialized string, you may want to consider [Redis hashes](https://redis.io/docs/data-types/hashes) or [RedisJSON](https://redis.io/docs/stack/json).

## More Links:

- [Redis Strings Explained](https://www.youtube.com/watch?v=7CUt4yWeRQE)
- [Redis University's RU101](https://university.redis.com/courses/ru101/)














