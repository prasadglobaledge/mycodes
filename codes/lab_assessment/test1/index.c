#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

char  *ret_index(char *str, int c);

int main()
{
    char *str = NULL;
    char *str1 = NULL;
    int c;
    int index = 0;
    char *res = NULL;

    str = (char *)malloc(SIZE * sizeof(char));
    if(str == NULL){
        perror("malloc");
        exit(1);
    }
    str1 = (char *)malloc(sizeof(int));
    if(str1 == NULL){
        perror("malloc");
        exit(1);
    }
    printf("enter the string\n");
    fgets(str , SIZE, stdin);

    printf("enter the character to search\n");
    __fpurge(stdin);
    c = getchar();

 /*   while(*(str + index) != '\n'){
        printf("character %c presents at %p position\n", *(str + index), str);
        index++;
        str++;
    }*/

    res = ret_index(str, c);
        
    if(res){
        printf("character entered is present in %p address in the string %s\n", res, str);
    }
    else{
        printf("character not found\n");
    }
    return 0;
}
char *ret_index(char *str, int c)
{
    int length = 0;
    int index = 0;

    while(*(str + index) != '\n'){
        length++;
        index++;
    }
    index = length - 1;

    while(index >= 0){
        if(*(str + index) == c){
            return str;      
        }
        index--;
    }
    return 0;
}
    

