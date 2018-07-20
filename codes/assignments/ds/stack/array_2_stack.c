#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int stack1[SIZE];
int stack2[SIZE];
int sp1 = -1;
int sp2 = 4;
int arr[10] = {1,2,3,4,5,6,7,8,9,0};
void push(int element);
void pop();
void display();

int main()
{
    int choice;
    int element;
    char *str = NULL;

    str = (char *)malloc(sizeof(char) * SIZE);
    if(str == NULL){
        printf("MA failed\n");
        exit(1);
    }

    for(;;){
        
        printf("enter the choice:\n1.push\n2.pop\n3.display_stack1\
                \n4.exit");
        choice = atoi(fgets(str, SIZE, stdin));

        switch(choice){
        
                case 1: printf("enter the element to push\n");
                        __fpurge(stdin);
                        element = atoi(fgets(str, SIZE, stdin));
                        push();
                        display();
                        break;
                case 2: pop();
                        display();
                        break;
                case 3: display();
                        break;
                case 4: exit(1);

                default: printf("wrong choice!! enter correct choice\n");
                         break;
        }
    }
    return 0;
}
void push(int element)
{
    int choice;
    char *str = NULL;

    str = (char *)malloc(sizeof(char) * SIZE);
    if(str == NULL){
        printf("MA failed\n");
        exit(1);
    }
    printf("enter\n1.push_to stack1\n2.push_to_stack2\n");
    __fpurge(stdin);
    choice = atoi(fgets(str, SIZE, stdin));

    switch(choice)
    {
        case 1: if(sp1 == SIZE -1){
                    printf("stack is full!!! stack overflows\n");
                }
                else
                {
                    sp1++;
                    stack[sp1++]
                }
    
    
    }

}
