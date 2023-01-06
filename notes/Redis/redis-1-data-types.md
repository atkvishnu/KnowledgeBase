# Redis data types

Redis is a data structure server.   
At it's core, Redis provides a collection of native data types that help you solve a wide variety of problems, from `caching` to `queuing` to `event processing`. 

# Core

## Strings
`Redis strings` are the most basic Redis data type, representing a sequence of bytes.

## Lists
`Redis lists` are lists of strings by insertion order.

## Sets
`Redis sets` are unordered collections of unique strings that act like the sets from youe favourite programming languages (ex. JAva HashSets, Python sets, and so on).
With a Redis set, you can add, remove, and test for existence O(1) time (in other words, regardless of the number of set elements).

## Hashes
`Redis hashes` are record types modeled as collections of field-value pairs.
As such, Redis hashes resemble `Python dictionaries`, `Java HashMaps` and `Ruby hashes`.

## Sorted sets
`Redis sorted sets` are collections of unique strings that maintain order by each string's associated score.

## Streams
A `Redis stream` is a data structure that acts like an append-only log. Streams help record events in the order they occur and then syndicate them for processing.

## Geospatial indexes
`Redis geospatial indexes` are useful for finding locations within a given geographic radius or bounding box.

## Bitmaps
`Redis bitmaps` let you perform bitwise ops on strings.

## Bitfields
`Redis bitfields` efficiently encode multiply counters in a string value.
- Bitfields provide atomic get, set, and increment operations and support different overflow policies.

## HyperLogLog
The `Redis HyperLogLog` data structures provide probabilistic estimates of the cardinality (i.e., number of elements) of large sets.

## Extensions
To extend the features provided by the included data types, use one of these options:

- Write your own custom server-side functions in Lua.
- Write your own Redis module using the modules API or check out the community-supported modules.
- Use JSON, querying, ***`time series`***, and other capabilities provided by `Redis Stack`.
