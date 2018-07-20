#include<stdio.h>
int a;
static int a;
int main()
{
   static int  a=8;
    printf("%d\n",a);

}

