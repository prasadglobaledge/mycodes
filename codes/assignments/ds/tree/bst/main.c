#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
int main()
{
    char post[SIZE];
    int choice;
    char loop;
    bst_t *root = NULL;
    do
    {
        printf("Choose any option\n");
        printf("1.Insert\n2.Search\n3.Find minimum\n4.Find maximum\n5.Delete\n6.Display\n");
        fgets(post, SIZE, stdin);
        choice = my_atoi(post);
        __fpurge(stdin);
        switch(choice)
        {
            case 1:root = insert_element(root);
                break;
            case 2:search_tree(root);
                   break;
            case 3:find_min(root);
                   break;
            case 4:find_max(root);
                   break;
            case 5:delete_element(root);
                   break;
            case 6:display_tree(root);
                   break;
            default:
                   printf("Invalid input\n");
                   break;
        }
        printf("Do you want to continue\n");
        loop = getchar();
        __fpurge(stdin);
    }while(loop == 'y');
    return 0;
}


