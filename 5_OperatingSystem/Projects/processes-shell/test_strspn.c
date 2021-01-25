/*************************************************************************
 @Author: XieXun
 @Created Time : Wed  6 Jan 10:13:31 2021
 @File Name: test_strspn.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <string.h>
// /*
int main()
{
    const char * dst = "abdf123!@#$%^&*";
    const char * src = "bc";
    printf("%zu\n", strspn(dst, src));
}
// */
/*
int main(void)
{
    const char *string = "abcde312$#@";
    const char *low_alpha = "qwertyuiopasdfghjklzxcvbnm";
 
    size_t spnsz = strspn(string, low_alpha);
    printf("After skipping initial lowercase letters from '%s'\n"
           "The remainder is '%s'\n", string, string+spnsz);
}
*/
