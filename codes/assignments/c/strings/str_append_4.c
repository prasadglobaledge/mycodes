#include<stdio.h>
#include<stdlib.h>

char *str_append(char *str1,char *str2);
int main()
{
	char *str1;
	char *str2;

    str1=(char *)malloc(100*sizeof(char));
    str2=(char *)malloc(100*sizeof(char));

    if(str1==NULL | str2==NULL)
    {
        exit(1);
    }
	printf("enter two strings\n");
	fgets(str1,25,stdin);
	fgets(str2,25,stdin);

	str_append(str1,str2);
	printf("the appended string is : %s\n",str1);

}
char *str_append(char *str1,char *str2)
{
	int i;
	int j;
	int length=0,length1=0;

	for(i=0;str1[i]!='\0';i++)
	{
		length++;
	}
	
	for(j=0;str2[j]!='\0';j++)
	{
		*(str1+j+length-1)=*(str2+j);
	}
	 *(str1+j+length-1)='\0';
}
	
