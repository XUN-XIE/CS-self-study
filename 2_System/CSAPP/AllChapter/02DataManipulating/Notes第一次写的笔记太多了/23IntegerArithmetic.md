**以后如果需要判断overflow，可以直接按照书中的公式，写函数测试！！！这很重要**
**主要讨论的是 signed 和 unsigned 之间的 加减乘除，以及对应的位操作和 overflow 的关系！！！**
Many beginning programmers are surprised to find that adding two positive num- bers can yield a negative result, and that the comparison x < y can yield a different result than the comparison x-y < 0. These properties are artifacts of the finite na- ture of computer arithmetic. Understanding the nuances of computer arithmetic can help programmers write more reliable code.

### 2.3.1 Unsigned Addition
1. This continued “word size inflation” means we cannot place any bound on the word size required to fully rep- resent the results of arithmetic operations.
2. (定义新的函数符号 + ) Let us define the operation +uw for arguments x and y, where 0 ≤ x, y < 2^w, as the result of truncating the integer sum x + y to be w bits long and then viewing the result as an unsigned number.
3. This can be characterized as a form of modular arithmetic, computing the sum modulo 2w by simply discarding any bits with weight greater than 2 ^ w−1 in the bit-level representation of x + y
4. **(公式) We can characterize operation +uw as follows:  principle: Unsigned addition ： (如果，相加小于 2 的 位数次幂，正常计算。如果大于，就是 Overflow)**
5. In general, we can see that if x + y < 2w, the leading bit in the (w + 1)-bit represen- tation of the sum will equal 0, and hence discarding it will not change the numeric value. On the other hand, if 2w ≤ x + y < 2w+1, the leading bit in the (w + 1)-bit representation of the sum will equal 1, and hence discarding it is equivalent to subtracting 2w from the sum.
6. **(overflow定义) An arithmetic operation is said to overflow when the full integer result cannot fit within the word size limits of the data type.**
7. (C中 overflow 不会被标记为错误！) When executing C programs, overflows are not signaled as errors. At times, however, we might wish to determine whether or not overflow has occurred.
8. **principle: Detecting overflow of unsigned addition： 如果相加结果小于 x, 或 y，那么就发生了overflow！**
9. **(定义 取负数， unary - ) principle: Unsigned negation ： 如果 x = 0，取反还是 0. ！如果x > 0，那么取反就是 2 ^ w - x, 就是位数上限所表示的最大值(-1) 减去 x**

##### Aside Security vulnerability in getpeername (一个错误的系统调用函数的错误，值得阅读学习)


### 2.3.2 Two’s-Complement Addition
1. **(见公式) principle: Two’s-complement addition 分三个情况讨论！！！因为分 positive overflow 和 negative overflow, 比较类似于 unsigned 的情况， 如果上界超了，就减去 2^w，如果是下届，就加上 2^w!!!** 
2. The w-bit two’s-complement sum of two numbers has the exact same bit-level representation as the unsigned sum. In fact, most computers use the same machine instruction to perform either unsigned or signed addition.
3. 另一种计算方法是， 因为我们已经有 unsigned 和 signed 之间的转换关系公式，U2T, T2U。所以可以先 T2U, 用 unsigned 做加法，再 U2T
4. 这一系列讨论和推导，都是为了得出第一点的那个总结公式！！！
**最简单的理解，就是binary表示进行正常的加法，然后截取最后四位，依然用 Two's-Complement 方法计算出 值就好了**
5. **principle: Detecting overflow in two’s-complement addition**
ForxandyintherangeTMinw≤x,y≤TMaxw,lets=. x+twy.Thenthecompu- tation of s has had positive overflow if and only if x > 0 and y > 0 but s ≤ 0. The computation has had negative overflow if and only if x < 0 and y < 0 but s ≥ 0.
6. **derivation: Detecting overflow of two’s-complement addition**
Let us first do the analysis for positive overflow. If both x > 0 and y > 0 but s ≤ 0, then clearly positive overflow has occurred. Conversely, positive overflow requires (1) that x>0 and y>0 (otherwise, x+y < TMaxw) and (2) that s≤0 (from Equation 2.13). A similar set of arguments holds for negative overflow.


### 2.3.3 Two’s-Complement Negation
1. **principle: Two’s-complement negation 只有两种情况， 就是 x = TMin 时，并不会发生变化， x 仍然等于 TMin，其他都正常**
2. That is, for w-bit two’s-complement addition, TMinw is its own additive inverse, while any other value x has −x as its additive inverse.
3. **换个角度想，因为 TMin 比 TMax 多出来一个值！所以它不存在一个有限的数相加等于 0**
4. Observe that TMinw + TMinw = −2w−1 + −2w−1 = −2w. This would cause nega- tive overflow, and hence TMinw +tw TMinw = −2w + 2w = 0. For values of x such that x > TMinw, the value −x can also be represented as a w-bit two’s-complement number, and their sum will be −x + x = 0.

### Web Aside DATA:TNEG Bit-level representation of two’s-complement negation
**提出了两个理解 Two's-Complement Negation的方法，理解！**
1. One technique for performing two’s-complement negation at the bit level is to complement the bits and then increment the result. In C, we can state that for any integer value x, computing the expressions -x and ~x + 1 will give identical results.
2. A second way to perform two’s-complement negation of a number x is based on splitting the bit vector into two parts. Let k be the position of the rightmost 1, so the bit-level representation of x has the form [xw−1, xw−2, . . . , xk+1, 1, 0, . . . 0]. (This is possible as long as x ̸= 0.) The negation is then written in binary form as [~xw−1, ~xw−2, . . . ~ xk+1, 1, 0, . . . , 0]. That is, we complement each bit to the left of bit position k.


### 2.3.4 Unsigned Multiplication
1. Instead, unsigned multiplication in C is defined to yield the w-bit value given by the low-order w bits of the 2w-bit integer product.
2. principle: Unsigned multiplication. 相乘的结果，直接对 2^w 求余


### 2.3.5 Two’s-Complement Multiplication
1. Instead, signed multi- plication in C generally is performed by truncating the 2w-bit product to w bits.
2. Truncating a two’s-complement number to w bits is equivalent to first computing its value modulo 2^w and then converting from unsigned to two’s complement, giving the following:
3. principle: Two’s-complement multiplication. 先做一遍 unsigned 的过程，然后结果进行 U2T，就得到了 signed 的结果
4. We claim that the bit-level representation of the product operation is identical for both unsigned and two’s-complement multiplication, as stated by the following principle: principle: Bit-level equivalence of unsigned and two’s-complement multiplication 
**就是说在做完运算后， unsigned 和 two's-complement 的结果， 截取到原来operand的位数上后，是一样的！**
5. The bit- level representations of both truncated products are identical for both unsigned and two’s-complement multiplication, even though the full 6-bit representations differ.
6. **最后有个公式推导，又把前面某节的公式拿过来使用，然后推导证明出这节给出的公式是正确的！**


### 2.3.6 Multiplying by Constants
1. **(乘法比加减法，位操作费时) Historically, the integer multiply instruction on many machines was fairly slow, requiring 10 or more clock cycles, whereas other integer operations—such as addition, subtraction, bit-level operations, and shifting—required only 1 clock cycle.**
2. (编译器优化乘法操作) As a consequence, one important optimization used by compilers is to attempt to replace multiplications by constant factors with combinations of shift and addition operations.
3. principle: Multiplication by a power of 2 ,直接使用 shift left，就可以实现
4. principle: Unsigned multiplication by a power of 2。 
5. Since the bit-level operation of fixed-size two’s-complement arithmetic is equivalent to that for unsigned arithmetic, we can make a similar statement about the relationship between left shifts and multiplication by a power of 2 for two’s- complement arithmetic:
6. principle: Two’s-complement multiplication by a power of 2。
7. **Note that multiplying by a power of 2 can cause overflow with either unsigned or two’s-complement arithmetic. Our result shows that even then we will get the same effect by shifting.**
8. **编译器优化方法，把const数拆分成 2 次幂的加和，分别进行移位操作。Given that integer multiplication is more costly than shifting and adding, many C compilers try to remove many cases where an integer is being multiplied by a constant with combinations of shifting, adding, and subtracting.**
9. The two computations will yield the same result, regardless of whether x is unsigned or two’s comple- ment, and even if the multiplication would cause an overflow.
10. Even better, the compiler can also use the property 14 = 24 − 21 to rewrite the multiplication as (x<<4) - (x<<1), requiring only two shifts and a subtraction.
11. By adding together the results for each run, we are able to compute x * K with- out any multiplications. Of course, the trade-off between using combinations of shifting, adding, and subtracting versus a single multiplication instruction depends on the relative speeds of these instructions, and these can be highly machine de- pendent. Most compilers only perform this optimization when a small number of shifts, adds, and subtractions suffice.


### 2.3.7 Dividing by Powers of 2
1. **除法比乘法更慢！！！！！Integer division on most machines is even slower than integer multiplication— requiring 30 or more clock cycles.**
2. **(开始区分 逻辑右移 和 算术右移了。 unsigned逻辑右移，signed算术右移) The two different right shifts—logical and arithmetic—serve this purpose for unsigned and two’s-complement numbers, respectively.**
3. **(除法的结果总是向着 0 靠近的，所以round的时候，以靠近 0 为准则思考就可以了) For x ≥ 0 and y > 0, integer division should yield ⌊x/y⌋, while for x < 0 and y > 0, it should yield ⌈x/y⌉. That is, it should round down a positive result but round up a negative one.**
4. The case for using shifts with unsigned arithmetic is straightforward, in part because right shifting is guaranteed to be performed logically for unsigned values.
5. principle: Unsigned division by a power of 2 : For C variables x and k with unsigned values x and k, such that 0 ≤ k < w, the C expression x >> k yields the value ⌊x/2^k⌋.
6. The case for dividing by a power of 2 with two’s-complement arithmetic is slightly more complex. First, the shifting should be performed using an arithmetic right shift, to ensure that negative values remain negative. Let us investigate what value such a right shift would produce.
7. principle: Two’s-complement division by a power of 2, rounding down: Let C variables x and k have two’s-complement value x and unsigned value k, respectively, such that 0 ≤ k < w. The C expression x >> k, when the shift is performed arithmetically, yields the value ⌊x/2^k⌋.
8. **(针对负数情况的 signed 要注意有一个 bias 技巧)principle: Two’s-complement division by a power of 2, rounding up: Let C variables x and k have two’s-complement value x and unsigned value k, respectively, such that 0 ≤ k < w. The C expression (x + (1 << k) - 1) >> k, when the shift is performed arithmetically, yields the value ⌈x/2k⌉.**
9. **理解， 1 << k - 1，个人理解为是，在移位k之后的 最后一位假设原来位置为 pos！那么相当于对原数据的 pos 的右边都填上了1 ！ 因为 k = pos, 1 << k - 1，就相当于 pos 右边全是 1， pos 为 0。 这样做的目的，思考： 如果原始数据中 pos 右边 存在 1 ！那么经过这个 + 1 << k - 1。就会让右边逐步进位，到 pos 上也要进 1 !!! 最后执行 k 右移，相当于让结果 + 1 ! 实现 round up**
10. The biasing technique exploits the property that ⌈x/y⌉ = ⌊(x + y − 1)/y⌋ for integers x and y such that y > 0.
11. **These analyses show that for a two’s-complement machine using arithmetic right shifts, the C expression**
```
(x<0 ? x+(1<<k)-1 : x) >> k
```
12. **(division 不支持 multiplication 那样的拆分使用 位操作和加减操作) We now see that division by a power of 2 can be implemented using logical or arithmetic right shifts. This is precisely the reason the two types of right shifts are available on most machines. Unfortunately, this approach does not generalize to division by arbitrary constants. Unlike multiplication, we cannot express division by arbitrary constants K in terms of division by powers of 2.**


### 2.3.8 Final Thoughts on Integer Arithmetic
1. **(计算机整数计算的本质还是一个求余的过程)As we have seen, the “integer” arithmetic performed by computers is really a form of modular arithmetic. The finite word size used to represent numbers limits the range of possible values, and the resulting operations can overflow.**
2. We have also seen that the two’s-complement representation provides a clever way to represent both negative and positive values, while using the same bit-level implementations as are used to perform unsigned arithmetic—operations such as addition, subtraction, multiplication, and even division have either identical or very similar bit-level behaviors, whether the operands are in unsigned or two’s- complement form.
3. We have seen that some of the conventions in the C language can yield some surprising results, and these can be sources of bugs that are hard to recognize or understand. We have especially seen that the unsigned data type, while conceptu- ally straightforward, can lead to behaviors that even experienced programmers do not expect. We have also seen that this data type can arise in unexpected ways—for example, when writing integer constants and when invoking library routines.






