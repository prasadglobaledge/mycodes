#include<stdio.h>
#include<string.h>
int main()
{
    char buf[]="global-edge@";
    char *delim=strtok(buf,"@-");

    while(delim!='\0')
    {
        printf("%s\n",delim);
        delim=strtok(NULL,"@-");
    }

}
