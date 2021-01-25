yi.trace

example from Write Up

s = 4; E = 1, b = 4
Sets = 16; Block = 16 bytes
cache size = 256 bytes

m = 8 bytes
address = 64 bits
t = 56 ; 
s = 4, b = 4

 L 10,1     // miss, 加载 0x10 --> set1
 M 20,1     // S --> miss --> L --> hit , 0x20 =   --> set2
 L 22,1     // hit， 因为 0x22 = --> set2
 S 18,1     // hit, 0x18 --> set 1
 L 110,1    // 0x110 --> set1 --> block 0 与第一条 L 冲突，因此 miss eviction
 L 210,1    // 0x210 --> set1   --> 同上 miss eviction
 M 12,1     // 0x12  --> set1   --> 因为上面两行修改了 set1，标志位不匹配。因此 miss eviction，第二次操作 hit

 **M当作是 L 和 S 的集合操作，其实就相当于访问两次，解释了最后一条指令的问题**
