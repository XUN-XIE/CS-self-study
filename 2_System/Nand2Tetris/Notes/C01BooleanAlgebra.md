### 1.1 Background
1. Boolean gates are physical implementations of Boolean functions
2. Since computer hardware is based on the representation and manipulation of binary values, Boolean functions play a central role in the specification, construction, and optimization of hardware architectures.
3. OR : +
4. AND : ·
5. A gate is a physical device that implements a Boolean function
6. (门 就是计算机科学家关心的最底层的黑盒，再向下就是电子工程师的职责了)Hence, a primitive gate (see figure 1.3) can be viewed as a black box device that implements an elementary logical operation in one way or another—we don’t care how
7. To sum up, the art of logic design can be described as follows: Given a gate specification (interface), find an efficient way to implement it using other gates that were already implemented. This, in a nutshell, is what we will do in the rest of this chapter.


# Lecture 1.2 Boolean Function
1. **一个通过真值表，反向构建布尔函数的方法，参见视频Unit1.2**
    1. 找到所有的 ouput 为 1 的行
    2. 对所有的input，以 AND 连接起来
    3. 如果 单个 input 为 1， 则直接写上该input； 如果 input 为 0，则加上 NOT 写上该 input
    4. 对所有的 output 为 1 的行。结合第三步中写成的每行独立的布尔函数，以 OR 连接
    5. 得到了最后的布尔函数，可以进行化简！(化简就得看布尔运算的功底了，可以参见 《离散数学及其应用》)
    **没有算法能够找出最短的布尔函数表达式，因为这是 NP 问题！！！**
2. Theorem:
**Any Boolean function can be represented using an expression containing AND and NOT operations.**
    proof: x OR y = NOT( NOT(x) AND NOT(y) )
3. NAND operation can represent all operations!
x NAND y = NOT( x AND y )
4. Theorem:
**Any Boolean fucntion canbe represented using an expression containing only NAND operations**
    proof:
        * NOT(x) = (x NAND x)
        * x AND y = NOT( x NAND y )

# Lecture 1.3 Logic Gate
1. 哲学：计算机接口(inferface) 和实现(implmentation) 的分离性，接口必须准确，只有一个，但是实现可以多种多样
2. Curcuits, transistors, relays, they are EE rather than CS


# Lecture 1.4 HDL
1. simulation
2. Design: from requirement to interface
    * Requirement: Build a gate that deliver specific functionality
    * Gate Interface: Implemented as an HDL stub file
3. Design: from gate diagram to HDL
4. Before using a chip part, you must know its interface!
**思想延伸：如果要使用一个类，必须先知道类的接口**
**如果要使用一个函数，必须先知道函数的接口**
**如果要使用一个命令，必须先知道命令的接口**
**Before using something, you must know its inferface first.**


# Lecture 1.5 Hardware Simulation
1. Verification
2. Hand-on. Practice!
3. 介绍硬件模拟软件的使用，测试


# Lecture 1.6 Multi-bit Buses
1. 如何处理多位bit
2. bus(总线): a group of bits as a single entity
3. HDL provide some convenient notation for handling buses
4. 多位bit的门，就是多条线同时进入该门(稍微具象的理解)，抽象上，还是和之前一样，两个多位，仍然是两个 input


# 1.7 Project         
1. just given NAND, to implement all 15 gate operations
2. Multiplexor
3. Demultiplexor













