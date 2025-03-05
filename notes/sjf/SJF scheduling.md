
The operating system is responsible for scheduling a job for the processor. There are various types of algorithms used for scheduling a job to the CPU for executing these processes. Shortest Job First (SJF) is a type of disk scheduling algorithm in the operating system in which the processor executes the job first that has the smallest execution time. In the shortest Job First algorithm, the processes are scheduled according to the burst time of these processes.

### Intro to SJF

The 'Disk Structure in OS' is made in such a way that there are many layers of storage blocks on the disk. And when we need to access these data from disk, we initialize a 'request' to the system to give us the required data. These requests are done on a large scale. So, there is a large number of input and output requests coming to the disk. The operating system manages the timetable of all these requests in a proper algorithm. This is called as `"Disk Scheduling Algorithm in OS"`.

This algorithm helps OS to maintain an efficient manner in which input-output requests can be managed to execute a process. There are various types of algorithms that an operating system uses for scheduling a process to the CPU. These algorithms have their own advantages and disadvantages and features. All the scheduling algorithms are useful in different conditions. The SJF (Shortest Job First) scheduling algorithm in which the CPU executes the job first has the shortest execution time. Also, the burst time is an important factor in SJF scheduling.

![[notes/sjf/Pasted image 20240629185811.png]]

Burst time can be defined as the time required by the process to get executed in a millisecond. The process that has the lowest burst time of all the currently available processes, will get scheduled by the SJF algorithm and it will get executed first. Also, it is not an easy task to predict the burst of a process so, the implementation of the SJF algorithm is also not easy.

## Characteristics of SJF Scheduling

Following are the characteristics of (Shortest Job First) SJF scheduling program in C.

- This algorithm is related to each job as a unit of time for completion.
- This algorithm is helpful for those types of processing of jobs in which the completion time of a job can be calculated easily like Batch-type processing.
- This algorithm can improve the CPU processing as it executes the shorter jobs first which leads to a short turnaround time.

## Algorithm

The algorithm of Shortest Job First is as follows:

- First of all, all the processes are sorted according to the arrival time.
- After that, the process having minimum arrival and burst time is selected.
- Then that process gets executed and all the process that arrives waits in a queue while the first process is in the execution state, and after completion again the process with minimum arrival and burst time is selected for the next execution.


## Types of SJF

(Shortest Job First) SJF scheduling program in C is of two types. 
The first one is Pre-emptive SJF and the second one is Non-Preemptive SJF. Let us see them in detail.

### Pre-emptive SJF

Pre-emptive SJF is a type of scheduling algorithm in which jobs are inserted into the ready queue as soon as they arrive at the disk. The process having the shortest burst time starts to get executed first, even if the shortest burst time arrives the current burst is removed from the execution process and the job having the shortest burst time gets allocated in the CPU cycle. Suppose there are five processes in a queue and their burst time and arrival time are given below in the table.

| Process Queue | Burst Time | Arrival Time |
| ------------- | ---------- | ------------ |
| P1            | 6          | 2            |
| P2            | 2          | 5            |
| P3            | 8          | 1            |
| P4            | 3          | 0            |
| P5            | 4          | 4            |

The processes will get executed in the following steps:

- job P4 arrives at time t=0, and gets executed
- after that at time=1, the process P3 comes. Since the burst time of P4 has a short burst time so it will get executed.
- all the jobs at each instance of time, a new job arrives and it is then compared to the burst time of other jobs. And the jobs having the shortest burst time will get executed.
- at time=15, when the process P1 gets executed, there is only job P3 left. So, it will get executed.
- at time=23, the process P3 will finish.

Now, the average waiting time will be calculated as:

```c
Wait time 
P4= 0-0=0
P1=  (3-2) + 6 =7
P2= 5-5 = 0
P5= 4-4+2 =2
P3= 15-1 = 14

The average waiting time is: 0+7+0+2+14/5 = 23/5 =4.6
```

### Non-Preemptive SJF

In this type of scheduling algorithm, if one process is allocated for the CPU, the process sticks to the CPU until the process becomes in a waiting state or gets executed. Suppose there are 5 processes shown in the below table and they have their own burst time and average time.

|Process Queue|Burst Time|Arrival Time|
|---|---|---|
|P1|6|2|
|P2|2|5|
|P3|8|1|
|P4|3|0|
|P5|4|4|

Given below are the steps through which the processes get executed:

- At time= 0, the CPU gets allocated to the process P4.
- At time= 1, Process P3 comes, but here process P4 is already in between the execution. So, the process will continue to execute here.
- At time= 2, the process P1 comes but it is added to the waiting queue and process P4 will still be in the execution process.
- Atc time= 3, P4 will finish. Here the burst time of processes P3 and P1 will be compared. Here the burst time of P1 is the shortest so it will get executed first.
- This will continue at each instance of time and lastly, process P5 will get executed and at time= 23, process P23 will get executed.

Now the average waiting time will be calculated as follows:

```c
Wait time 
P4= 0-0=0
P1=  3-2=1
P2= 9-5=4
P5= 11-4=7
P3= 15-1=14

Average Waiting Time= 0+1+4+7+14/5 = 26/5 = 5.2
```

## 3 factors to consider while solving SJF

There are some factors that are responsible for calculating the SJF algorithm. Let us see them in brief.

### BURST Time

The burst time is defined as the difference between the completion time and the waiting time for a particular process.

### Average waiting time

The waiting time is defined as the difference between the turnaround time and burst time of a process.

### Average turnaround time

The Turn around time is defined as the time taken by a process to complete after the arrival time. Or simply we can say that turnaround time is the difference between the arrival and completion time of a process.



## Advantages of SJF

The following are the advantages of SJF scheduling:

- This algorithm comes into use when there is long-term scheduling.
- This algorithm reduces the average waiting time.
- This algorithm is useful if there is a batch-type processor.
- This algorithm can be considered an optimal algorithm because, in this algorithm, the average waiting time is minimum.

## Disadvantages of SJF

The following are the disadvantages of the SJF algorithm:

- There are chances that this algorithm will face starvation if there are too many processes that have shorter burst times then it will cause longer processes to wait in the queue will lead to Starvation.
- This algorithm can lead to a long turnaround time.
- It is not an easy task to get knowledge about the length of future jobs.

## Conclusion

- The SJF scheduling algorithm executed that process first that has the smallest execution time.
- The SJF algorithm considers the time as a unit for a job to execute a process.
- Used in Batch-type processing because, in this type of system, it is easy to wait for one job to get executed first.
- There are two types of SJF scheduling algorithms that are:-
    - Non-preemptive SJF
    - Preemptive SJF
- In non-preemptive SJF, one process gets executed in a single CPU cycle and the process sticks to the CPU until it gets executed.
- SJF is generally used when there is long-term scheduling.
- Waiting time of this algorithm is reduced when compared to the FIFO (First in First Out) algorithm.