/* $begin show-bytes */
#include <stdio.h>
/* $end show-bytes */
#include <stdlib.h>
#include <string.h>
/* $begin show-bytes */

// 这个是用来表示 地址 十六进制的字符串，使用 unsigned 应该是为了可移植性
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
    // 按照每个字节对应的十六进制数进行打印，一个字节8位，就是两位的十六进制数
	    printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

// 调用时，第一个参数，是直接取变量的地址，并且被强制转换为了 btye_pointer类型
// 经过自己的实验，这里我们可以用 %p 直接打出变量所在的地址，只不过作者利用casting把他变成unsinged char *类型再用 %.2x 打印
void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float)); //line:data:show_bytes_amp2
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *)); //line:data:show_bytes_amp3
}
/* $end show-bytes */


/* $begin test-show-bytes */
void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}
/* $end test-show-bytes */

void simple_show_a() {
/* $begin simple-show-a */
int val = 0x87654321;
byte_pointer valp = (byte_pointer) &val;
show_bytes(valp, 1); /* A. */
show_bytes(valp, 2); /* B. */
show_bytes(valp, 3); /* C. */
/* $end simple-show-a */
}

void simple_show_b() {
/* $begin simple-show-b */
int val = 0x12345678;
byte_pointer valp = (byte_pointer) &val;
show_bytes(valp, 1); /* A. */
show_bytes(valp, 2); /* B. */
show_bytes(valp, 3); /* C. */
/* $end simple-show-b */
}

void float_eg() {
  int x = 3490593;
  float f = (float) x;
  printf("For x = %d\n", x);
  show_int(x);
  show_float(f);

  x = 3510593;
  f = (float) x;
  printf("For x = %d\n", x);
  show_int(x);
  show_float(f);

}

void string_ueg() {
/* $begin show-ustring */
const char *s = "ABCDEF";
show_bytes((byte_pointer) s, strlen(s)); 
/* $end show-ustring */
}

void string_leg() {
/* $begin show-lstring */
const char *s = "abcdef";
show_bytes((byte_pointer) s, strlen(s)); 
/* $end show-lstring */
}

void show_twocomp() 
{
/* $begin show-twocomp */
    short x = 12345; 
    short mx = -x; 
    
    show_bytes((byte_pointer) &x, sizeof(short)); 
    show_bytes((byte_pointer) &mx, sizeof(short)); 
/* $end show-twocomp */
}

int main(int argc, char *argv[])
{
    int val = 12345;
    
    // 注意这里，如果要调用 test_show_bytes 需要额外传入一个参数，随便一个都行，然后后面的就不会调用了
    if (argc > 1) {
	if (argc > 1) {
	    val = strtol(argv[1], NULL, 0);
	}
	printf("calling test_show_bytes\n");
	test_show_bytes(val);
    } else {
	printf("calling show_twocomp\n");
	show_twocomp();
	printf("Calling simple_show_a\n");
	simple_show_a();
	printf("Calling simple_show_b\n");
	simple_show_b();
	printf("Calling float_eg\n");
	float_eg();
	printf("Calling string_ueg\n");
	string_ueg();
	printf("Calling string_leg\n");
	string_leg();
    }
    return 0;
}
