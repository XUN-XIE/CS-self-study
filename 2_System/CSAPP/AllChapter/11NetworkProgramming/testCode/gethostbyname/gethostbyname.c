/*************************************************************************
 @Author: XieXun
 @Created Time : Wed 20 Jan 09:38:06 2021
 @File Name: gethostbyname.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#include <netdb.h>
/*
struct  hostent {
             char    *h_name;         official name of host
             char    **h_aliases;     alias list 
             int     h_addrtype;      host address type
             int     h_length;        length of address
             char    **h_addr_list;   list of addresses from name server
     };
*/
int main()
{
    char *web = "xiexundeMBP";
    struct hostent *res = gethostbyname(web);
    printf("h_name = %s\n", res->h_name);
    printf("h_aliases:\n");
    for (int i = 0; res->h_aliases[i]; i++)
        printf("%s\n", res->h_aliases[i]);
    printf("\nh_addrtype = %d\n", res->h_addrtype);
    printf("h_length = %d\n", res->h_length);
    printf("h_addr_list:\n");
    for (int i = 0; res->h_addr_list[i]; i++)
        printf("%s\n", res->h_addr_list[i]);
}

