#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int str_len(char *str);
int str_spn_cnt(char *str1,char *str2);
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
    printf("enter the string\n");
    fgets(str1,SIZE,stdin);

    printf("enter the string to count\n");
    fgets(str2,SIZE,stdin);

    res=str_spn_cnt(str1,str2);
    printf("count of initial characters present in main string is : %d\n",res);
    return 0;
}
int str_spn_cnt(char *str1,char *str2)
{
    int count=0;
    int i=0,j=0;
    int len1;
    int len2;

    len1=str_len(str1);
    len2=str_len(str2);
    
    while(i<len2-1)
    {
        while(j<len1-1)
        {
            if(*(str2+i)==*(str1+j))
            {
                count++;
                break;
            }
            j++;
        }
        i++;
    }
    return count;
}
int str_len(char *str)
{
    int i=0;
    int length=0;
    while(str[length++] != '\n');

    return length;
}
