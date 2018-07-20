#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *ptr=NULL;

/*    ptr=(int *)malloc(5);
    if(ptr==NULL)
    {
        printf("MA failed\n");
        exit(1);
    }*/
    ptr=malloc(0);
    ptr="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
        printf("%s",ptr);
/*    *ptr = 0x1;
    printf("%d\n",*ptr);
    
    *ptr = 0x12;
    printf("%d\n",*ptr);
    
    *ptr = 0x123;
    printf("%d\n",*ptr);
    
    *ptr = 0x1234;
    printf("%d\n",*ptr);
    
    *ptr = 0x12345678;
    printf("%d\n",*ptr);*/
    
    
}
