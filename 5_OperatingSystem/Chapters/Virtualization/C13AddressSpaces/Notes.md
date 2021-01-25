出现的意图：
1. 早期计算机，在 context switch 时，把 memory 里的数据和状态，全部存储到 disk （可知这样的做法很慢！因为在做对 disk 的读写操作）
2. 因此，如果能把所有的 context switch 发生时的数据和状态都存储在 memory 就会加快存储速度！（回忆 CSAPP 里的 memory hierarchy）

# 13.3 The address space
三个最重要的组成元素：
1. stack 在最大值处向上 减小地址 获取
2. heap 在最小值（除 program code 外）向下 增加地址 获取
3. program code （整个地址空间的 最小值处）

# Crux P112
HOW TO VIRTUALIZE MEMORY


# 13.4 Goals
设计操作系统的目标
1.transparency: The OS should implement virtual memory in a way that is invisible to the running program.
2. efficiency: The OS should strive to make the virtualization as efficient as possible, both in terms of time and space
3. protection / isolation: The OS should make sure to protect processes from one another as well as the OS itself from pro- cesses.

ASIDE: 小实验，打印 code，stack，heap 的初始虚拟地址！
mac 上打印，好像不太符合预期。问题出在 heap 上，heap 的初始位置接近于 stack， 而不是 code 的位置！
Linux 云主机上打印，完全复合书中的预期

