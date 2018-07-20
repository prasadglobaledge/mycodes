#include<stdio.h>
#include<string.h>
main()
{
   
    int x;
    char str[100];
    char str1[100];

    fgets(str,50,stdin);
    fgets(str1,50,stdin);

    x=strcmp(str,str1);
    printf("%d\n",x);
    
   
}
