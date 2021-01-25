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



# 测试
 ./csim -s 1 -E 1 -b 1 -t traces/yi2.trace
 ref --> hits:9 misses:8 evictions:6
 mine--> hits:9 misses:8 evictions:6

 ./csim -s 4 -E 2 -b 4 -t traces/yi.trace
 ref --> hits:4 misses:5 evictions:2
 mine--> hits:4 misses:5 evictions:2

 ./csim -s 2 -E 1 -b 4 -t traces/dave.trace
 ref --> hits:2 misses:3 evictions:1
 mine--> hits:2 misses:3 evictions:1

 ./csim -s 2 -E 1 -b 3 -t traces/trans.trace
 ref --> hits:167 misses:71 evictions:67
 mine--> hits:167 misses:71 evictions:67

 ./csim -s 2 -E 2 -b 3 -t traces/trans.trace
 ref --> hits:201 misses:37 evictions:29
 mine--> hits:196 misses:42 evictions:34

 ./csim -s 2 -E 4 -b 3 -t traces/trans.trace
 ref --> hits:212 misses:26 evictions:10
 mine--> hits:208 misses:30 evictions:14

 ./csim -s 5 -E 1 -b 5 -t traces/trans.trace
 ref --> hits:231 misses:7 evictions:0
 mine--> hits:231 misses:7 evictions:0

 ./csim -s 5 -E 1 -b 5 -t traces/long.trace
 ref --> hits:265189 misses:21775 evictions:21743
 mine--> hits:265189 misses:21775 evictions:21743

 分析结果：
 除了 trans.trace 其他测试都通过了
 分析原因应该是 trans.trace 里包含了 'I' 指令。我的处理方式是直接跳过。但是看测试的标准答案，应该对其也有一定的处理的。但是根据自己读 write-up 应该是不处理的
