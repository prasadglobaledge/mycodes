#include"queue.h"

extern int rear;
extern int front;

void enqueue(int element)
{
    if(rear == SIZE - 1 && front == 0)
    {
        printf("queue is full!! overflow\n");
        return;
    }
    else if(rear == -1 && front == 0)
    {
        rear++;
    }
    else if(rear == SIZE -1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = element;
}
void dequeue()
{
    if(rear == -1 && front == 0)
    {
        printf("queue is empty!! underflows\n");
        return;
    }
    else if(rear == SIZE - 1 && front == rear)
    {
        printf("the popped element is : %d\n", queue[front]);
        front = 0;
        rear = -1;
    }
    else if(front == SIZE-1 && rear != front)
    {
        front = 0;
        printf("the popped element is : %d\n",queue[front]);
        front++;
    }
    else
    {
        printf("the popped element is : %d\n", queue[front]);
        front++;
    }
}
void isempty()
{
    if(front == 0 && rear == -1)
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

    if(front == 0 && rear == -1)
    {
        printf("queue is empty!! nothing to display\n");
    }
    else if(front != 0 && rear == SIZE - 1)
    {
        printf("the elements of queue are :\n");
        for(index = front;index <= SIZE - 1;index++)
        {
            printf("%d\n",queue[index]);
        }
    }
    else if(front == (rear + 1) && rear != SIZE - 1)
        {
             printf("the elements of queue are :\n");
             for(index = front;index <= SIZE - 1;index++)
             {
                printf("%d\n",queue[index]);
             }
             for(index = 0;index < front;index++)
             {
                printf("%d\n", queue[index]);
             }
        }
    else 
    {
        printf("the elements of queue are :\n");
        for(index = front;index <= rear;index++)
        {
            printf("%d\n",queue[index]);
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
    
    if(front == 0 && rear == -1)
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
    if(front == 0 && rear == -1)
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
    if(front == 0 && rear == -1)
    {
        return 0;
    }
    else if(front != 0 && rear != SIZE -1)
    {
        return ((SIZE - front) + (rear + 1));
    }
    else
    {
        return (rear - front + 1);
    }

}
