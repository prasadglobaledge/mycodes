#include"stack.h"
int sp = -1;

int main()
{
    int choice;
    int element;
    int count;
    char *str = NULL;

    str = (char *)malloc(SIZE * sizeof(char));
    if(str == NULL)
    {
        printf("MA failed\n");
        exit(1);
    }

    for(;;)
    {
        printf("enter your choice of operation on stack:\n 1.PUSH\n2.POP\n3.DISP\
                \n4.ISEMPTY\n5.ISFULL\n6.TOP_ELEMENT\n7.SIZE\n");
        fgets(str, SIZE, stdin);
        choice = atoi(str);
    
        switch(choice)
        {
            case 1: printf("enter the element\n");
                    fgets(str, SIZE, stdin);
                    element = atoi(str);
                    push(element);
                    display();
                    break;

            case 2: pop();
                    display();
                    break;

            case 3: display();
                    break;

            case 4: isempty();
                    break;

            case 5: isfull();
                    break;

            case 6: element = top();
                    printf("the top most element is : %d\n",element);
                    break;

            case 7: count = size();
                    printf("the number of elemets in the stack is : %d\n",count);
                    break;

            default: printf("wrong choice\n");
                     break; 

        }
    }
    return 0;
}
