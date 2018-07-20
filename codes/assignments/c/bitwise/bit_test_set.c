#include<stdio.h>

#define bit_ts(num,pos) ((num & (1<<(pos-1)))?num:(num | (1<<(pos-1))))
void display(int num);
int main()
{
	int num,pos,res;

	printf("enter the number and position\n");
	scanf("%d %d",&num,&pos);
	printf("\n entered number is:\n");
	display(num);
	res=bit_ts(num,pos);
	printf("\n numbers after set _bit is:\n");
	display(res);
}
void display(int num)
{
	int i;

	for(i=31;i>0;i--)
	{
		printf("%d",(num & (1<<(i-1)))?1:0);
	}
	printf("\n");
}

