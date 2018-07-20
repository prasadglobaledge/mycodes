#include<stdio.h>
 
int bit_cpy(int,int,int,int,int);
void display(int,int);
int main()
{
	int snum,dnum,s_pos,d_pos,pos;

	printf("enter the snum, dnum,s_pos, d_pos,position\n");
	scanf("%d %d %d %d %d",&snum,&dnum,&s_pos,&d_pos,&pos);

	printf("\n nubers before copying\n");
	display(snum,dnum);
	bit_cpy(snum,dnum,s_pos,d_pos,pos);
}
int bit_cpy(int snum,int dnum,int s_pos,int d_pos,int pos)
{
	int index1=0,index2,temp1,temp2;

	index2=d_pos;
	temp2=dnum;

	while(index1<pos)
	{
		temp1=snum;
		temp1=temp1 & (1<<(s_pos-1));
		temp1=(temp1>>(s_pos-1))&1;
		if(temp1==0)
		{
			temp2=dnum & ~(temp1<<(index2-1));
			index2++;
			index1++;
		}
		else
		{
			temp2=dnum | (temp1<<(index2-1));
			index2++;
			index1++;
		}
		s_pos++;
	}
	dnum=temp2;
	printf("\n numbers after copying are:\n");
	display(snum,dnum);
}
void display(int snum,int dnum)
{
	int i;

	for(i=31;i>0;i--)
	{
		printf("%d",(snum & (1<<(i-1)))?1:0);
	}
	printf("\n");
	for(i=31;i>0;i--)
	{
		printf("%d",(dnum & (1<<(i-1)))?1:0);
	}
}
