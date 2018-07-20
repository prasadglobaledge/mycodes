#include<stdio.h>

void display(int,int);
int main()
{
	int snum,dnum,s_pos,d_pos,temp1,temp2;

	printf("enter the snum, dnum, s_pos, d_pos\n");
	scanf("%d %d %d %d",&snum,&dnum,&s_pos,&d_pos);

	temp1=snum;
	temp2=dnum;

	printf("\nnumbers before swapping\n");
	display(snum,dnum);
	temp1=(temp1>>(s_pos-1))&1;
	temp2=(temp2>>(d_pos-1))&1;

	if(temp1==temp2)
	{
		printf("\nnumbers after swapping\n");
		display(snum,dnum);
	}
	else
	{
		snum=(snum^(1<<(s_pos-1)));
		dnum=(dnum^(1<<(d_pos-1)));
	}
	printf("\nthe numbers after swapping are\n");
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
	
