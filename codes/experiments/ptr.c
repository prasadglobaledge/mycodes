#include<stdio.h>
int main()
{
   int a[10]={1,2,3,4,5,6,7};
   int *ptr;
   ptr=&a[0];
   printf("%p\n %p\n",ptr,&a);
   printf("%d %d\n",*(ptr+10),a[5]);
    
    
}
