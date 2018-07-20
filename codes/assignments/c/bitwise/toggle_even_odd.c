#include<stdio.h>

int even_bit_toggle(int num);
int odd_bit_toggle(int num);
void display(int);

int main()
{
	unsigned int num;
	int res1,res2;

	printf("enter the number\n");
	scanf("%d",&num);
	display(num);

	res1=even_bit_toggle(num);
	printf("\n number with even toggled bits\n");
	display(res1);
	res2=odd_bit_toggle(num);
	printf("\n number with odd toggled bits\n");
	display(res2);
}
int even_bit_toggle(int num)
{
	int i;

	for(i=1;i<=32;i=i+2)
	{
		num=num ^ (1<<i);
	}
	return num;
}
int odd_bit_toggle(int num)
{
	int i;

	for(i=0;i<32;i=i+2)
	{
		num=num ^ (1<<i);
	}
	return num;
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
