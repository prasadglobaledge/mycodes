#include<stdio.h>

#define get_bits(x,p,n,temp)  while(p>=(p-n))\
		            	    {temp=x;\
				            temp=(temp & (1<<(p-1)));\
                            temp=(temp>>(p-1));\
                            printf("%d",temp);\
                           p--; }

int main()
{
	int x,p,n,temp;

	printf("enter the number, position,limit\n");
	scanf("%d %d %d",&x,&p,&n);

	get_bits(x,p,n,temp)
	return 0;
}
				
			
