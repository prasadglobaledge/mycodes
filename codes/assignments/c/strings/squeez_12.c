#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

char *squeeze_chr(char *str);
int main()
{
    char *str=NULL;
    char *res=NULL;

    str=(char *)malloc(SIZE*sizeof(char));
    if(str==NULL)
    {
        printf("MA failed\n");
        exit(1);
    }
    
    printf("enter the string\n");
    fgets(str,SIZE,stdin);

    res=squeeze_chr(str);
    printf("string after squeezing consecutive characters : %s\n",res);
    free(str);
}
char *squeeze_chr(char *str)
{
    int i=0,j=0;
    int length=0;

    while(*(str+i)!='\n')
    {
        length++;
        i++;
    }
    i=0;
    while(j<length)
    {
        if(*(str+j)!=*(str+j+1))
        {
            *(str+i)=*(str+j);
            i++;
        }
        j++;
    }
    *(str+i)='\0';
    return str;
}
