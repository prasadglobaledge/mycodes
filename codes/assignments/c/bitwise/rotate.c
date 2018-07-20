#include<stdio.h>
#include<stdlib.h>

void display(unsigned int num);
unsigned int left_rotate_bits(unsigned int num);
unsigned int right_rotate_bits(unsigned int num);
unsigned int left_rotate_n_bits(unsigned int num, int pos);
unsigned int right_rotate_n_bits(unsigned int num,int pos);

int main()
{
	unsigned int num;
	int pos,res,ch;

	printf("enter the number and position and choice \n 1.left_rotate 2.right_rotate 3.left_n_rotate 4.right_n_rotate\n");
	scanf("%d %d %d",&num,&pos,&ch);

	printf("\nnumber before rotate\n");
	display(num);
	
	switch(ch)
	{
		case 1:	printf("\nnumber after left_shift\n");
			res=left_rotate_bits(num);
			display(res);
			break;

		case 2:	printf("\n number after right_shift\n");
			res=right_rotate_bits(num);
			display(res);
			break;

		case 3:	printf("\n number afterv left_n_bits\n");
			res=left_rotate_n_bits(num,pos);
			display(res);
			break;
	
		case 4:	printf("\n number after right_n_bits\n");
			res=left_rotate_n_bits(num,pos);
			display(res);
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
unsigned int left_rotate_bits(unsigned int num)
{
	unsigned int temp;

	temp=num;
	temp=temp & (1<<(31));
	temp=(temp>>(31)) & 1;
	if(temp==0)
	{
		num=(num<<1) & ~(temp);
		return num;
	}
	else
	{
		num=(num<<1) | (temp);
		return num;
	}
}
unsigned int right_rotate_bits(unsigned int num)
{
	unsigned int temp;

	temp=num;
	temp=temp & 1;
	if(temp==0)
	{
		num=(num>>1) & ~(1<<31);
		return num;
	}
	else
	{
		num=(num>>1) | (1<<31);
		return num;
	}
}
unsigned int left_rotate_n_bits(unsigned int num,int pos)
{
	unsigned int temp,temp1;
	int i;

	temp=num;
	for(i=0;i<pos;i++)
	{
		temp1=temp;
		temp=temp & (1<<31);
		temp=(temp>>31)&1;
		if(temp==0)
		{
			temp=(temp1<<1) & ~(temp);
		}
		else
		{
			temp=(temp<<1) | (temp);
		}
	}
	num=temp1;
	return num;
}
unsigned int right_rotate_n_bits(unsigned int num,int pos)
{
	unsigned int temp,temp1;
	int i;
	
	temp=num;
	for(i=0;i<pos;i++)
	{
		temp1=temp;
		temp=temp & 1;
		if(temp==0)
		{
			temp=(temp1>>1) & ~(1<<31);
		}
		else
		{
			temp= (temp1>>1) | (1<<31);
		}
	}
	num=temp1;
	return num;
}
