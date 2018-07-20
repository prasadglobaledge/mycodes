#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50

int a_2_i(char *str);

int main()
{
    char *str = NULL;
    int res;

    str = (char *) malloc(sizeof(char) * SIZE);
    if(str == NULL)
    {
        printf("MA failed\n");
        exit(1);
    }
    printf("enter the string with integers\n");
    fgets(str,SIZE,stdin);

    res=a_2_i(str);
    
    printf("strings converted to integer is : %d\n",res);
}
int a_2_i(char *str)
{
    int i = 0;
    int len;
    int num = 0;
     
    len = strlen(str);
    len = len - 1;

    while(i < len)
    {
        if(*(str + i) == '-')
        {
            i++;
        }
        num = num * 10 +(*(str + i) - '0');
        i++;
    }
    if(*(str + 0) == '-')
    {
        return -num;
    }
    else
    {
        return num;
    }
}
