/*************************************************************************
 @Author: XieXun
 @Created Time : Sat 28 Nov 13:17:51 2020
 @File Name: main.c
 @Description:
 ************************************************************************/

#include <stdio.h>

int main()
{
    // 直接想办法证明 都可能存在 false 的情况，用逻辑
    printf("Problem A: case 2, when x = INT_MIN, x > 0 , x - 1(underflow) > 0\n");
    // 因为是 || 所以左右两边都必须为 false
    // 左边相当于 x & 7 == 7, 所以 x = 7 
    // x << 29 < 0 说明, x 的第三位是 1，所以contradiction
    printf("Problem B: case 1， 必为正确的\n");
    
    // 存在一些数的平方，截取后，最高位为 1 即可小于0
    printf("Probelm C: case 2, 存在一些数的平方，截取后，最高位为 1 即可小于0\n");

    // 左面 false x >= 0
    // 右边 -x <= 0
    // 唯一的特殊情况就是 INT_MIN = INT_MIN, 但是不影响结果
    printf("Problem D: case 1\n");

    // x > 0 false, x <= 0
    // if x = INT_MIN,  -x = INT_MIN < 0, false
    printf("Problem E: case 2, when x = INT_MIN\n");
    
    printf("\n最后两题参考了答案，倒二是做错了，最后一题不记得 ~x 的表达了\n");
    printf("Problem F: case 2, unsigned and signed addition have the sanme bit representation!\n");

    // 
    printf("Problem G: case 1, ~y = - y - 1. 又因为 unsigned 和 signed 乘法 bit representation 相同，所以 x * y == ux * uy，所以相等\n");
}
