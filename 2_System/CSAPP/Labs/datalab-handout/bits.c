/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * Name: XieXun
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
// Time1: 2020/12/01 18:00-20:00
// Time2: 2020/12/02 08:00-12:00
// Time3: 2020/12/02 12:30-14:00
//
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    // 目的是用 & 和 ~ 表达 异或
    // ~(x & y) & (x | y) = ~(x & y) & ~(~x & ~y)
    // x = 1, y = 1, result = 0
    // x = 1, y = 0, result = 1
    // x = 0, y = 1, result = 1
    // x = 0, y = 0. result = 0
    return ( ~(x & y) & ~(~x & ~y) );
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    // 100...00 = 1 << 31
  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    // Tmax = 01...11
    // Tmax + Tmax = 11...10
    return (x + x) + 3;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    // if x = 101010...10
    // sum = x + x = 0101...100
    // sum ^ x = 111...110
    return ~( ( x + x ) ^ x);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    // ~x + 1 = -x
    return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    // 0x30          0x39
    // 0011 0000     0011 1001
    // 48            57
    // 0             9
    // 0-9 / 10 = 0
    // 6-15 >> 3 = 0
    // 0 - 5???
    // 0-9 * 1.6 / 16
    // 0-9 * 0.8 / 8
    // 6->0110
    // -5-4 = 11...11 1011 | 0100
    // -x = x
    //
    //  0-9 >> 4 = 0
    //  6-15 >> 4 = 0
    //  
    //  10-15 >> 4 = 1, but 16-21 >> 4 = 1
    //  -6--1 >> 4 = -1, 0-5 >> 4 = 0
    //
    //  test: 10
    //  (x - 48) >> 4
    //  (x - 42) >> 4
    return !( (x + ~48 + 1) >> 4 | (x + ~42 + 1) >> 4 );
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    // apply !x to make it 0 or 1
    // and also !!x to make it 1 or 0
    // then, if shift right by 32 bits, one number is 0
    // if shift right by 0, one number will not change
    // 1 << 31 >> 26 = -32
    // 0 << 31 >> 26 = 0
    // -x = ~x + 1
    // so the code is below
    return ( y >> ( ~( !x << 31 >> 26 ) + 1 ) ) + ( z >> ( ~( !!x << 31 >> 26 ) + 1 ) );
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    // ~x + 1 + y = y - x >= 0 
    // >=0 means sign bit is 0
    // >>31 = 0
    return !( (~x + 1 + y) >> 31 );
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    // (-x >> 31) & (x >> 31), which man make all the bits are 1 except the x = 0;
    // ~ ( (-x >> 31) & (x >> 31) ) + 1, get the results
    return  ~( ( ~(~x + 1) >> 31) & (x >> 31) ) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
// 本题解题时，参考了网上的思路，不是纯个人所做
// 逐步移位比较确定返回值
// website: https://zhuanlan.zhihu.com/p/59534845
int howManyBits(int x) {
    // f(12) = 5 = 0 1100
    // f(298) = 10 = 01 0010 1010
    // f(-5) = 4 = 1011
    // f(0) = 1 = 0
    // f(-1) = 1 = 1
    // f(0x80000000) = 32 =  1000 00...00

    // positive case, the minimum number is
    //  12 / 16 = 0 --> 4 bits, + 1 sign bit = 5 bits
    //  298 / 512 = 0 --> 9 bits, + 1 sign bit = 10 bits
    //  16 / 16 = 1 ->> 5 bits, + 1 sign bit = 6 bits
    //  8-15 = 5 bits   --> 1000-1111
    //  16-31 = 6 bits  --> 1 0000---1 1111
    //  so the target is the location of significant bit 1, finally plus 1
    //
    //  negative case, the minimum number is 
    //  -5 = 1011, 0 in thid bit
    //  -1 = 1, 0 in zeroth bit
    //  -5 -- -8 = 1011 -- 1000. 1 in fourth bit
    //  so the target is the location of the sign bit
    
    // comparison of positive and negative
    // 9  = 0 1001
    // -9 = 1 0001
    // 1  = 0 1
    // -1 =   1
    // 2  =  0 10
    // -2 =  1 0
    // 3  =  0 11
    // -3 =  1 01
    //
    // x and ~x have same bits

    // what we need: 
    // 1. distinguish three cases 0, positive, negtive
    // 2. find the significant bit 1 for positive, finally plus 1
    // 3. find the sign bit for negative (find the largest 0 bit in valid bits plus 1)
    
    // negative convert to positive
    // -5 = 1011 -> ~(-5) = 00...00 0100
    // 5  = 0101 -> ~(5)  = 11...11 1010
    // 4 =  0100 -> ~(4) =  11...11 1011
    // -4 =  100 -> ~(-4) = 00...00 0011

    int sign = x >> 31;
    // if x = negative, transfer to positive
    x = ( x >> ( ~( sign << 31 >> 26 ) + 1 ) ) + ( ~x >> ( ~( !sign << 31 >> 26 ) + 1 ) );
    
    // start to find the leftmost 1
    int left16 = !!(x >> 16) << 4;
    x = x >> leftmost;
    left8 = !!(x >> 8) << 3;
    x = x >> leftmost;
    left4 = !!(x >> 4) << 2;
    x = x >> leftmost;
    left2 = !!(x >> 2) << 1;
    x = x >> leftmost;
    left1 = !!(x >> 1);
    x = x >> leftmost;
    left0 = x;

    return left16 + left8 + left4 + left2 + left1 + left0 + 0;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    // sign, exp, frac = 1, 8, 23
    // exp += 1
    // ( (uf >> 23 + 1) << 23 ) | ( (uf << 9) >> 9)
    unsigned int exp = uf << 1 >> 24;
    unsigned frac_left_most = uf << 9 >> 31;
    // Nan
    if ( ~exp == 0 && (uf << 9 >> 9) != 0 )
        return uf;
    // what if uf is the representation of the largest denormalized value?
    // when it is multiplied 2, the normalized value will have implied leading !
    // when exp are all 0s, and the frac's significant bit is 1, the result will be normalized value
    // just shift left 1 bit to frac as if it is a 12 bits representation (discard the leftmost 1). and add 1 to exp field
    if (exp == 0 && frac_left_most)
        return uf >> 31 << 31 & (uf << 1);
    // other cases
    return ( ( uf >> 23) + 1) << 23 | ( uf << 9 >> 9);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    // infinity and Nan
    unsigned int sign = uf >>31;    // 0 or 1
    unsigned int exp = uf << 1 >> 24;
    unsigned int shift = exp - 127;     // shift = exp - bias when normal value, shift = 1 - bias when denormal value (but it is to return 0)
    unsigned int frac = uf << 9 >> 9;   // 23 bits
    
    // larger than range
    if ( shift >= 32 )
        return 0x80000000u;
    // too small to round to 0
    if (shift <= 0)    
        return 0;
    // positive
    if (!sign)
        return frac << shift;
    // negative
    if (sign)
        return -frac;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    // E = 1 - 127 = -126, smallest frac = 000...001 = 2^-23
    if (x < -149)
        return 0;
    // E = 254 - 127 = 127;
    if (x > 127)
        return 255 << 23;
    // denormalized value
    // 1 - Bias = 1 - 127 = -126
    if ( x < -126 )
        return 1 << 22 >> -(x + 127);
    // normalized value
    return x << 23;
}
