#include<stdio.h>
int main()
{
    float a[5]={1.1,1.2,1.3,1.4,1.5};
    int i=0;
    float *ptr;
    ptr=a;

    while(i<5)
    {
        printf("%p\n",ptr);
        printf("%lf\n",*ptr);
        ptr++;
        i++;
    }



}
