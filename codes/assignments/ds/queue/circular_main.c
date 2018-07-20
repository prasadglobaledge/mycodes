#include"queue.h"

int rear = -1;
int front = 0;

int main()
{
    int element;
    int choice;
    char *str = NULL;
    int rear_ele;
    int front_ele;
    int count;

    str = (char *)malloc(sizeof(int));
    if(str == NULL)
    {
        printf("MA failed\n");
        exit(1); 
    }

    for(;;)
    {
        printf("enter your choice :\n1.Enqueue\n2.Dequeue\n3.Display\n4.Isfull\n\
               \r5.Isempty\n6.Rear_element\n7.Front_element\n8.SIze\n");
        fgets(str, sizeof(int), stdin);
        choice = atoi(str);

        switch(choice)
        {
            case 1: printf("enter the element to push\n");
                    __fpurge(stdin);
                    fgets(str, sizeof(int), stdin);
                    element = atoi(str);
                    enqueue(element);
                    display();
                    break;

            case 2: dequeue();
                    display();
                    break;
            
            case 3: display();
                    break;

            case 4: isfull();
                    break;

            case 5: isempty();
                    break;

            case 6: rear_ele = rear_element();
                    printf("the rear element is : %d\n", rear_ele);
                    break;

            case 7: front_ele = front_element();
                    printf("the front element is : %d\n",front_ele);
                    break;

            case 8: count = size();
                    printf("the number of elements in queue is : %d\n",count);
                    break;

            default: printf("wrong choice\n");
                     break;
        }

    }
    return 0;
}
