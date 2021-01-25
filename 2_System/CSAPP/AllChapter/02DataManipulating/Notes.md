### Web Aside: DATA:TMin
1. in C, we must write - INT_MAX - 1 to represent INT_MIN! 
2. **When the compiler encounters a number of the form -X, it first determines the data type and value for X and then negates it.**

### Web Aside: Two's-comlement Negation in bit-level
1. ~x + 1

# Introduction
1. three most important representations of numbers. 
    * Unsigned encoding, used to represent unsiged value
    * Two's-complement encoding, used to represent signed value
    * Floating-point encoding, used to reprent floating value
2. Overflow
3. Integer computer arithmetic, support associative(交换律)
4. Floating-point arithmetic, cannot support associative(交换律)
5. differnce of mathematical properties between integer and floating arithmetic is from the difference of representation. Integer can only represent small range of value, but precisely. Floating can represent a large range of values, but approximately
6. bit-level representation and operations to manipulate arithmetic
7. All above is essential for portability of the pragram in wide range of machine. And they are also useful when we study next chapter

How to read this chapter!
the principle is very useful and it is also a conclusion for what we are learning.



# 2.1 Information Storage
#### Introduction
1. bytes (8 bits) is the smallest addressable unit of memory.
2. virtual memory: memory that is a very large array of bytes viewed by A machine-level program
3. address and virtual address space: Every byte of memory is identified by a unique number, known as its address, and the set of all possible addresses is known as the virtual address space.
4. Various mechanisms are used to allocate and manage the storage for different parts of the program. This management is all performed within the virtual address space.


### 2.1.1 Hexadecimal Notation
1. conversion between decimal, binary and hexadecimal

### 2.1.2 Data Sizes
1. word size: indicate the nominal size of pointer date
2. (maximum size of the virtual address space is determined by word size!) Since a virtual address is encoded by such a word, the most important system parameter determined by the word size is the maximum size of the virtual address space. 
3. (example, because max decimal value represented by word-size bits is 2^w, so the virtual address space is computed as following) That is, for a machine with a w-bit word size, the virtual addresses can range from 0 to 2w − 1, giving the program access to at most 2w bytes.
4. we can simulate the compilation in 32-bit machine environment although we are using a 64-bit computer
```
gcc -m32 prog.c
```
5. the bit we choose also determine the length of some data type, such as long, pointer, etc.
6. some defined and fixed length of data type in C/C++, int32_t and int64_t, etc.

### 2.1.3 Addressing and Byte Ordering
1. we can find the detail virtual space of a variable in C program. A multi-byte object is stored as a contiguous sequence of bytes.
2. ordering the bytes representing an object. two types: little endian and big endian. the differenc is the significant byte is at the beginning or the end

**byte ordering would be a problem in following three cases**
3. byte ordering is not a problem for one-machine programmer, but being an issue when communicate over network between different machines.
4. byte ordering can also be a probelm when representing integer data which is discussed in machine-level program(Chapter3)
5. byte ordering can also arise in casting in C program.

6. Figure 2.4 Code for show the byte in C program. Pointer to other type is casted to pointer to char. so we can see the each byte of other type represented by hexadecimal. This cast indicates to the compiler that the program should consider the pointer to be to a sequence of bytes rather than to an object of the original data type. (Mac OS and Linux are little endian form)


### 2.1.4 Representing Strings
ASCII

### 2.1.5 Representing Code
1. Different machine types use different and incompatible instructions and encodings. Hence are not binary compatible.
2. A fundamental concept of computer systems is that a program, from the perspective of the machine, is simply a sequence of bytes.

### 2.1.6 Introduction to Boolean Algebra
1. We can extend the four Boolean operations to also operate on bit vectors, strings of zeros and ones of some fixed length w.
2. mask

### 2.1.7 Bit-Level Operations in C
1. masking operation: apply mask and bit operations to maniplulate the target binary representation

### 2.1.9 Shift Operations in C
1. shift operation is performed from left to right
2. only one form of left shift, just filling right end with 0
3. but there are two forms of right shift for usigned value and signed value respectively
    * Logical: just filling the left end with zero
    * Arithmetic: filling the left end with value same as the most significan bit (because signed value need the significant bit to represent positive and negative value, introduced in later section)
4. although not every machine can ensure the above right shift assumption, but we assume it (and nearly all machines do like this)
5. final mention: in C, the precedence of shift operations are even lower than +, -.







# 2.2 Integer Representations
### 2.2.2 Unsigned Encodings
1. $ B2U_w $: function to evulate a unsigned value from binary representation
2. **( P92 Function(2.1) )** principle: Definition of unsigned encoding
3. range of the usigned encoding: 0 - $ 2^w - 1 $
4. principle: Uniqueness of unsigned encoding: Function $ B2U_w $ is a bijection. Which means one-to-one relation


### 2.2.3 Two’s-Complement Encodings
1. $ B2T_w $: function to evulate a signed value from binary representation 
2. This is defined by interpreting the most significant bit of the word to have negative weight.
3. **( P93 Function(2.3) )** principle: Definition of two’s-complement encoding
4. The most significant bit $ x_{w−1} $ is also called the sign bit. Its “weight” is $ −2^{w−1} $, the negation of its weight in an unsigned representation. When the sign bit is set to 1, the represented value is negative, and when set to 0, the value is nonnegative.
5. $ TMin = -2^{w-1} $ which is represented by [10...0], and $ TMax = w^{w-1} - 1$ which is represneted by [01...1]
6. principle: Uniqueness of two’s-complement encoding. Function $ B2T_w $ is a bijection (same as unsigned encoding)


**relationship between two encoding**
* All of the bit patterns that denote negative numbers in two’s-complement notation become positive values in an unsigned representation.
* UMax = 2TMax + 1

## 2.2.4 Conversions between Signed and Unsigned
1. the effect of casting is to keep the bit values identical but change how these bits are interpreted.
2. In C program, the numeric values might change, but the bit patterns do not.
3. $ T2U $: describes the conversion of a two’s- complement number to its unsigned counterpart
4. **( P101 Fcuntion (2.5) )** principle: Conversion from two’s complement to unsigned
5. **( Function (2.6) )** the principle conversion can also be represented as:
<font size=7>$$
B2U_w(T2B_w(x)) = T2U_w(x) = x + x_{w-1}2^w
$$</font>
6. **( P102 Function(2.7) )** principle: Unsigned to two’s-complement conversion
7. **( Function(2.8) )** the principle conversion can also be represented as:
<font size=7>$$
U2T_w(u) = -u_{w-1}2^w + u
$$</font>


### 2.2.5 Signed versus Unsigned in C
1. C will cast the signed value to be unsigned value when they are mixed together in expression

### 2.2.6 Expanding the Bit Representation of a Number
1. To convert an unsigned number to a larger data type, we can simply add leading zeros to the representation; this operation is known as zero extension, expressed by the following principle:
    principle: Expansion of an unsigned number by zero extension
2. For converting a two’s-complement number to a larger data type, the rule is to perform a sign extension, adding copies of the most significant bit to the representation, expressed by the following principle.
    principle: Expansion of a two’s-complement number by sign extension
3. in C, when we need to change the signed to unsigned AND change the size (length) of type. It will firstly change the data size and then change the signed to unsigned


### 2.2.7 Truncating Numbers
1. **( P110 )**principle: Truncation of an unsigned number
2. The intuition behind this principle is simply that all of the bits that were truncated have weights of the form $ 2^i $, where i ≥ k, and therefore each of these weights reduces to zero under the modulus operation.
3. the principle truncation can also be represented as
    Applying the modulus operation ( mod $ 2^k $ ) to Equation 2.1. where k is the size of bits after truncation

4. A similar property holds for truncating a two’s-complement number, except that it then converts the most significant bit into a sign bit
5. **(P111)** principle: Truncation of a two’s-complement number. First truncate just like unsigned encoding, then apply function $ B2U_k $ to the result from former

**Summary**
* (P111 Function(2.9))
* (P111 Function(2.10))

### 2.2.8 Advice on Signed versus Unsigned
1. implicit conversion can easily lead to bugs and errors







# 2.3 Integer Arithmetic
### 2.3.1 Unsigned Addition
1. (Overflow) This continued “word size inflation” means we cannot place any bound on the word size required to fully rep- resent the results of arithmetic operations.
2. operator + : define the result of truncting the integer sum x + y to be w bits long and then viewing the result as an unsigned number.
3. this operator can be viewed as sum modulo $ 2^w $, which means discarding any bits with weight greater tan $ 2^{w-1} $ in the bit-level representation of x + y
3. **( P116 Function(2.11) )** principle: Unsigned addition
4. An arithmetic operation is said to overflow when the full integer result cannot fit within the word size limits of the data type.

5. principle: Detecting overflow of unsigned addition
    if x + y >= x or x + y >= y, it means the result is not overflow. Otherwise, it means the result is overflow, because the result becomes $ x + y - 2^w $
6. **( P118 Function(2.12) )** principle: Unsigned negation
    on the bit-level operation, it just like negation in bit representation. except 0, because the negation of 0 is 0!

### 2.3.2 Two’s-Complement Addition
1. **( P119 Function(2.13) )** principle: Two’s-complement addition
2. **( P120 Function(2.14) )**Since two’s-complement addition has the exact same bit-level representation as unsigned addition, we can characterize the operation +tw as one of converting its arguments to unsigned, performing unsigned addition, and then converting back to two’s complement

3. ( P121 ) principle: Detecting overflow in two’s-complement addition: if x > 0, y > 0, the result <= 0 . or x < 0, y < 0, the result >= 0. theses two cases mean overflow happened in operation.


### 2.3.3 Two’s-Complement Negation
1. **( P124 Function(2.15) )** principle: Two’s-complement negation: That is, for w-bit two’s-complement addition, TMin is its own additive inverse, while any other value x has −x as its additive inverse.
2. There are several clever ways to determine the two’s-complement negation of a value represented at the bit level. But I just want to mention one that is important in C programming **-x == ~x + 1**


### 2.3.4 Unsigned Multiplication
Truncating an unsigned number to w bits is equivalent to computing its value modulo $ 2^w $, giving the following:
**( P126 Fuction(2.16) )**principle: Unsigned multiplication
<font size=7>$$
x * y = ( x · y ) mod 2^w
$$</front>

### 2.3.5 Two’s-Complement Multiplication
1. Truncating a two’s-complement number to w bits is equivalent to first computing its value modulo $ 2^w $ and then converting from unsigned to two’s complement, giving the following
**( P126 Function(2.17) )** principle: Two’s-complement multiplication
<font size=7>$$
x * y = U2T_w( ( x · y ) mod 2^w )
$$</front>

2. principle: Bit-level equivalence of unsigned and two’s-complement multipli- cation


### 2.3.6 Multiplying by Constants
1. integer multiplication instruction is lower than integer operation(addtion, subtraction, bit-level operaions and shifting).
2. As a consequence, one important optimization used by compilers is to attempt to replace multiplications by constant factors with combinations of shift and addition operations.

3. principle: Unsigned multiplication by a power of 2, by using shift left
4. principle: Two’s-complement multiplication by a power of 2, the same as that of unsigned multiplication
**above two operation cannot guarantee no happening of overflow, if it happens, it will truncate as usual**

5. (details need to read book P131)C compilers try to remove many cases where an integer is being multiplied by a constant with combinations of shifting, adding, and subtracting.

### 2.3.7 Dividing by Powers of 2
1. integer division is even slower than integer multiplication
2. The two different right shifts—logical and arithmetic—serve this purpose for unsigned and two’s-complement numbers, respectively.
**rounding is very important when operate on integer division!!!**
3. principle: Unsigned division by a power of 2, just shift right, x >> k yields the value ⌊x/2k⌋

**rounding in Two's-complement is complex because we have two sign, so there are round down and round up. When the result is positive, we need to round down. When the result is negative we need to round up (the result need to be rounded forward to 0!)**
4. principle: Two’s-complement division by a power of 2, rounding down, this is the simple case, because it is same as the unsigned encoding.

5. principle: Two’s-complement division by a power of 2, rounding up, this is complex, we need more technique to round up.
Let C variables x and k have two’s-complement value x and unsigned value k, respectively, such that 0 ≤ k < w. The C expression (x + (1 << k) - 1) >> k, when the shift is performed arithmetically, yields the value ⌈x/2k⌉.
6. bias: We can correct for the improper rounding that occurs when a negative number is shifted right by “biasing” the value before shifting.
7. as you can see in principle, the expresiion (1 << k) - 1 is the bias. which means we need to add 11...11 which the number of 1 is k - 1. add this binary representation to x which can guarantee round up.

8. **Summary two cases in one expression in C,  (x<0 ? x+(1<<k)-1 : x) >> k**


### 2.3.8 Final Thoughts on Integer Arithmetic
1. **the essence in integer arithmetic in computer is a form of modular arithmetic**
2. remember **Overflow**






# 2.4 Floating Point
1. A floating-point representation encodes rational numbers of the form $ V = x * 2^y $.
2. issue of rounding
3. mathematical properties of floating point, which is not complete as integer value (because it approximate a value , not so precisely)

### 2.4.1 Fractional Binary Numbers
### 2.4.2 IEEE Floating-Point Representation
1. The IEEE floating-point standard represents a number in a form $ V = (−1)^s × M × 2^E $:
    * The sign s determines whether the number is negative (s = 1) or positive (s = 0), where the interpretation of the sign bit for numeric value 0 is handled as a special case.
    * The significand M is a fractional binary number that ranges either between 1 and 2 − ε or between 0 and 1 − ε.
    * The exponent E weights the value by a (possibly negative) power of 2.
2. The bit representation of a floating-point number is divided into three fields to encode these values:
    * The single sign bit **s** directly encodes the sign s.
    * The k-bit exponent field **exp** = $ e_{k−1} . . . e_1e_0 $ encodes the exponent E.
    * The n-bit fraction field **frac** = $ f_{n−1} . . . f_1f_0 $ encodes the significand M , but the value encoded also depends on whether or not the exponent field equals 0.


3. The value encoded by a given bit representation can be divided into three different cases (the latter having two variants), depending on the value of **exp**.

**Mention: the bias is easily to be forgot to be minumsed from the exp value**
##### Case 1: Normalized Values
**used to represent the normal value which is not too small near the 0, nor too big to overflow**
1. This is the most common case. It occurs when the bit pattern of **exp** is neither all zeros (numeric value 0) nor all ones.

**exp**
2. **(bias, this bias is different from that above, but is also very important)the exponent field is interpreted as representing a signed integer in biased form**
3. exponent value is E = e − Bias, where e is the unsigned number having bit representation $ e_{k−1} . . . e_1e_0 $  and Bias is a bias value equal to $ 2^{k−1} − 1 $ (127 for single precision and 1023 for double).

**frac**
4. The fraction field **frac** is interpreted as representing the fractional value f , where 0 ≤ f < 1, having binary representation 0.$ f_{n−1} . . . f_1f_0 $
5. **(the reason to add 1 need to read book carefully and think deeply, basic reason is avoid the duplicate of representation between Normal case with Denormalized case) The significand is defined to be M = 1 + f . implied leading 1 representation, we can view M to be the number with binary representation 1.$ f_{n−1} . . . f_1f_0 $**



##### Case 2: Denormalized Values:
**used to represent the value which is near 0**
1. exponent field is all zeros
2. exponent value is E = 1 − Bias
3. significand value is M = f, value of the fraction field without an implied leading 1
4. Purpose of Denormalized Values:
    * provide a way to represent numeric value 0, since with a normalized number we must always have M ≥ 1, and hence we cannot represent 0. Meanwhile there are two 0! when sign bit is 0, it means +0, when sign bit is 1, it means -0.
    * A second function of denormalized numbers is to represent numbers that are very close to 0.0. They provide a property known as gradual underflow in which possible numeric values are spaced evenly near 0.0.



##### Case 3: Special Values
**used to represent infinity and null value**
1. exponent field is all ones
2. When the fraction field is all zeros, the resulting values represent infinity, either +∞ when s = 0 or −∞ when s = 1.
3. Infinity can represent results that overflow, as when we multiply two very large numbers, or when we divide by zero.

4. When the fraction field is nonzero, the resulting value is called a NaN , short for "not a number."
5. Such values are returned as the result of an operation where the result cannot be given as a real number or as infinity, as when computing $ \sqrt{-1} $ or $ \infin - \infin $, They can also be useful in some applications for representing uninitialized data.


###2.4.3 Example Numbers
1. smallest Normalized value is next to largest Denormalized value
2. ( read book for detail P148, there is some relationship between integer binary represention and floating binary representation )One useful exercise for understanding floating-point representations is to con- vert sample integer values into floating-point form.

### 2.4.4 Rounding
1. we need to approximate floating representation to represent the value wo want to store.
2. **Round-to-even: we need to ensure the least sigificant bit is an even number if the value is the average between the precise representation of floating represnetation**
example:
1.52 -> 1.5
1.56 -> 1.6
1.55 -> 1.6
0.0101-> 0.010 (base 2)
0.01011-> 0.011 (base 2)


### 2.4.5 Floating-Point Operations
1. **The lack of associativity in floating-point addition is the most important group property that is lacking**， It has important implications for scientific programmers and compiler writers.
2. ( compilter will not optimize the multiplication or divistion just like integer ) compilers have no way of knowing what trade-offs the user is willing to make between efficiency and faithfulness to the exact behavior of the original pro- gram. As a result, they tend to be very conservative, avoiding any optimizations that could have even the slightest effect on functionality.
3. **(floating-point addition satisfies the following monotonicity property, which cannot be applied to integer) if a ≥ b, then x + a ≥ x + b for any values of a, b, and x other than NaN.**
4. **This lack of associativity and distributivity is of serious concern to scientific programmers and to compiler writers. Even such a seemingly simple task as writing code to determine whether two lines intersect in three-dimensional space can be a major challenge.**


### 2.4.6 Floating Point in C
**avoid one case rounding, such as**
```
double a = 1.0;
float b = 1E20;
( b + a ) - b == a
```
the result of the last line is **false**, because when computer do a + b, it will round the sum of a, b to b!


# Summary
1. Converting large floating-point numbers to integers is a common source of programming errors.
