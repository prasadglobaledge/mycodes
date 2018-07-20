#include<stdio.h>
#include<stdlib.h>
int fun();
int main(void)
{
	int *num0 = NULL;
	int num1;
	int num2=2;
	int num3=3;
    //int *ptr = NULL;

	num3=num1+num2;
    *num0 = 12;
    printf("%d\n", num3);
    fun();
	return 0;
}
int fun()
{
    int *ptr = NULL;

    ptr = 10;
    printf("%p\n",*ptr);
    return 0;
}
