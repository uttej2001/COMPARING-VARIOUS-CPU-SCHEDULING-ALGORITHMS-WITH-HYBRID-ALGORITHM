# COMPARING-VARIOUS-CPU-SCHEDULING-ALGORITHMS-WITH-HYBRID-ALGORITHM
## Introduction 
Operating Systems support wireless communication. As we already know that wireless communication occurs in the number of applications. And conventionally in the wireless network portable devices such as the laptops and mobile phones are associated with a single access point where each device deals with a rigid pool of data speed.   

In a Single Processor Operating Software System, only one method/process can run at a particular time. All processes which are ready to be executed need to wait for as long as a processor is dispatched to the process. Once the CPU is freed from its current task, the next process at the head of the ready queue is sent in for execution. Usually, the computer enters the idle state each time there’s a gap between finishing the execution of a process and waiting for a process to be dispatched into the running state. No work is accomplished during this time. In order to accomplish this CPU Scheduling is introduced. Multiple processes are kept in the main memory at one time. 

In the multiprogramming system, multiple processes are stored in the main memory and are maintained in the main memory. Majority of the processes have a dedicated memory location which contains all intricacies and detailing of the respective process including those of the program to be processed, contents of the registers, etc. Each of the processes also takes it in turn between the processor consumption and I/O event occurrences. 

The highlight of multiprocessing in a system is to ensure that the CPU never sits idle and that it needs to consistently indulge in executing/processing programs and tasks as this is one of the best ways to increase and elevate the CPU utilization and efficiency. Most importantly, all peripherals and resources to be used by the scheduled processes need to be scheduled and arranged in an organized manner. 

FCFS is a simple and easy scheduling algorithm with regards to implementation and understanding. The process which arrives first and requests for the CPU will be allotted the processor and goes into execution. This is done through the FIFO queue. However, it can lead to extremely large waiting times and takes quite long for completion. 

One of the other conventional scheduling algorithms is Shortest Job First (SJF) wherein the CPU allocates the processor to those processes which have the shortest amount of time for completion and considers the burst time for scheduling the processes. In case of situations where more than one process has the same amount of time for completion, then FCFS is used to decide which process is scheduled next.  

Priority scheduling, is the algorithm that executes and completes the processes based on the priority which has been assigned to each of the tasks/processes in the schedule queue. Those processes with a higher priority are executed initially while those with lower priority are processed towards the end. This algorithm can also be of preemptive or non-preemptive type. 

Round Robin is the algorithm which is capable of ensuring that each of the processes get an equal share of CPU allotment on the basis of the pre-decided time quantum is the RR algorithm. Each of the processes from the scheduling queue will be executed in a cyclic order for a limited amount of time. The major highlight of this algorithm is that it ensures starvation free process execution.

## INPUT DETAILS OF THE PROCESS FROM THE USER 
![image](https://user-images.githubusercontent.com/72940291/139532213-eef63ba4-bae8-4db7-a470-7b48eaf1af9b.png)
![image](https://user-images.githubusercontent.com/72940291/139532243-109a62bc-0ad1-4c4d-bcab-a1bbe5623f94.png)
## Gantt Chart & Timeline Chart
![image](https://user-images.githubusercontent.com/72940291/139532264-38ac3ccc-58b4-4314-abc8-c919ba102f61.png)
## Final Table
![image](https://user-images.githubusercontent.com/72940291/139532283-2b0bd265-eca0-4c95-830c-a154dd671e12.png)
## Final Comparitive Graph
![image](https://user-images.githubusercontent.com/72940291/139532307-c4fa389b-1157-4c3d-86ff-35d467177aad.png)
