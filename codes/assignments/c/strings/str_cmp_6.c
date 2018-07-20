#include<stdio.h>
#define SIZE 100

int str_cmp(char *str1,char *str2);
int main()
{
    char *str1=NULL;
    char *str2=NULL;
    int res;

    str1=(char *)malloc(SIZE*sizeof(char));
    str2=(char *)malloc(SIZE*sizeof(char));

    if(str1==NULL | str2==NULL)
    {
        exit(1);
    }
    res=str_cmp(str1,str2);

    printf("%d\n",res);
    
}
int str_cmp(char *str1,char *str2)
{
    int i=0;
    int res;

    while()
    
}


