#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int str_cmp_case(char *str1,char *str2);
char *upper_lower(char *str);
int main()
{
    char *str1=NULL;
    char *str2=NULL;
    int res;

    
    str1=(char *)malloc(SIZE*sizeof(char));
    str2=(char *)malloc(SIZE*sizeof(char));
    
    if(str1==NULL || str2==NULL)
    {
        printf("MA failed\n");
        exit(1);
    }

    printf("enter two strings to compare\n");
    fgets(str1,50,stdin);
    fgets(str2,50,stdin);

    res=str_cmp_case(str1,str2);
    printf("%d\n",res);
}
char *upper_lower(char *str)
{
    int i=0;

    while(*(str+i)!='\n')
    {
        if((*(str+i)>=65 && *(str+i)<=92))
        {
            *(str+i)=*(str+i)+32;
        }
        i++;
    }
    return str;
}
int str_cmp_case(char *str1,char *str2)
{
    int i=0;

    str1=upper_lower(str1);
    str2=upper_lower(str2);

    while(*(str1+i)!='\n')
    {
        if(*(str1+i)>*(str2+i))
        {
            return 1;
        }
        else if(*(str1+i)<*(str2+i))
        {
            return -1;
        }
        i++;
    }
    return 0;
}


