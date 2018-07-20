#include<stdio.h>
#include<stdlib.h>

void str_n_cpy(char *dbuf,char *sbuf,int n);

int main()
{
	char *sbuf="Global Edge";
	char *dbuf;
	int n;

	printf("enter the number of characters to copy\n");
	scanf("%d",&n);

	str_n_cpy(dbuf,sbuf,n);
	return 0;
}
void str_n_cpy(char *dbuf,char *sbuf,int n)
{
	int length=0,i;

	for(i=0;sbuf[i]!='\0';i++)
	{
		length++;
	}
	dbuf=(char *)malloc(length+1);

	if(dbuf==NULL)
	{
		printf("MA failed\n");
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		*(dbuf+i)=sbuf[i];
	}
	*(dbuf+i)='\0';

	printf("dbuf after the string_n_copy is : %s\n",dbuf);
	free(dbuf);
	dbuf=NULL;
}
