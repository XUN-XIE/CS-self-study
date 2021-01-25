# 重点
### 1. 理解 DFF 在第一个 Bit 实现中的用法！HDL是电路图语言，并不是传统的编程语言！不是顺序执行，而是模拟出电路图
### 2. 学习RAM8-16K的实现， DMux8Way 和 Mux8Way16 的巧妙用法。理解 Memory 的构建过程，如何与 第二章的 逻辑运算搭建关系

**先看书，因为这块儿知识没接触过，有bakground再看视频**
# 3.1 Sequential Logic
Clock: basic time unit in computer
1. 利用 clock 模拟出计算机内的虚拟时间，作为时间的单位
2. 逻辑运算，都在一个 clock 内进行计算，然后把 signal 进行改变
3. 尽管 物理电信号 不是立即改变，但是我们可以直接取 每个clock 最后一小段的稳定！signal 作为结果
4. (之前两个Chapter都是 Combinatorical logic， 这一章的 memory 是 Sequential Logic)Combinatorical logic VS Sequential Logic
    * Combinatorical Logic is dependent on the current time unit
    * Sequential Logic is dependent on the last time unit
5. Combinatorcial Logic will mix the new information with old information


# 3.2 Flip Flops
1. DFF
2. out[t] = in[t-1]
3. 把 DFF 当作 NAND 一样，作为最基础的黑盒！更底层就不是 CS 关心的知识了
4. 


















