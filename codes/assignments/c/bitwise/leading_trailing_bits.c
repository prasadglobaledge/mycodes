#include<stdio.h>
#include<stdlib.h>
 
int cnt_leading_set_bits(unsigned int num);
int cnt_leading_clear_bits(unsigned int num);
int cnt_trailing_set_bits(unsigned int num);
int cnt_trailing_clear_bits(unsigned int num);
void display(unsigned int num);

int main()
{
	unsigned int num;
	int ch,res;

	printf("enter the number and choice\n 1.leading_set 2.leading_clear 3.trailing_set 4.trailing_clear\n");
	scanf("%d %d",&num,&ch);

	printf("entered number is :\n");
	display(num);
	
	
	switch(ch)
	{
		case 1: res=cnt_leading_set_bits(num);
			printf("number of leading set bits : %d\n",res);
			break;
		case 2:	res=cnt_leading_clear_bits(num);
			printf("number of leading clear bits : %d\n",res);
			break;
		case 3: res=cnt_trailing_set_bits(num);
			printf("number of trailing set bits : %d\n",res);
			break;
		case 4: res=cnt_trailing_clear_bits(num);
			printf("number of trailing clear bits are: %d\n",res);
			break;
		default: exit(1);
	}
	
}
void display(unsigned int num)
{
	int i;
	
	for(i=32;i>0;i--)
	{
		printf("%d",(num & (1<<(i-1)))?1:0);
	}
	printf("\n");
}
int cnt_leading_set_bits(unsigned int num)
{
	int pos,count=0;
	unsigned int temp;

	for(pos=31;pos>=0;pos--)
	{
		temp=num;
		temp=temp & (1<<(pos-1));
		temp=(temp>>(pos-1))&1;
		if(temp==1)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}
int cnt_leading_clear_bits(unsigned int num)
{
	int pos,count=0;
	unsigned int temp;

	for(pos=31;pos>=0;pos--)
	{
		temp=num;
		temp=temp & (1<<(pos-1));
		temp=(temp>>(pos-1))&1;
		if(temp==0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}
int cnt_trailing_set_bits(unsigned int num)
{
	int pos,count=0;
	unsigned int temp;

	for(pos=1;pos<=32;pos++)
	{
		temp=num;
		temp=temp & (1<<(pos-1));
		temp=(temp>>(pos-1))&1;
		if(temp==1)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}
int cnt_trailing_clear_bits(unsigned int num)
{
	int pos,count=0;
	unsigned int temp;
		
	for(pos=1;pos<=32;pos++)
	{
		temp=num;
		temp=temp & (1<<(pos-1));
		temp=(temp>>(pos-1))&1;
		if(temp==0)
		{
			count++;
		}
		else
		{
			break;
		}
	}	
	return count;
}
