fair-share scheduler
随机算法
lottery scheduling

concept: instead of optimizing for turnaround or response time, a scheduler might instead try to guarantee that each job obtain a certain percentage of CPU time.

basic idea: every so often, hold a lottery to determine which pro- cess should get to run next; processes that should run more often should be given more chances to win the lottery


# Crux P83
HOW TO SHARE THE CPU PROPORTIONALLY
    How can we design a scheduler to share the CPU in a proportional manner? 
    What are the key mechanisms for doing so? 
    How effective are they?


### 9.1 Basic Concept: Tickets Represent Your Share
__tickets__: used to represent the share of a resource that a process (or user or whatever) should receive

#思想: USE RANDOMNESS
TIP: USE RANDOMNESS
Random approaches has at least three advantages over more traditional decisions.
    * First, random often avoids strange corner-case behaviors that a more traditional algorithm may have trouble handling.
    * Second, random also is lightweight, requiring little state to track alter- natives
    * Finally, random can be quite fast.


### 9.2 Ticket Mechanisms
1. __ticket currency__: 进程向自己的任务，进行分配。但是在总体所有进程的所有任务分配CPU时，要进行汇率转换
Currency allows a user with a set of tick- ets to allocate tickets among their own jobs in whatever currency they would like; the system then automatically converts said currency into the correct global value.
2. __ticket transfer__: 进程可以把自己份额分给子进程
With transfers, a process can temporarily hand off its tickets to another process. This ability is especially useful in a client/server setting, where a client process sends a message to a server asking it to do some work on the client’s behalf. To speed up the work, the client can pass the tickets to the server and thus try to maximize the performance of the server while the server is handling the client’s request. When finished, the server then transfers the tickets back to the client and all is as before.
3. __ticket inflation__: 一组互相信任的进程通过改变自身 ticket 的大小来获取或抛弃CPU资源。
With inflation, a process can temporarily raise or lower the number of tickets it owns.
inflation can be applied in an environment where a group of processes trust one another; in such a case, if any one process knows it needs more CPU time, it can boost its ticket value as a way to reflect that need to the system, all without communicating with any other processes.

### 9.5 How To Assign Tickets?

### 9.6 Why Not Deterministic?
scheduler, it occasionally will not deliver the exact right proportions, especially over short time scales

__stride scheduling__, a deterministic fair-share scheduler

1. Each job in the system has a __stride__, which is inverse in proportion to the number of tickets it has.
2. every time a process runs, we will increment a counter for it (called its pass value) by its stride to track its global progress.
3. idea: at any given time, pick the process to run that has the lowest pass value so far; when you run a process, increment its pass counter by its stride.



对比 lottery 和 stride scheduler
lottery scheduling has one nice property that stride scheduling does not: no global state


解释 上述的比较（如果中途加入新的 process， stride scheduler 无法为 新的进程 设置其 stride！ 但是 lottery 可以！
Imagine a new job enters in the middle of our stride scheduling example above; what should its pass value be? Should it be set to 0? If so, it will monopolize the CPU. With lottery scheduling, there is no global state per process; we simply add a new process with whatever tickets it has, update the single global variable to track how many total tickets we have, and go from there. In this way, lottery makes it much easier to incorporate new processes in a sensible manner.


**所以，最终还是会选择 lottery scheduler 作为调度算法**



# summary
1. 通用调度算法，MLFQ 被使用的更多
General-purpose schedulers (such as the MLFQ we discussed previously, and other similar Linux schedulers) do so more gracefully and thus are more widely deployed.
2. 随机调度算法，在特殊情况下（ticket的份额比较好取值），才有用武之地
proportional-share schedulers are more useful in domains where some of these problems (such as assignment of shares) are rela- tively easy to solve.

例如：
For example, in a virtualized data center, where you might like to assign one-quarter of your CPU cycles to the Windows VM and the rest to your base Linux installation, proportional sharing can be simple and effective.




