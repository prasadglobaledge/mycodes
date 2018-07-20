#include<stdio.h>
int main()
{
    char a[10] = {1,2,3,4,5,6,7,8,9,10};
    short int b;

    char *c = &b;
    *c = a[6];
    c++;
    *c = a[5];

    printf("%x\n",b);
    return 0;
}
