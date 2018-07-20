#include<stdio.h>
#define a b
#define b c
#define c a

int main()
{
	int a=10;
	int b=20;
	int c=30;
	
	printf("%d %d %d",a,b,c);
	return 0;
}
