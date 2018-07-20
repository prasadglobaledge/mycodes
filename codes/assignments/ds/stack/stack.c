#include"stack.h"
extern int sp;

void push(int element)
{
    if(sp == SIZE - 1)
    {
        printf("stack is full!! stack overflow\n");
    
    }
    else
    {
        sp++;
        stack[sp] = element;
    }
}
void pop()
{
    if(sp == -1)
    {
        printf("stack undeflows!! stack is empty\n");
    }
    else
    {
        printf("the removed/popped element is :%d\n",stack[sp]);
        sp--;
    }
}
void display()
{
    int index;

    if(sp == -1)
    {
        printf("stack is empty!! nothing to display\n");
    }
    else
    {
        printf("elements of the stack are :\n");
        for(index = sp;index >= 0;index--) 
        {
            printf("%d\n",stack[index]);
        }   
    }

}
void isempty()
{
    if(sp == -1)
    {
        printf("stack is empty!!!");
    }
    else
    {
        printf("stack is not empty. Elements are present\n");
    }
}
void isfull()
{
    if(sp == SIZE - 1)
    {
        printf("stack is full\n");
    }
    else
    {
        printf("stack is not full you can insert the element\n");
    }
}
int size()
{
    if(sp == -1)
    {
        return 0;
    }
    else
    {
        return (++sp);
    }
}
int top()
{
    return stack[sp];
}
