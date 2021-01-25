**重点在后面几节的 转换，expand，truncate部分**
**移位操作，左移没关系，都是填入0。右移要慎重了！！！**
## 2.2 Integer Representations
1. In this section, we describe two different ways bits can be used to encode integers— one that can only represent nonnegative numbers, and one that can represent negative, zero, and positive numbers.


### 2.2.1 Integral Data Types
1. Each type can specify a size with keyword char, short, long, as well as an indication of whether the represented numbers are all nonnegative (declared as unsigned), or possibly negative (the default.)
2. (负数特殊，因为他是从-1开始计数的) One important feature to note in Figures 2.9 and 2.10 is that the ranges are not symmetric—the range of negative numbers extends one further than the range of positive numbers. We will see why this happens when we consider how negative numbers are represented.
3. The C standards define minimum ranges of values that each data type must be able to represent.
4. **Both C and C++ support signed (the default) and unsigned numbers. Java supports only signed numbers.**


### 2.2.2 Unsigned Encodings
1. We can express this interpretation as a function B2Uw (for “binary to unsigned,” length w):
2. **(有公式，但是我懒得打，自己翻书)principle: Definition of unsigned encoding**，这个还是很简单的，就是对应每一位加权求和
3. **principle: Uniqueness of unsigned encoding：Function B2Uw is a bijection.**
4. The mathematical term bijection refers to a function f that goes two ways: it maps a value x to a value y where y = f (x), but it can also operate in reverse, since for every y, there is a unique value x such that f (x) = y.


# 2.2.3 Two’s-Complement Encodings(用于表达 signed 类型数据)
                                                               
1. For many applications, we wish to represent negative values as well. The most com- mon computer representation of signed numbers is known as two’s-complement form.
2. **This is defined by interpreting the most significant bit of the word to have negative weight.**
3. **(有公式)principle: Definition of two’s-complement encoding**，理解为最重要的位，最大位加权为负数，其余位加权求和相加，得到结果
4. The most significant bit x(w−1) is also called the sign bit. Its “weight” is −2^(w−1), the negation of its weight in an unsigned representation. When the sign bit is set to 1, the represented value is negative, and when set to 0, the value is nonnegative.
5. (range of Two's-Complement) Let us consider the range of values that can be represented as a w-bit two’s-complement number. The least representable value is given by bit vector [10 . . . 0] (set the bit with negative weight but clear all others), having integer value TMinw =. −2^(w−1(). The greatest value is given by bit vector [01 . . . 1] (clear the bit with negative weight but set all others), having integer value 2^(w−1) − 1.
6. **principle: Uniqueness of two’s-complement encoding: Function B2Tw is a bijection.**
7. We define function T2Bw (for “two’s complement to binary”) to be the inverse of B2Tw. That is, for a number x, such that TMinw ≤ x ≤ TMaxw, T2Bw(x) is the (unique) w-bit pattern that encodes x.
8. **A few points are worth highlighting about these numbers. First, as observed in Figures 2.9 and 2.10, the two’s-complement range is asymmetric: |TMin| = |TMax| + 1; that is, there is no positive counterpart to TMin.**
9. As we shall see, this leads to some peculiar properties of two’s-complement arithmetic and can be the source of subtle program bugs.
10. **This asymmetry arises because half the bit patterns (those with the sign bit set to 1) represent negative numbers, while half (those with the sign bit set to 0) represent nonnegative numbers.**
11. Since 0 is nonnegative, this means that it can represent one less positive number than negative.
12. **Second, the maximum unsigned value is just over twice the maximum two’s-complement value: UMax = 2TMax + 1. All of the bit patterns that denote negative numbers in two’s-complement notation become positive values in an unsigned representation.**
13. (关于 signed 类型在不同机器上，不一定使用 Two's-complement 方法) The C standards do not require signed integers to be represented in two’s- complement form, but nearly all machines do so. (所以可能有其他移植性问题) Programmers who are concerned with maximizing portability across all possible machines should not assume any particular range of representable values, beyond the ranges indicated in Figure 2.11, nor should they assume any particular representation of signed numbers. On the other hand, many programs are written assuming a two’s-complement representation of signed numbers, and the “typical” ranges shown in Figures 2.9 and 2.10, and these programs are portable across a broad range of machines and compilers.
14. (JAVA的一致性) The Java standard is quite specific about integer data type ranges and repre- sentations. It requires a two’s-complement representation with the exact ranges shown for the 64-bit case (Figure 2.10). In Java, the single-byte data type is called byte instead of char. These detailed requirements are intended to enable Java programs to behave identically regardless of the machines or operating systems running them.



#### Aside More on fixed-size integer types
1. (特定字节数的类型定义在 stdint.h 里)The ISO C99 standard introduces this class of integer types in the file stdint.h. This file defines a set of data types with declarations of the form intN_t and uintN_t, specifying N-bit signed and unsigned integers, for different values of N. The exact values of N are implementation dependent, but most compilers allow values of 8, 16, 32, and 64. Thus, we can unambiguously declare an unsigned 16-bit variable by giving it type uint16_t, and a signed variable of 32 bits as int32_t.
2. (特定字节数类型的range有宏定义)Along with these data types are a set of macros defining the minimum and maximum values for each value of N. These have names of the form INTN_MIN, INTN_MAX, and UINTN_MAX.
3. (特定字节数的类型在printf中打印使用的 符号 也有宏定义)Formatted printing with fixed-width types requires use of macros that expand into format strings in a system-dependent manner. So, for example, the values of variables x and y of type int32_t and uint64_t can be printed by the following call to printf: 
```
printf("x = %" PRId32 ", y = %" PRIu64 "\n", x, y);
```
When compiled as a 64-bit program, macro PRId32 expands to the string "d", while PRIu64 expands to the pair of strings "l" "u". When the C preprocessor encounters a sequence of string constants separated only by spaces (or other whitespace characters), it concatenates them together.

#### Aside Alternative representations of signed numbers
1. Ones’ complement. This is the same as two’s complement, except that the most significant bit has weight −(2^(w−1) − 1) rather than −2^(w−1)
2. (就是我之前一直以为的表达方法，第一位用来表示正负号，后面的用来计数)Sign magnitude. The most significant bit is a sign bit that determines whether the remaining bits should be given negative or positive weight
3. **We will see that sign-magnitude encoding is used with floating-point numbers.**
 

# 2.2.4 Conversions between Signed and Unsigned(重点内容，有符号和无符号数的转换)
1. What should be the effect of casting signed value to unsigned, or vice versa?
2. **On the other hand, converting a negative value to unsigned might yield zero.**
3. **Converting an unsigned value that is too large to be represented in two’s- complement form might yield TMax.**
4. **What we see here is that the effect of casting is to keep the bit values identical but change how these bits are interpreted. We saw in Figure 2.15 that the 16-bit two’s-complement representation of −12,345 is identical to the 16-bit unsigned representation of 53,191. Casting from short to unsigned short changed the numeric value, but not the bit representation.**
5. 解释第四点： 一个 类型(无论signed如何)，它的位数能表达的最大值的一半以内，都是可以随意转换。因为 signed type 和 unisigned type 表现形式一模一样。但是超出这个范围之后，如果发生了两者的转换！就会发生额外效果
6. **This is a general rule for how most C implementations handle conversions between signed and unsigned numbers with the same word size—the numeric values might change, but the bit patterns do not.**
7. (建立T2U和U2T函数，就是建立signed数和unsigned数的realtion) Now define the function T2Uw as T2Uw(x) =. B2Uw(T2Bw(x)). This function takes a number between TMinw and TMaxw and yields a number between 0 and UMaxw, where the two numbers have identical bit representations, except that the argument has a two’s-complement representation while the result is unsigned. Similarly, for x between 0 and UMaxw, the function U2Tw, defined as U2Tw(x) =. B2Tw(U2Bw(x)), yields the number having the same two’s-complement represen- tation as the unsigned representation of x.
8. We see, then, that function T2U describes the conversion of a two’s- complement number to its unsigned counterpart, while U2T converts in the op- posite direction. These describe the effect of casting between these data types in most C implementations.
9. **(有公式)principle: Conversion from two’s complement to unsigned**
10. derivation: Conversion from two’s complement to unsigned
11. **Figure 2.17 转换图解,As it shows, when mapping a signed number to its unsigned counterpart, negative numbers are con- verted to large positive numbers, while nonnegative numbers remain unchanged.**
12.**(有公式conversion back from Unsigned to signed) principle: Unsigned to two’s-complement conversion**

**总结：To summarize, we considered the effects of converting in both directions between unsigned and two’s-complement representations. For values x in the range 0 ≤ x ≤ TMaxw, we have T2Uw(x) = x and U2Tw(x) = x. That is, num- bers in this range have identical unsigned and two’s-complement representations. For values outside of this range, the conversions either add or subtract 2w. For example, we have T2Uw(−1) = −1 + 2w = UMaxw—the negative number clos- est to zero maps to the largest unsigned number. At the other extreme, one can see that T2Uw(TMinw) = −2w−1 + 2w = 2w−1 = TMaxw + 1—the most neg- ative number maps to an unsigned number just outside the range of positive two’s-complement numbers.**


### 2.2.5 Signed versus Unsigned in C
1. Generally, most numbers are signed by default.
2. **Adding character ‘U’ or ‘u’ as a suffix creates an unsigned constant; for example, 12345U or 0x1A2Bu.**
3. C allows conversion between unsigned and signed. Although the C standard does not specify precisely how this conversion should be made, most systems follow the rule that the underlying bit representation does not change. This rule has the effect of applying the function U2T w when converting from unsigned to signed, and T2Uw when converting from signed to unsigned, where w is the number of bits for the data type.
4. **test for C++ in my own code, the result is the same as that in C**
5. **(注意隐式转换！！！C会默认为 有符号转为无符号！！！) Some possibly nonintuitive behavior arises due to C’s handling of expres- sions containing combinations of signed and unsigned quantities. When an op- eration is performed where one operand is signed and the other is unsigned, C implicitly casts the signed argument to unsigned and performs the operations assuming the numbers are nonnegative.**
6. As we will see, this convention makes little difference for standard arithmetic operations, but it leads to nonintuitive results for relational operators such as < and >.
7. **所以说隐式转换有时候害人呐，不过这个特性既然存在肯定是有利有弊的，全靠程序员自己的自觉来防止问题的出现**


#### Web Aside DATA:TMIN    Wrting TMin in C
1. In Figure 2.19 and in Problem 2.21, we carefully wrote the value of TMin32 as -2,147,483,647-1. Why not simply write it as either -2,147,483,648 or 0x80000000? Looking at the C header file limits.h, we see that they use a similar method as we have to write TMin32 and TMax32:
```
/* Minimum and maximum values a ‘signed int’ can hold.  */
#define INT_MAX   2147483647
#define INT_MIN   (-INT_MAX - 1)
```
2. Although understanding this issue requires us to delve into one of the murkier corners of the C language standards, it will help us appreciate some of the subtleties of integer data types and representations.


# 2.2.6 Expanding the Bit Representation of a Number
1. One common operation is to convert between integers having different word sizes while retaining the same numeric value. Of course, this may not be possible when the destination data type is too small to represent the desired value. Converting from a smaller to a larger data type, however, should always be possible.
2. **(unsigned 小字节转大字节) To convert an unsigned number to a larger data type, we can simply add leading zeros to the representation; this operation is known as zero extension, expressed by the following principle: principle: Expansion of an unsigned number by zero extension**
3. **(signed 小字节转大字节，这个不太好理解，要多注意注意，是在左面多的位上全部填上原来最大位的数，如果是1，也全部填1 ！！！) For converting a two’s-complement number to a larger data type, the rule is to perform a sign extension, adding copies of the most significant bit to the representation, expressed by the following principle. principle: Expansion of a two’s-complement number by sign extension**
4. **可以用indcution证明上述的性质**
5.**(大小字节之间，unsigned 和 signed 之间当然不能保证这些性质了) One point worth making is that the relative order of conversion from one data size to another and between unsigned and signed can affect the behavior of a program.**
6. **(如果发生第五点提到的情况， first change the size and then the type) This shows that, when converting from short to unsigned, the program first changes the size and then the type. That is, (unsigned) sx is equivalent to (unsigned) (int) sx, evaluating to 4,294,954,951, not (unsigned) (unsigned short) sx, which evaluates to 53,191. Indeed, this convention is required by the C standards.**


# 2.2.7 Truncating Numbers
1. Suppose that, rather than extending a value with extra bits, we reduce the number of bits representing a number.
2. **(因为是unsigned，所以直接把前面的字节去掉就得到最终的binary表示的unsigned值)principle: Truncation of an unsigned number**
3. The intuition behind this principle is simply that all of the bits that were truncated have weights of the form 2i, where i ≥ k, and therefore each of these weights reduces to zero under the modulus operation.
4. A similar property holds for truncating a two’s-complement number, except that it then converts the most significant bit into a sign bit
5. **(截取signed数据和expand类似，将原binary里的sign bit全部替换到被截取的字节处即可) principle: Truncation of a two’s-complement number**
6. **书中使用 mod 求余的方式表达截取的，以 2^k 为除数，那么高于 k 位的1都会被转化为0(unsigned)。书中对signed表示的方式是，先对数据当作 unsigned 求余，然后调用 U2T 进行转换！**


### 2.2.8 Advice on Signed versus Unsigned
1. As we have seen, the implicit casting of signed to unsigned leads to some non- intuitive behavior. Nonintuitive features often lead to program bugs, and ones involving the nuances of implicit casting can be especially difficult to see. Since the casting takes place without any clear indication in the code, programmers often overlook its effects.
2. We have seen multiple ways in which the subtle features of unsigned arith- metic, and especially the implicit conversion of signed to unsigned, can lead to errors or vulnerabilities.
3. **(不要使用 unsigned 类型！！！) One way to avoid such bugs is to never use unsigned numbers. In fact, few languages other than C support unsigned integers.**
4. Appar- ently, these other language designers viewed them as more trouble than they are worth.
5. For example, Java supports only signed integers, and it requires that they be implemented with two’s-complement arithmetic. The normal right shift oper- ator >> is guaranteed to perform an arithmetic shift. The special operator >>> is defined to perform a logical right shift.
6. **(unsigned存在的意义！！！还是很有帮助的，一个是系统级的bool值，一个是数学库内的使用) Unsigned values are very useful when we want to think of words as just col- lections of bits with no numeric interpretation. This occurs, for example, when packing a word with flags describing various Boolean conditions. Addresses are naturally unsigned, so systems programmers find unsigned types to be helpful. Unsigned values are also useful when implementing mathematical packages for modular arithmetic and for multiprecision arithmetic, in which numbers are rep- resented by arrays of words.**

