#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int file_size(FILE *fp, long int count);

int main()
{
    FILE *fp = NULL;
    FILE *fp1 = NULL;
    char *str = NULL;
    long int count = 0;
    int res;
    int size_blocks;
    int i = 0;
    
    str = (char *)malloc(SIZE * sizeof(char));
    //*str = (char *)malloc(SIZE * sizeof(char));

    if(str == NULL)
    {
        printf("MA failed\n");
        exit(1);
    }

    fp = fopen("file1.txt", "r");
    fp1 = fopen("file2.txt", "w");
    if(fp == NULL || fp1 == NULL)
    {
        printf("file not opened\n");
        exit(1);
    }
    res = file_size(fp, count);
    printf("the size of the file is : %d bytes\n",res);

    size_blocks = (res/4);

    rewind(fp);

    while(i < 4)
    {
        fread(str, size_blocks, 1, fp);
        printf("%s\n", str);
        fwrite(str,size_blocks, 1, fp1);
        i++;     
    }
    
    fclose(fp);
    fclose(fp1);
    free(str);

    return 0;

}
int file_size(FILE *fp,long int count)
{
    fseek(fp, 0, SEEK_END);
    count = ftell(fp);
    
    return count;
}
