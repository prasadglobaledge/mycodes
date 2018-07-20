#include<stdio.h>
#include<stdlib.h>

char  *chr_addr_instr(char *sbuf,char c);

int main()
{
	char *sbuf;
	char c;
	char *res;

    sbuf=(char *)malloc(50*sizeof(char));
    if(sbuf==NULL)
    {
        exit(1);
    }

	printf("enter the string\n");
	fgets(sbuf,25,stdin);

	printf("enter the character to search\n");
	scanf("%c",&c);

	res=chr_addr_instr(sbuf,c);
	if(res)
	{
		printf("the first occurence of %c is at the address %p  in the given string\n",c,res);
	}
	else
	{
		printf("Not found\n");
	}
}

char  *chr_addr_instr(char *sbuf,char c)
{
	int length=0,i;

	for(i=0;sbuf[i]!='\0';i++)
	{
		length++;
	}
	for(i=0;i<length;i++)
	{
		if(*(sbuf+i)==c)
		{
			return (sbuf+i);
		}
	}
	return 0;
}
