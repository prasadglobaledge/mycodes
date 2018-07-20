#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int str_palindrome(char *str);
int main()
{
    char *str=NULL;
    int res;

    str=(char *)malloc(SIZE*sizeof(char));
    if(str==NULL)
    {
        printf("MA failed\n");
        exit(1);
    }
    printf("enter the string\n");
    fgets(str,SIZE,stdin);

    res=str_palindrome(str);
    if(res==1)
    {
        printf("string is palindrome\n");
    }
    else
    {
        printf("string is not palindrome\n");
    }
    free(str);
}
int str_palindrome(char *str)
{
    int i=0,j=1;
    int length=0;
    int flag;

    while(*(str+i)!='\n')
    {
        length++;
        i++;
    }    
    i=0;
    while(i<(length/2))
    {
        flag=0;
        if(*(str+i) != *(str+length-j))
        {
            return 0;
        }
        else
        {
            flag=1;
            i++;
            j++;
        }
    }
    if(flag==1)
    {
        return 1;
    }
}
