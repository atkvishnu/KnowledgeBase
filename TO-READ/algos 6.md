𝟱 𝗮𝗹𝗴𝗼𝗿𝗶𝘁𝗵𝗺𝘀 𝘁𝗼 𝗸𝗻𝗼𝘄 𝗯𝗲𝗳𝗼𝗿𝗲 𝘆𝗼𝘂𝗿 𝗻𝗲𝘅𝘁 𝗦𝘆𝘀𝘁𝗲𝗺 𝗱𝗲𝘀𝗶𝗴𝗻 𝗶𝗻𝘁𝗲𝗿𝘃𝗶𝗲𝘄.  
  
𝟭) 𝗖𝗔𝗣/𝗣𝗔𝗖𝗘𝗟𝗖 𝗧𝗵𝗲𝗼𝗿𝗲𝗺𝘀  
With the help of these two theorems, distributed systems can choose a good balance between Consistency, Availability, Partition Tolerance, and Latency.  
   
Details: [https://lnkd.in/dTFksWj9](https://lnkd.in/dTFksWj9)  
  
  
𝟮) 𝗠𝗲𝗿𝗸𝗹𝗲 𝗧𝗿𝗲𝗲  
Identify data inconsistencies between servers.  
   
Distributed systems store multiple copies of data on different servers for high availability and better reliability. Any replica server can contain a lot of data. Merkle Trees are used to identify inconsistencies in data between replicas. Naively splitting up the entire data range to calculate checksums for comparison is not very feasible; there is simply too much data to be transferred. Instead, we can use the Merkle tree to compare replicas of a range.  
   
Details: [https://lnkd.in/gZpt67uU](https://lnkd.in/gZpt67uU)   
  
  
𝟯) 𝗕𝗹𝗼𝗼𝗺 𝗙𝗶𝗹𝘁𝗲𝗿  
Bloom filters are used to quickly find if an element might be present in a set.  
   
Details: [https://bit.ly/3TbSAsR](https://bit.ly/3TbSAsR)  
  
  
𝟰) 𝗖𝗼𝗻𝘀𝗶𝘀𝘁𝗲𝗻𝘁 𝗛𝗮𝘀𝗵𝗶𝗻𝗴  
Distributed systems use Consistent Hashing to distribute data across servers.  
  
Consistent Hashing helps with two things:  
1. It maps data to physical servers. Whenever the system wants to read or write data, Consistent Hashing tells us which server holds the data.  
2. It ensures that only a small set of keys move when servers are added or removed.  
   
Details: [https://lnkd.in/dJQKjN6i](https://lnkd.in/dJQKjN6i)  
  
  
𝟱) 𝗚𝗼𝘀𝘀𝗶𝗽 𝗣𝗿𝗼𝘁𝗼𝗰𝗼𝗹  
Used for efficiently sharing state information between servers.   
  
Each server keeps track of state information about other servers in the cluster and gossips (i.e., shares) this information with one random server every second. This way, eventually, each server gets to know about the state of every other node in the cluster.  
   
Details: [https://bit.ly/3D2w14j](https://bit.ly/3D2w14j)  
  
   
6) 𝗛𝗲𝗮𝗿𝘁𝗯𝗲𝗮𝘁  
Used for broadcasting the health status of a server.  
  
Each server periodically sends a heartbeat message to a central monitoring server or other servers in the system to show that it is still alive and functioning.  
  
Details: [https://bit.ly/3eFnT04](https://bit.ly/3eFnT04)