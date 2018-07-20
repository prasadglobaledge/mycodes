#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp = NULL;
    int seek;
    int tell;
    int pos;

    fp = fopen("data.txt","r+");
    if(fp == NULL)
    {
        printf("file not opened\n");
        exit(1);
    }
    seek = fseek(fp, -1, SEEK_END);
    tell = ftell(fp);
   // fsetpos(fp,5);
   // pos = fgetpos(fp,6);

    printf("%d\n%d\n", seek, tell);
    fclose(fp);
    return 0;
}
