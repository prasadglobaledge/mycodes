#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int str_rotate(char *str1,char *str2);
int str_len(char *str);
int main()
{
    char *str1=NULL;
    char *str2=NULL:
    int res;

    str1=(char *)malloc(SIZE*sizeof(char));
    str2=(char *)malloc(SIZE*sizeof(char));
    
    if(str1==NULL || str2==NULL)
    {
        printf("MA failed\n");
        exit(1);
    }
    
    printf("enter the string\n");
    fgets(str1,SIZE,stdin);

    printf("enter the rotated string\n");
    fgets(str2,SIZE,stdin);

    res=str_rotate(str1,str2);
    if(res)
    {
        printf("string2 is rotated string of string1\n");
    }
    else
    {
        printf("string2 is not a rotated string of string1\n");
    }
}
int str_rotate(char *str1,char *str2)
{
    int i=0;
    int j=0;
    int len1,len2;

    len1=str_len(str1);
    len2=str_len(str2);
    
    while(*(str+i)!='\n') 
    {
        if(*(str+j)==*(str+i))
        {
            break;
        }
        i++;
    }   


}
int str_len(char *str)
{
    int length=0;
    while(str[length++]!='\n');
    return length;
}

