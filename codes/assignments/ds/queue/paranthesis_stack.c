#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

char stack[SIZE];
int sp = -1;

char push(char element);
char pop();
void display();

int main()
{
    char *str = NULL;
    int i = 0;
    char res, ch;

    str = (char *)malloc(sizeof(char) * SIZE) ;
    if(str == NULL)
    {
        printf("MA failes\n");
        exit(1);
    }   
    printf("enter the equqtion with paranthesis\n");
    fgets(str, SIZE, stdin);

    while(*(str + i) != '\0')
    {
        if(*(str + i) == '(')
        {
            ch = *(str + i);
            push(ch);
            display();
        }
        else if(*(str + i) == ')')
        {
            res = pop();
            sp--;
            printf("pranthesis matched : %c and %c\n", res, *(str + i));
        }
        i++;
    }

}
char push(char ch)
{
    if(sp == SIZE - 1)
    {
        printf("stack is full!!! ovrflows\n");
    }
    else
    {
        sp++;
        stack[sp] = ch;
    }
}
void display()
{
    int i;
    if(sp == -1)
    {
        printf("stack is empty nothing to display\n");
    }
    else
    {
        printf("contents of the stack are : \n");
        for(i = sp;i >=0;i--)
        {
            printf("%c\n",stack[i]);
        }
    }
}   
char pop()
{
    if(sp == -1)
    {
        printf("stack is empty!! underflows\n");
    }
    else
    {
        printf("the popped element is : %c\n",stack[sp]);
        return stack[sp];
    }
}
