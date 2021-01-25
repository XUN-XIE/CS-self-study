### 2.4.2 IEEE Floating-Point Representation
1. M 的 range 是根据情况改变的，0-1, 1-2
2. normalizaed case，需要表示一般的正常数据，M = 1-2
3. denormalizaed case，需要表示 0 和极其接近0的数据，所以 M = 0-1
4. **为什么 Normalized case 的M有个leading implied，biancheng M = 1 + fraction (看到后面的例子就明白了，是为了防止重叠，因为 denormalized 能表示的最大值，和normalized 能表示的最小值，刚好是分隔开的！如果不加的话，那么会出现 两个 case 有重叠的现象)**
5. normalized case 中 exponent 的 range 只能从 000..0001 到 111...1110 ，因为全是0属于denormalized case，全是1属于special case！
6. 如果要记住怎么计算 floating 表示的值，得三种情况分别讨论记忆
7. 加深理解，normalized case 里 M = 1 + ...，另一个原因是一般数字，用科学记数法，就是 nEe, 但是科学计数法是十进制的，所以降低到 二进制，就变成了 1.... (这里的...是0 or 1)后缀 2^E。所以这样以来， M 自带一个加一， 我们就可以直接把 小数点后面的一串二进制，直接转成 fractional filed里去！(这应该就是作者前面提到的 leading implied 思想，只是那时候看不懂)
8. Practice Problem48之前的那个小例子要理解！， int 和 float 的 fractional 对齐！除了 int 的第一位，因为 implied leading，那个 1 也对上了！！！


### rounding
1. 注意，取最近的方法，如果是 .5的情况，那么就rounding后最小位为偶数的去rounding
2. round to even 存在的理由是，防止统计偏差


### floating operation
1. 因为 rounding，所以 加减法 不符合 交换律，就是先加哪个后加哪个会影响结果
2. 因为 rounding 和 overflow，所以 乘法 也没有交换律
3. 不过float的乘法和加法还是具备一些 unsigned signed 数没有的性质，(比后者更优良)，尤其是针对 科学计算，这一章很重要


### 2.4.6 Floating Point in C
1. All versions of C provide two different floating-point data types: float and dou- ble. On machines that support IEEE floating point, these data types correspond to single- and double-precision floating point. In addition, the machines use the round-to-even rounding mode.
2. (缺点) Unfortunately, since the C standards do not re- quire the machine to use IEEE floating point, there are no standard methods to change the rounding mode or to get special values such as −0, +∞, −∞, or NaN.
3. Most systems provide a combination of include (.h) files and procedure libraries to provide access to these features, but the details vary from one system to an- other.
4. float, double 和 int 之间的相互转换！(没有unsigned) 因为unsigned没有负数，所以binary representation会有些不一致，会导致不必要的问题，实在要转换，可以先 int ？也要防止 overflow

### summary
1 区分 overflow 和 underflow， underflow是floating 才有的 接近0 round to 0. int只有 overflow
2. usigned signed 有交换律，floating没有
3. signed ， ~x + 1 = - x

