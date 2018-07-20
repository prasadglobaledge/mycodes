#include<stdio.h>
int main()
{
	int value,i;

	printf("enter the value\n");
	scanf("%d",&value);

	for(i=31;i>=0;i--)
	{
		printf("%d",(value&(1<<i))?1:0);
		
	}
	return 0;
}
