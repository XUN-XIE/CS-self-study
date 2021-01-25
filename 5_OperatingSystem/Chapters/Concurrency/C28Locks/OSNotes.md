# 28.13 A Simple Approach: Just Yield, Baby
1. Our first try is a simple and friendly approach: when you are going to spin, instead give up the CPU to another thread.

2.  While better than our spinning approach (which would waste 99 time slices spinning), this approach is still costly; the cost of a context switch can be substantial, and there is thus plenty of waste.

3. Worse, we have not tackled the starvation problem at all. A thread may get caught in an endless yield loop while other threads repeatedly enter and exit the critical section. We clearly will need an approach that addresses this problem directly.



**从这里开始后面，不是很理解，略微复杂了起来
但是这里开始的 OS 支持的代码，才是真正实现一个 lock 的正确方式和最终版本！**
# 28.14 Using Queues: Sleeping Instead Of Spinning
1. 









