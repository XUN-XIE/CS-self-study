Everything is bits
each bit is 0 or 1


通常使用 4 bits 合成，然后用十六进制

byte 发音 bite
1 byte = 8 bits

**虚拟地址空间是由机器字长决定的**
**我们将使用C大量实现位运算**
1. 人么喜欢C的原因之一，就是因为C可以直接执行位运算这种低级别的操作！
2. 位运算可以理解为表示集合，位运算是集合运算
3. & = 交集， ｜ = 并集， ^ = 对称差异， ~ = 反集
4. **PPT 有个很好的代码， p &&  * p （avoids null pointer access)**
5. shift operation， << , >> 根据base乘以和除以对应base^shift (no overflow or underflow)



Numeric Ranges
1. unsined整型数， MaxRange = 2 ^ (size) - 1
2. 取反操作公式没看懂，看书要仔细解决
3. unsigned and signed numberic value
4. Mapping between signed and unsigned(没听懂)
5. 两者补码可以和unsigned之间相互转化
6. 应该是指 两者补码(现有的减去高一位的单1)得到的是 signed 对应的数


## 为什么重要？
因为C显式的拥有 unsigned 类型，会存在隐式转换的可能
发生在 赋值，比较 时可能是会出问题，所以很重要
如果存在符号数和无符号数，会发生符号数隐式转化为无符号数！！！可能发生的操作，比较运算符和赋值运算符
结合之前的，因为signed数据的负数是依次对应于unsigned数据的。所以如果发生隐式转换可能会出现问题，会被加上或者减去 2 ^ (size)






































