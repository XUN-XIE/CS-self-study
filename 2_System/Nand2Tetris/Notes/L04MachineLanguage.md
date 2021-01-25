Memory Hierarchy
可以理解成：每次需要访问一个大小的存储结构时， 我们所需要传入的位数！
回忆上一节，一个 Register，不需要address就能访问，一个RAM8，需要三位address访问，以此类推，一个RAM16K，需要14位。进行对比可以发现，内存层次结构，可以让我们对本身小容量的存储结构，快速的访问，因为只需要一位address，而大容量存储结构，则需要更多位！运算当然会慢一些, clock会多一些

Reigister(最快，访问直接可以达到)
1. 用来存储临时需要计算的数据
2. 存储需要访问内存的地址！


**Essence of Machine Language**
A machine language can be viewed as an agreed-upon formalism, designed to manipulate a memory using a processor and a set of registers.















