#include<stdio.h>
int add(int a,int b,int c)
{
    return (printf("%*c%*c%*c",a,' ',b,' ',c,' '));
}
int main()
{
    int a=2,b=3,c=4;

    printf("sum=%d\n",add(a,b,c));
    return 0;
}
