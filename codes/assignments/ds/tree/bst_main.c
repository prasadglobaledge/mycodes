#include "bst_header.h"

NODE *root = NULL;

int main(void){

    int choice = 0;
    char *str = NULL;
    int res;

    str = (char *) malloc(sizeof(int));
    if(str == NULL){
        fprintf(stdout, "malloc error\n");
        assert(str);
    }

    for(; ;){
        fprintf(stdout, "enter the choice :\
                        \n1.Insertion\
                        \n2.Deletion\
                        \n3.Post_traversal\
                        \n4.Pre_traversal\
                        \n5.In_traversal\
                        \n6.Search_node\n");
        choice = atoi(fgets(str, sizeof(int), stdin));

        switch(choice){
            case Insertion : res = insertion();
                             (res == 1) ? fprintf(stdout, "successfull insertion\
                             \n") : fprintf(stdout, "failed\n");
                             break;
            
            case Deletion : res = deletion();
                             (res == 1) ? fprintf(stdout, "successfull deletion\
                             \n") : fprintf(stdout, "failed\n");
                             break;

            case Post_Traversal : res = post_traversal();
                             (res == 1) ? fprintf(stdout, "successfull traversal\
                             \n") : fprintf(stdout, "failed\n");
                             break;
        
            case Pre_Traversal : res = pre_traversal();
                             (res == 1) ? fprintf(stdout, "successfull traversal\
                             \n") : fprintf(stdout, "failed\n");
                             break;
    
            case In_Traversal : res = in_traversal();
                             (res == 1) ? fprintf(stdout, "successfull traversal\
                             \n") : fprintf(stdout, "failed\n");
                             break;

            case Search_node : res = search_node();
                             (res == 1) ? fprintf(stdout, "successfull searching\
                             \n") : fprintf(stdout, "failed\n");
                             break;

            default : fprintf(stdout, "wrong choice entered\n");
                      break;

        }
    }
    return 0;
}
