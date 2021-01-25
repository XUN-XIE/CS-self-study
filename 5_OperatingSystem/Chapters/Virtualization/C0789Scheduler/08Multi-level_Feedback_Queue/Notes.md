one of the most well-known approaches to scheduling
The scheduler has subsequently been refined throughout the years to the implementations you will encounter in some modern systems.

**其实可以理解成是 SJF 和 RR 两个调度算法的结合体！不过用历史记录来预测，然后选择两个调度算法之一进行近似！**

**The fundamental problem MLFQ tries to address is two-fold**
    * First, it would like to optimize turnaround time
    * Second, MLFQ would like to make a system feel responsive to interactive users, thus minimize response time

__problem__: given that we in general do not know anything about a process, how can we build a scheduler to achieve these goals? How can the scheduler learn, as the system runs, the characteristics of the jobs it is running, and thus make better scheduling decisions?

# Crux P71
HOW TO SCHEDULE WITHOUT PERFECT KNOWLEDGE?

**重要思想: LEARN FROM HISTORY**
TIP: LEARN FROM HISTORY
The multi-level feedback queue is an excellent example of a system that learns from the past to predict the future. Such approaches are __common in operating systems__ (and many other places in Computer Science, including __hardware branch predictors__ and __caching algorithms__). Such approaches work when jobs have phases of behavior and are thus pre- dictable; of course, one must be careful with such techniques, as they can easily be wrong and drive a system to make worse decisions than they would have with no knowledge at all.


### 8.1 MLFQ: Basic Rules
1. a number of distinct queues, each assigned a different priority level
2. At any given time, a job that is ready to run is on a single queue
3. MLFQ uses priorities to decide which job should run at a given time: a job with higher priority (i.e., a job on a higher queue) is chosen to run.
4. Of course, more than one job may be on a given queue, and thus have the same priority. In this case, we will just use round-robin scheduling among those jobs.
5. key to MLFQ scheduling lies in how the scheduler sets pri- orities.
6. MLFQ varies the priority of a job based on its observed behavior
7. 实施，判断process priority的例子：If, for example, a job repeat- edly relinquishes the CPU while waiting for input from the keyboard, MLFQ will keep its priority high, as this is how an interactive process might behave. If, instead, a job uses the CPU intensively for long periods of time, MLFQ will reduce its priority. In this way, MLFQ will try to learn about processes as they run, and thus use the history of the job to predict its future behavior.

**
• Rule 1: If Priority(A) > Priority(B), A runs (B doesn’t).
• Rule 2: If Priority(A) = Priority(B), A & B run in RR.
**

### 8.2 Attempt #1: How to Change Priority
basis: a mix of interactive jobs that are short-running (and may frequently relinquish the CPU), and some longer-running “CPU-bound” jobs that need a lot of CPU time but where response time isn’t important

**
• Rule 3: When a job enters the system, it is placed at the highest priority (the topmost queue).
• Rule 4a: If a job uses up an entire time slice while running, its pri- ority is reduced (i.e., it moves down one queue).
• Rule4b:IfajobgivesuptheCPUbeforethetimesliceisup,itstays at the same priority level.
**


__one of the major goals of the algorithm__: because it doesn’t know whether a job will be a short job or a long-running job, it first assumes it might be a short job, thus giving the job high priority. If it actually is a short job, it will run quickly and complete; if it is not a short job, it will slowly move down the queues, and thus soon prove itself to be a long-running more batch-like process. In this manner, MLFQ approximates SJF.


##### Problems With Our Current MLFQ
(太多的 interactive 进程会使得 priority较低的进程无法使用CPU)First, there is the problem of __starvation__: if there are “too many” in- teractive jobs in the system, they will combine to consume all CPU time, and thus long-running jobs will never receive any CPU time (they starve).

(程序可以故意设计成恶意使用全部的CPU)Second, a smart user could rewrite their program to game the sched- uler. The algorithm we have described is susceptible to the following attack: before the time slice is over, issue an I/O operation (to some file you don’t care about) and thus relinquish the CPU; doing so allows you to remain in the same queue, and thus gain a higher percent- age of CPU time.

(不能让先运行，后编程 interactive 的程序提升 priority)Finally, a program may change its behavior over time; what was CPU- bound may transition to a phase of interactivity


### 8.3 Attempt #2: The Priority Boost
**
• Rule 5: After some time period S, move all the jobs in the system to the topmost queue.
**

**Our new rule solves two problems at once.**
    * First, processes are guar- anteed not to starve
    * Second, if a CPU-bound job has become interactive, the scheduler treats it properly once it has received the priority boost.


__parameter S is an trade-off option__: If it is set too high, long-running jobs could starve; too low, and interactive jobs may not get a proper share of the CPU.


### 8.4 Attempt #3: Better Accounting
解决上述中的第二个问题：恶意控制CPU使用

问题出在原始的 rule 4a 4b

修改为：
**
• Rule 4: Once a job uses up its time allotment at a given level (re- gardless of how many times it has given up the CPU), its priority is reduced (i.e., it moves down one queue).
**


### 8.5 Tuning MLFQ And Other Issues
One big question is how to parameterize such a scheduler
    * how many queues should there be
    * How big should the time slice be per queue
    * How often should priority be boosted in order to avoid starvation and account for changes in behavior


most MLFQ variants allow for varying time-slice length across different queues: 
    * The high-priority queues are usually given short time slices    
    * The low-priority queues, in contrast, contain long-running jobs that are CPU-bound; hence, longer time slices work well


Finally, many schedulers have a few other features that you might en- counter. 
    * (OS 的 priority 最高！) some schedulers reserve the highest priority levels for operating system work; thus typical user jobs can never obtain the highest levels of priority in the system.
    * ( change scheduler algorithm by command __nice__) Some systems also allow some user advice to help set priorities; for example, by using the command-line utility nice you can increase or decrease the priority of a job (somewhat) and thus increase or decrease its chances of running at any given time.


# MLFQ: Summary
why it is called that: it has multiple levels of queues, and uses feedback to determine the priority of a given job. History is its guide: pay attention to how jobs behave over time and treat them accordingly.


TIP: USE ADVICE WHERE POSSIBLE
因为不同的 OS 要处理的任务不一样。因此 OS 也提供了可以更改一些算法策略的 接口
    * scheduler : nice
    * memory manager : madvise
    * file system : TIP


