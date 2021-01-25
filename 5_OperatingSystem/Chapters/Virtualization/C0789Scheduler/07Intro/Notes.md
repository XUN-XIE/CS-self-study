Software Policies
算法！其实学习的就是调度算法，来调度不同的process占用CPU

# Crux P59
HOW TO DEVELOP SCHEDULING POLICY
    How should we develop a basic framework for thinking about scheduling policies? 
    What are the key assumptions? 
    What metrics are important? 
    What basic approaches have been used in the earliest of computer systems?


### 7.1 Workload Assumptions
**workload**: Determining the workload is a critical part of building policies, and the more you know about workload, the more fine-tuned your policy can be.

__assumptions__: We will make the following assumptions about the processes, sometimes called jobs, that are running in the system:
    1. Each job runs for the same amount of time.
    2. All jobs arrive at the same time.
    3. All jobs only use the CPU (i.e., they perform no I/O) 
    4. The run-time of each job is known.
__通过逐步去掉 assumptions 研究出 practical schedule algorithms__


### Metrics
__turnaround time__(Performance metric): the time at which the job completes minus the time at which the job arrived in the system

another metric will discussed later (fairness)

### First In, First Out (FIFO)
1. simple to implement
2. not suitable for first assumption (all jobs rum same time)

### Shortest Job First (SJF)
1. suitable for first assumption
2. not suitable for second assumption (all jobs arrive at same time)

### Shortest Time-to-Completion First (STCF)
1. suitable for second assumption

__response time__: the time from when the job arrives in a system to the first time it is scheduled. (which related to interactivity! you need to wait in front of computer but you can't type command in a shell!)

2. not suitable for response time metric

### Round Robin (time- slicing)
Idead: instead of running jobs to completion, RR runs a job for a time slice (sometimes called a scheduling quantum) and then switches to the next job in the run queue.

1. suitable for response time metric
2. not suitable for turnaround metric

**Note that the length of a time slice must be a multiple of the timer-interrupt period (因为 OS 只有这样才能 从进程中 regain control 进行 context switch！！！)**

3. the length of the time slice is critical for RR. The shorter it is, the better the performance of RR under the response-time metric.
4. However, making the time slice too short is problematic: suddenly the cost of context switching will dominate overall performance.
5. (需要算法里的 amortized analysis 使得 contect switch 的开销摊销变小)Thus, de- ciding on the length of the time slice presents a trade-off to a system de- signer, making it long enough to amortize the cost of switching without making it so long that the system is no longer responsive.


### 两个metric的分析
1. performance: turnaround time
2. fairness   : response time
**this is an inherent trade-off: if you are willing to be unfair, you can run shorter jobs to com- pletion, but at the cost of response time; if you instead value fairness, response time is lowered, but at the cost of turnaround time. This type of trade-off is common in systems; you can’t have your cake and eat it too.**

### 7.7 Incorporating I/O
relax assumption 3 : (jobs can only use CPU, now can request I/O)

Overlap: when one process doing I/O opertions, we can switch it to another process to be in CPU


### 7.8 No More Oracle
assumption 4 (known time of jobs)

Thus, how can we build an approach that be- haves like SJF/STCF without such a priori knowledge? Further, how can we incorporate some of the ideas we have seen with the RR scheduler so that response time is also quite good?


