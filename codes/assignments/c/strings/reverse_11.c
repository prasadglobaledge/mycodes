#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

char *reverse_str(char *str);
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

    res=reverse_str(str);

    printf("the reversed string is : %s\n",res);
    free(str);
}
char *reverse_str(char *str)
{
    char *temp=NULL;
    int i=0;
    int j=1;
    int length=0;

    temp=(char *)malloc(SIZE*sizeof(char));
    if(temp==NULL)
    {
        printf("MA failed\n");
        exit(1);
    }
    while(*(str+i)!='\n')
    {
        length++;
        i++;
    }
    i=0;
    while(i<length)
    {
        *(temp+i)=*(str+length-j);
        i++;
        j++;
    }
    return temp;
}
