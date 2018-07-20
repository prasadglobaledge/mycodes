#include<stdio.h>

int count_set_bits(int num);
int count_clear_bits(int num);
void display(int num);

int main()
{
	unsigned int num;
	int res1,res2;

	printf("enter the number\n");
	scanf("%d",&num);

	printf("entered number is :\n");
	display(num);
	
	res1=count_set_bits(num);
	printf("number of set bits are : %d\n",res1);
	
	res2=count_clear_bits(num);
	printf("number of clear bits are : %d\n",res2);
}
int count_set_bits(int num)
{
	int pos,temp,count=0;

	for(pos=1;pos<=32;pos++)
	{
		temp=num;
		temp=temp & (1<<(pos-1));
		temp=(temp>>(pos-1))&1;
		if(temp==1)
		{
			count++;
		}
	}
	return count;
}
int count_clear_bits(int num)
{
	int pos,temp,count=0;

	for(pos=1;pos<=32;pos++)
	{
		temp=num;
		temp=temp & (1<<(pos-1));
		temp=(temp>>(pos-1))&1;
		if(temp==0)
		{
			count++;
		}
	}
	return count;
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
