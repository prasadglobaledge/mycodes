#include"queue.h"

extern int rear;
extern int front;

void enqueue(int element)
{
    if(rear == SIZE - 1)
    {
        printf("queue is full!! overflow\n");
    }
    else
    {
        rear++;
        queue[rear] = element;
    }
}
void dequeue()
{
    if(rear == -1)
    {
        printf("queue is empty!! underflows\n");
    }
    else
    {
        printf("the popped element is : %d\n", queue[front]);
        front++;
    }
}
void isempty()
{
    if(rear == -1 && front == 0)
    {
        printf("queue is empty!!you can push the values\n");
    }
    else
    {
        printf("queue is not empty\n");
    }
}
void display()
{
    int index;

    if(rear == -1)
    {
        printf("queue is empty!! nothing to display\n");
    }
    else
    {
        printf("the elements of queue are :\n");
        for(index = front;index <= rear;index++)
        {
            printf("%d\n", queue[index]);
        }
    }
}
void isfull()
{
    if(rear == SIZE - 1 && front == 0)
    {
        printf("queue is full!! you cant insert the elements\n");
    }
    else
    {
        printf("queue is not full\n");
    }
}
int rear_element()
{
    if(rear == -1)
    {
        printf("queue is empty no rear element\n");
    }
    else
    {
        return queue[rear];
    }
}
int front_element()
{
    if(rear == -1)
    {
        printf("queue is empty no front element\n");
    }
    else
    {
        return queue[front];
    }
}
int size()
{
    if(rear == -1)
    {
        return 0;
    }
    else
    {
        return (rear - front + 1);
    }
}
