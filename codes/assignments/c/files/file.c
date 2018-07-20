#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp = NULL; //decalring a file pointer
    char ch;  //declaring a variable of type character

    fp = fopen("data.txt","r+"); //opening a file
    if(fp == NULL)              //checking for file opened or not
    {
        printf("file not opened\n");
        exit(0);
    }
    while((ch = fgetc(fp)) != EOF)  //taking characters from file
    {
        if(ch >= 65 && ch <=92)     //conversion from upper to lower
        {
            ch = ch + 32;
            fseek(fp, -1, SEEK_CUR);
            fputc(ch, fp);
        }
        else if(ch == '\n' || ch == ' ' || ch == '\0')
        {
            ch = ch;
        }
            
        else                            //conversion from lower to upper
        {
            ch = ch - 32;
            fseek(fp, -1, SEEK_CUR);
            fputc(ch, fp);
        }
    }
    fclose(fp);
}
