#include<stdio.h>
int main()
{
	 int a=3;
	 register int *b;
	int c;

	c=a;

//	b=&a;	
//	*b=10;
	printf("%p\n",&a);
//	printf("%p\n",b);
	printf("%d\n",a);
	printf("%d\n",c);
}
