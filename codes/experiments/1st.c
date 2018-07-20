int main()
{
	int a,i;

	printf("enter any integer\n");
	scanf("%d",&a);

	for(i=31;i>=0;i--)
	{
		a=a&(1<<i);
		printf("%d",a);
	}
}
