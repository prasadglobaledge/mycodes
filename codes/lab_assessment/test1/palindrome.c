#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int palindrome(char *str);

int main()
{
    char *str = NULL;
    int res;

    str = (char *)malloc(SIZE * sizeof(char));
    if(str == NULL){
        perror("malloc");
        exit(1);
    }
    printf("enter the string to check palindrome or not\n");
    fgets(str , SIZE, stdin);

    res = palindrome(str);

    (res == 1) ? printf("palindrome\n") : printf("not palindrome\n");
    return 0;
}
int palindrome(char *str)
{
    int index = 0;
    int length = 0;

    while(*(str + index) != '\n'){
        length++;
        index++;
    }
    index = 0;
    while(index < (length/2)){
        if(*(str + index) != *(str + (length - index - 1))){
            return 0;
        }
        index++;
    }
    return 1;
}

