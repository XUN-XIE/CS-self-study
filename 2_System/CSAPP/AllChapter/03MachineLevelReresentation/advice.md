这一章超级难读，尤其是没学过汇编语言的

1. 建议：寄存器的那个表格，Figure3.2，里面的每个寄存器的字节长度倒还好说。重点是**最后那一列，表示每个寄存器的作用**。后面书中的每个例子，都反复的回来查看这个表格，对应它的作用是，然后才能逐渐理解，每一行汇编代码，不然总会看着看就看不懂了！！！
2. 用 objdump -d  查看反汇编码时的那两列地址，也很重要，后面也会出现，导致理解不懂这些机制在干嘛。根据查阅 下面那一条的，读书笔记理解。第一列 offset就是指当前指令所处的 地址。第二列是 指令转成机器码(binary representation)的表达形式
3. 结合 已有的网上读书笔记进行阅读





