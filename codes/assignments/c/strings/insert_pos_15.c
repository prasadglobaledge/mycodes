#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

char *insert_char(char *str,char ch,int pos);
int str_len(char *str);
int main()
{
    char *str=NULL;
    char *res=NULL;
    char ch;
    int pos;
    int length;

    str=(char *)malloc(SIZE*sizeof(char));
    if(str==NULL)
    {
        printf("MA failed\n");
        exit(1);
    }
    printf("enter the string\n");
    fgets(str,SIZE,stdin);
    length=str_len(str);

    printf("enter the character to insert\n");
    ch=getchar();

    printf("enter the position to insert a character b/w 1 and %d\n",length);
    scanf("%d",&pos);

    res=insert_char(str,ch,pos);

    printf("string after the character insertion is : %s\n",res);
    free(str);
}
char *insert_char(char *str,char ch,int pos)
{
    int i=0,j=0,length=0,len=0;
    while(*(str+i)!='\0')
    {
        length++;
        i++;
    }
    len=length;
    while(length>=pos)
    {
        *(str+length)=*(str+length-1);
        length--;
    }
    *(str+pos-1)=ch;
    *(str+len+1)='\0';
    return str;
}
int str_len(char *str)
{
    int i=0;
    int length=0;
    while(*(str+i)!='\0')
    {
        length++;
        i++;
    }
    return length;
}
