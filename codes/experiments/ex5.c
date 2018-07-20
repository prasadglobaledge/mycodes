#include<stdio.h>
int fun(int a)
{
	int res;
	if(a!=0)
	{
		return a*fun(a-1);
	
	}
}
int main()
{
	static int a=123;
	int b;
	int res;

	a=6;
	res=fun(a);
	return 0;
}
