
---

1. What is the main purpose of an operating system? Discuss different types? 

> An `operating system` (OS) is system software that `manages computer hardware`, `software resources`, and `provides common services for computer programs`. So it manages the computer’s memory, processes, devices, files, and security aspects of the system. It also allows us to communicate with the computer without knowing how to speak the computer’s language. Without an operating system, a computer is not useful.

Types of operating system:

* Batch OS
* Distributed OS
* Multitasking OS
* Network OS
* Real-Time OS
* Mobile OS


* Batch OS - This type of operating system does not interact with the computer directly. There is an operator which takes similar jobs having the same requirement and group them into batches. It is the responsibility of the operator to sort jobs with similar needs. 

![batch-os](https://media.geeksforgeeks.org/wp-content/uploads/BatchOS.jpeg)

Advantages of Batch Operating System: 
- It is very difficult to guess or know the time required for any job to complete. Processors of the batch systems know how long the job would be when it is in queue
-Multiple users can share the batch systems
-The idle time for the batch system is very less
-It is easy to manage large work repeatedly in batch systems

Disadvantages of Batch Operating System:  
- The computer operators should be well known with batch systems
- Batch systems are hard to debug
- It is sometimes costly
- The other jobs will have to wait for an unknown time if any job fails

Examples of Batch based Operating System: Payroll System, Bank Statements, etc. 


* Time-Sharing OS - Each task is given some time to execute so that all the tasks work smoothly. Each user gets the time of CPU as they use a single system. These systems are also known as Multitasking Systems. The task can be from a single user or different users also. The time that each task gets to execute is called quantum. After this time interval is over OS switches over to the next task. 

![](https://media.geeksforgeeks.org/wp-content/uploads/Time-Share.jpeg)

Advantages of Time-Sharing OS:  

- Each task gets an equal opportunity
- Fewer chances of duplication of software
- CPU idle time can be reduced

Disadvantages of Time-Sharing OS:  

- Reliability problem
- One must have to take care of the security and integrity of user programs and data
- Data communication problem

Examples of Time-Sharing OSs are: Multics, Unix, etc. 

* Distributed Operating System - These types of the operating system is a recent advancement in the world of computer technology and are being widely accepted all over the world and, that too, with a great pace. Various autonomous interconnected computers communicate with each other using a shared communication network. Independent systems possess their own memory unit and CPU. These are referred to as loosely coupled systems or distributed systems. These system’s processors differ in size and function. The major benefit of working with these types of the operating system is that it is always possible that one user can access the files or software which are not actually present on his system but some other system connected within this network i.e., remote access is enabled within the devices connected in that network. 

![](https://media.geeksforgeeks.org/wp-content/uploads/Distributed.jpeg)

Advantages of Distributed Operating System:  

- Failure of one will not affect the other network communication, as all systems are independent from each other
- Electronic mail increases the data exchange speed
- Since resources are being shared, computation is highly fast and durable
- Load on host computer reduces
- These systems are easily scalable as many systems can be easily added to the network
- Delay in data processing reduces

Disadvantages of Distributed Operating System:  

- Failure of the main network will stop the entire communication
- To establish distributed systems the language which is used are not well defined yet
- These types of systems are not readily available as they are very expensive. Not only that the underlying software is highly complex and not understood well yet

Examples of Distributed Operating System are- LOCUS, etc. 

* Network Operating System - These systems run on a server and provide the capability to manage data, users, groups, security, applications, and other networking functions. These types of operating systems allow shared access of files, printers, security, applications, and other networking functions over a small private network. One more important aspect of Network Operating Systems is that all the users are well aware of the underlying configuration, of all other users within the network, their individual connections, etc. and that’s why these computers are popularly known as tightly coupled systems. 

![](https://media.geeksforgeeks.org/wp-content/uploads/Network-OS.jpeg)

Advantages of Network Operating System:  

- Highly stable centralized servers
- Security concerns are handled through servers
- New technologies and hardware up-gradation are easily integrated into the system
- Server access is possible remotely from different locations and types of systems

Disadvantages of Network Operating System:  

- Servers are costly
- User has to depend on a central location for most operations
- Maintenance and updates are required regularly

Examples of Network Operating System are: Microsoft Windows Server 2003, Microsoft Windows Server 2008, UNIX, Linux, Mac OS X, Novell NetWare, and BSD, etc. 

* Real-Time Operating System – These types of OSs serve real-time systems. The time interval required to process and respond to inputs is very small. This time interval is called response time. 

Real-time systems are used when there are time requirements that are very strict like missile systems, air traffic control systems, robots, etc. 

Two types of Real-Time Operating System which are as follows: 

- Hard Real-Time Systems: 
These OSs are meant for applications where time constraints are very strict and even the shortest possible delay is not acceptable. These systems are built for saving life like automatic parachutes or airbags which are required to be readily available in case of any accident. Virtual memory is rarely found in these systems.

- Soft Real-Time Systems: 
These OSs are for applications where for time-constraint is less strict.

![](https://media.geeksforgeeks.org/wp-content/uploads/RTOS.jpeg)

Advantages of RTOS:  

- Maximum Consumption: Maximum utilization of devices and system, thus more output from all the resources
- Task Shifting: The time assigned for shifting tasks in these systems are very less. For example, in older systems, it takes about 10 microseconds in shifting one task to another, and in the latest systems, it takes 3 microseconds.
- Focus on Application: Focus on running applications and less importance to applications which are in the queue.
- Real-time operating system in the embedded system: Since the size of programs are small, RTOS can also be used in embedded systems like in transport and others.
- Error Free: These types of systems are error-free.
- Memory Allocation: Memory allocation is best managed in these types of systems.

Disadvantages of RTOS:  

- Limited Tasks: Very few tasks run at the same time and their concentration is very less on few applications to avoid errors.
- Use heavy system resources: Sometimes the system resources are not so good and they are expensive as well.
- Complex Algorithms: The algorithms are very complex and difficult for the designer to write on.
Device driver and interrupt signals: It needs specific device drivers and interrupts signals to respond earliest to interrupts.
- Thread Priority: It is not good to set thread priority as these systems are very less prone to switching tasks.

Examples of Real-Time Operating Systems are: Scientific experiments, medical imaging systems, industrial control systems, weapon systems, robots, air traffic control systems, etc.

---

2. What is a socket, kernel and monolithic kernel ? 

- `Socket`: A socket is defined as an endpoint for communication, A pair of processes communicating over a network employ a pair of sockets ,one for each process. A socket is identified by an IP address concatenated with a port number.
The server waits for incoming client requests by listening to a specified port. Once a request is received, the server accepts a connection from the client socket to complete the connection.


- `Kernel` is the central core component of an operating system that manages operations of computer and hardware. Kernel Establishes communication between user level application and hardware. Manages memory and CPU time. Decides state of incoming processes. Controls Disk, Memory, Task Management

- `Monolithic Kernel` (provides good performance but lots of lines of code) : It is one of the types of kernel where all operating system services operate in kernel space. It has dependencies between system components. It has huge lines of code which is complex.
Example : Unix, Linux, Open VMS, XTS-400 etc.


---

3. Difference between process and program and thread? Different types of process. 

`Process`: Process is an instance of an executing program. For example, we write our computer programs in a text file and when we execute this program, it becomes a process which performs all the tasks mentioned in the program.

`Program`: Program is a set of instructions to perform a certain task. Eg: chrome.exe, notepad.exe

`Thread`: Thread is a path of execution within a process. A thread is also known as a lightweight process. The idea is to achieve parallelism by dividing a process into multiple threads. For example,Word processor uses multiple threads: one thread to format the text, another thread to process inputs.

---

4. Define virtual memory, thrashing, threads.  

- `Virtual Memory`: A computer can address more memory than the amount physically installed on the system. This extra memory is actually called virtual memory and it is a section of a hard disk that’s set up to emulate the computer’s RAM.
The main visible advantage of this scheme is that programs can be larger than physical memory. Virtual memory serves two purposes. First, it allows us to extend the use of physical memory by using a disk. Second, it allows us to have memory protection, because each virtual address is translated to a physical address.

- `Thrashing`: Thrashing is a condition or a situation when the system is spending a major portion of its time in servicing the page faults, but the actual processing done is very negligible. High degree of multiprogramming(if number of processes keeps on increasing in the memory), lack of frames (if a process is allocated too few frames, then there will be too many and too frequent page faults) causes Thrashing.

- `Threads`: A thread is a single sequential flow of execution of tasks of a process so it is also known as thread of execution or thread of control.

---

5. What is RAID ? Different types. 

`RAID (Redundant Arrays of Independent Disks)` is a technique which makes use of a combination of multiple disks instead of using a single disk for increased performance, data redundancy or both.Data redundancy, although taking up extra space, adds to disk reliability. This means, in case of disk failure, if the same data is also backed up onto another disk, we can retrieve the data and go on with the operation.

> RAID 1 to RAID 10

---

6. What is a deadlock? Different conditions to achieve a deadlock. 


A Deadlock is a situation where each of the computer processes waits for a resource which is being assigned to some other process. In this situation, none of the processes gets executed since the resource it needs is held by some other process which is also waiting for some other resource to be released.

How deadlock is achieved: Deadlock happens when Mutual exclusion, hold and wait, No preemption and circular wait occurs simultaneously.

Necessary Conditions for deadlock:

- Mutual Exclusion
- Hold and Wait
- No preemption
- Circular Wait

---

7. What is fragmentation? Types of fragmentation. 

Fragmentation:
An unwanted problem in the operating system in which the processes are loaded and unloaded from memory, and free memory space is fragmented. Processes can’t be assigned to memory blocks due to their small size, and the memory blocks stay unused. It is also necessary to understand that as programs are loaded and deleted from memory, they generate free space or a hole in the memory. These small blocks cannot be allotted to new arriving processes, resulting in inefficient memory use.

The conditions of fragmentation depend on the memory allocation system. As the process is loaded and unloaded from memory, these areas are fragmented into small pieces of memory that cannot be allocated to incoming processes. It is called fragmentation.

Types of fragmentation:
1. Internal
2. External

---

8. What is spooling ? 

SPOOL is an acronym for `simultaneous peripheral operations online`. 
Spooling is a process in which data is temporarily held to be used and executed by a device, program, or system.
In spooling, there is no interaction between the I/O devices and the CPU. That means there is no need for the CPU to wait for the I/O operations to take place. Such operations take a long time to finish executing, so the CPU will not wait for them to finish.
The biggest example of Spooling is printing. The documents which are to be printed are stored in the SPOOL and then added to the queue for printing. During this time, many processes can perform their operations and use the CPU without waiting while the printer executes the printing process on the documents one-by-one.

---

9. What is semaphore and mutex (Differences might be asked)? Define Binary semaphore. 

---

10. Belady’s Anomaly

`Bélády’s anomaly` is the name given to the phenomenon where increasing the number of page frames results in an increase in the number of page faults for a given memory access pattern.

Solution to fix Belady’s Anomaly:
Implementing alternative page replacement algo helps eliminate Belady’s Anomaly.. Use of stack based algorithms, such as Optimal Page Replacement Algorithm and Least Recently Used (LRU) algorithm, can eliminate the issue of increased page faults as these algorithms assign priority to pages

---

11. Starving and Aging in OS

Starving/Starvation(also called Lived lock): Starvation is the problem that occurs when low priority processes get jammed for an unspecified time as the high priority processes keep executing. So starvation happens if a method is indefinitely delayed.

Solution to Starvation : Ageing is a technique of gradually increasing the priority of processes that wait in the system for a long time.


---

12. Why does trashing occur? 

High degree of multiprogramming(if number of processes keeps on increasing in the memory) , lack of frames(if a process is allocated too few frames, then there will be too many and too frequent page faults.) causes Thrashing.

---

13. What is paging and why do we need it? 

Paging is a memory management scheme that eliminates the need for contiguous allocation of physical memory. This scheme permits the physical address space of a process to be non – contiguous.
Paging is used for faster access to data. When a program needs a page, it is available in the main memory(RAM) as the OS copies a certain number of pages from your storage device to main memory. Paging allows the physical address space of a process to be noncontiguous.

---

14. Demand Paging, Segmentation 

Demand paging is a method of virtual memory management which is based on the principle that pages should only be brought into memory if the executing process demands them. This is often referred to as lazy evaluation as only those pages demanded by the process are swapped from secondary storage to main memory.
So demand paging works opposite to the principle of loading all pages immediately.

Segmentation is a memory management technique in which the memory is divided into the variable size parts. Each part is known as a segment which can be allocated to a process.

The details about each segment are stored in a table called a segment table. Segment table is stored in one (or many) of the segments.

Segment table contains mainly two information about segment:

Base: It is the base address of the segment
Limit: It is the length of the segment.

---

15. Real Time Operating System, types of RTOS. 

A real-time operating system (RTOS) is a special-purpose operating system used in computers that has strict time constraints for any job to be performed and is intended to serve real time applications that possess data as it comes in , typically without buffer delays.

Types of RTOS:

- Hard RTOS
- Firm RTOS
- Soft RTOS

---

16. Difference between main memory and secondary memory. 



---

17. Dynamic Binding 

Static binding happens when the code is compiled, while dynamic bind happens when the code is executed at run time.

Static Binding:
When a compiler acknowledges all the information required to call a function or all the values of the variables during compile time, it is called “static binding”. As all the required information is known before runtime, it increases the program efficiency and it also enhances the speed of execution of a program. Static Binding makes a program very efficient, but it declines the program flexibility, as ‘values of variable’ and ‘function calling’ are predefined in the program. Static binding is implemented in a program at the time of coding. Overloading a function or an operator is the example of compile time polymorphism i.e. static binding.

Dynamic Binding Calling a function or assigning a value to a variable, at run-time is called “Dynamic Binding”. Dynamic binding can be associated with run time ‘polymorphism’ and ‘inheritance’ in OOP. Dynamic binding makes the execution of a program flexible as it can decide what value should be assigned to the variable and which function should be called, at the time of program execution. But as this information is provided at run time it makes the execution slower as compared to static binding.

---

18. FCFS Scheduling 

---

19. SJF Scheduling 

---

20. SRTF Scheduling 

SRTF Scheduling is a preemptive version of SJF scheduling. In SRTF, the execution of the process can be stopped after a certain amount of time. At the arrival of every process, the short term scheduler schedules the process with the least remaining burst time among the list of available processes and the running process.

---

21. LRTF Scheduling 

This is a preemptive version of Longest Job First (LJF) scheduling algorithm. In this scheduling algorithm, we find the process with the maximum remaining time and then process it. We check for the maximum remaining time after some interval of time(say 1 unit each) to check if another process having more Burst Time arrived up to that time.

---

22. Priority Scheduling 

Priority Scheduling is a method of scheduling processes that is based on priority. In this algorithm, the scheduler selects the tasks to work as per the priority.

The processes with higher priority should be carried out first, whereas jobs with equal priorities are carried out on a round-robin or FCFS basis. Priority depends upon memory requirements, time requirements, etc.

---

23. Round Robin Scheduling 

In Round-robin scheduling, each ready task runs turn by turn only in a cyclic queue for a limited time slice. This algorithm also offers starvation free execution of processes. Widely used preemptive scheduling method in traditional OS. All the jobs get a fair allocation of CPU. Cons include : Finding a correct time quantum is a quite difficult task in this system, Round-robin scheduling doesn’t give special priority to more important tasks.

---

24. Producer Consumer Problem 

About Producer-Consumer problem: The Producer-Consumer problem is a classic problem that is used for multi-process synchronisation i.e. synchronisation between more than one processes.

The job of the Producer is to generate the data, put it into the buffer, and again start generating data. While the job of the Consumer is to consume the data from the buffer.

What’s the problem here?
The following are the problems that might occur in the Producer-Consumer:

The producer should produce data only when the buffer is not full. If the buffer is full, then the producer shouldn’t be allowed to put any data into the buffer.
The consumer should consume data only when the buffer is not empty. If the buffer is empty, then the consumer shouldn’t be allowed to take any data from the buffer.
The producer and consumer should not access the buffer at the same time.

We can solve this problem by using semaphores.

---

25. Banker’s Algorithm 

It is a banker algorithm used to avoid deadlock and allocate resources safely to each process in the computer system. The ‘S-State’ examines all possible tests or activities before deciding whether the allocation should be allowed to each process. It also helps the operating system to successfully share the resources between all the processes. The banker’s algorithm is named because it checks whether a person should be sanctioned a loan amount or not to help the bank system safely simulate allocation resources.

---

26. Explain Cache

Cache memory is an extremely fast memory type that acts as a buffer between RAM and the CPU. It holds frequently requested data and instructions so that they are immediately available to the CPU when needed.


---

27. Diff between direct mapping and associative mapping 

---

28. Diff between multitasking and multiprocessing

---
