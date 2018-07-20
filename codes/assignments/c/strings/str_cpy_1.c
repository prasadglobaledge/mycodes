#include<stdio.h>
#include<stdlib.h>

void str_cpy(char *dbuf,char *sbuf);

int main()
{
	char *sbuf="Global Edge";
	char *dbuf;

	str_cpy(dbuf,sbuf);
//	printf("dbuf after string copy is: %s\n",dbuf);
	return 0;
}
void str_cpy(char *dbuf,char *sbuf)
{
	int length=0,i;

	for(i=0;sbuf[i]!='\0';i++)
	{
		length++;
	}
	dbuf=(char *)malloc(length+1);

	if(dbuf==NULL)
	{
		printf("memory allocation failed\n");
		exit(1);
	}

	for(i=0;i<length;i++)
	{
        *(dbuf+i)=*(sbuf+i);
	}
	*(dbuf+i)='\0';

	printf("dbuf after string copy is : %s\n",dbuf);
	free(dbuf);
	dbuf=NULL;
}
