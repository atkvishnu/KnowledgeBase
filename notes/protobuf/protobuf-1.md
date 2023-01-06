## What problems do Protocol Buffers Solve?

- Protocol buffers provide a serialization format for packets of typed (type-strict), structured data that are up to a few megabytes(MB) in size.   
- The format is suitable for both ephemeral(lasting for a very short time) network traffic, long-term data storage, it's used extensively in inter-server communications as well as for archival storage of data on disk..
- Protocol buffers can be extended with new information without invalidating existing data or requiring code to be updated.
- Protocol buffer messages and services are described by engineer-authored `.proto` files. 

The following shows an example `message`:
```go
message Person {
    optional string name = 1;
    optional int32 id = 2;
    optional string email = 3;
}
```

- The proto `compiler` is `invoked at build time` on .proto files to generate code in various programming languages to manipulate the corresponding protocol buffer. Each generated class contains simple accessors for each field and methods to serialize and parse the whole structure to and from raw bytes.    
The following shows you an example that uses those generated methods:
```go
Person john = Person.newBuilder()
    .setId(1234)
    .setName("John Doe")
    .setEmail("jdoe@example.com")
    .build();
output = new FileOutputStream(args[0]);
john.writeTo(output);
```

- Because protocol buffers are used extensively across all manner of services at Google and data within them may persist for some time, maintaining backwards compatibility is crucial. 
- Protocol buffers allow for the seamless support of changes, including the addition of new fields and the deletion of existing fields, to any protocol buffer without breaking existing services. 

---

## Benefits of using Protocol Buffers

Protobufs are ideal for any situation in which you `need to serialize structured, record-like, typed data in a language neutral, platform-neutral, extinsible manner`.   

- They are `most often used for defining communications protocols (together with gRPC)` and for `data storage`.

Advantages: 

- Compact data storage.
- Fast parsing.
- Availability in many programming languages.
- Optimized functionality through automatically-generated classes.


### Cross-language Compatibility

The same message can be read by code written in any supported programming language.   
You can have a Java program on one platform capture data from one software system, serialize it based in a `.proto` definition, and then extract specific values from that serialized data in a separate Python application running on another platform.








