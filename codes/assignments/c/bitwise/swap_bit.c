#include<stdio.h>

int bit_swap(int,int,int);
void display(int);

int main()
{
	int number,s_pos,d_pos,res;

	printf("enter the number, source_pos, dest_pos\n");
	scanf("%d %d %d",&number,&s_pos,&d_pos);
	
	res=bit_swap(number,s_pos,d_pos);

 	printf("\nnumber after bit swapping is: %d\n",res);
}
int bit_swap(int number,int s_pos,int d_pos)
{
	int num1,num2;

	num1=number;
	num2=number;
	printf("\nnumber before bit swapping\n");
	display(number);
	num1=(number>>(s_pos-1))&1;
	num2=(number>>(d_pos-1))&1;

	if(num1==num2)
	{
		printf("\nnumber after swapping\n");
		display(number);
		return number;
	}
	else
	{
		number=(number^(1<<(s_pos-1)));
		number=(number^(1<<(d_pos-1)));
		printf("\nnumber after swapping\n");
		display(number);
		return number;
	}
}
void display(int number)
{
	int i;
	
	for(i=31;i>0;i--)
	{
		printf("%d",(number & (1<<(i-1)))?1:0);
	}
}
