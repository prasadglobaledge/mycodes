#include<stdlib.h>
#include<stdio.h>
char *str_tok(char *buf,char *delim);
int main()
{
    char *buf;
    char *delim;
    char *temp;

    buf=(char *)malloc(100*sizeof(char));
    delim=(char *)malloc(100*sizeof(char));

    if(buf==NULL | delim==NULL)
    {
        printf("MA failed");
        exit(1);
    }
    printf("enter the string with delimiter\n");
    fgets(buf,50,stdin);
    printf("eneter the set of delimiters\n");
    fgets(delim,50,stdin);
    temp=str_tok(buf,delim);
    
    while(temp!='\0')
     {
         printf("%s\n",temp);
         temp=str_tok(NULL,delim); 
     }

}
char *str_tok(char *buf,char *delim)
{
    int i=0;
    int j=0;
    int k;
    char *temp;

    temp=(char *)malloc(100*sizeof(char));

    while(*(buf+i)!='\0')
    {
        while(*(buf+i)!=*(delim+j))
        {
            j++;
            if(*(delim+j)=='\0')
            {
                break;
            }

        }
        *(temp+i)=*(buf+i);



        }
    
    }
