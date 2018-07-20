#include<stdio.h>
#include<stdlib.h>

int my_atoi(char *str);
int main()
{
    int number;
    char *str = NULL;

    str = (char *)malloc(sizeof(int));
    if(str == NULL){
        perror("malloc");
        exit(1);
    }
    printf("enter the number to check number is even or odd\n");
    number = my_atoi(fgets(str, sizeof(int), stdin));
    
    (number & 1) ? printf("number is odd\n") : printf("number is even\n");
    return 0;
}
int my_atoi(char *str)
{
    int num = 0;
    int index = 0;

    while(*(str + index) != '\n')
    {
        num = (*(str + index) - '0') + (10 * num);
        index++;
    }
    return num;
}
