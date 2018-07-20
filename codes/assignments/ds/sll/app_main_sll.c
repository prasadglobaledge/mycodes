///// file to give the interface to the user for seleting the operstion//////
/*16-04-2018 continuing with assert() */
#include "sll_headers.h"

NODE *head = NULL;///@var

int main(void){
    
    int choice; /** @var choice to select the operation*/
    char *str = NULL; /**@var pointer to collect the choice*/
    int res;  /**@var to collect the result value*/

    str = (char *) malloc(sizeof(int)); /**dynamic memory allocation*/
    assert(str);
    
    for(; ;){                                   

        fprintf(stdout, "enter the choice : \
                         \n1.INSERT_begin\
                         \n2.INSERT_end\
                         \n3.INSERT_any_pos\
                         \n4.DISPLAY\
                         \n5.DELETE_begin\
                         \n6.DELETE_end\
                         \n7.DELETE_any_pos\
                         \n8.SEARCH_node\n");

        choice = atoi(fgets(str, SIZE, stdin)); /**getting choice from user*/
        
        switch(choice){             /**cases to perform different opeartions*/
        
            case Insert_begin   : res = insert_begin();
                                  (res == 1) ? fprintf(stdout, "Insertion \
                                          \rsuccessfull\n") : fprintf(stdout,"\
                                          \rinsertion failed\n");
                                  display();
                                  break;

            case Insert_end     : res = insert_end();
                                  (res == 1) ? fprintf(stdout, "Insertion \
                                          \rsuccessfull\n") : fprintf(stdout,"\
                                          \rinsertion failed\n");  
                                  display();
                                  break;

            case Insert_pos : res = insert_any_pos();
                                  (res == 1) ? fprintf(stdout, "Insertion \
                                          \rsuccessfull\n") : fprintf(stdout,"\
                                          \rinsertion failed\n");
                                  display();
                                  break;
        
            case Display        : res = display();
                                  (res == 1) ? fprintf(stdout, "display \
                                          \rsuccessfull\n") : fprintf(stdout,"\
                                          \rdisplay failed\n");

                                  break;

            case Delete_begin   : res = delete_begin();
                                  (res == 1) ? fprintf(stdout, "deletion \
                                          \rsuccessfull\n") : fprintf(stdout,"\
                                          \rdeletion failed\n");
                                  display();
                                  break;

            case Delete_end     : res = delete_end();
                                  (res == 1) ? fprintf(stdout, "deletion \
                                          \rsuccessfull\n") : fprintf(stdout,"\
                                          \rdeletion failed\n");
                                  display();
                                  break;

            case Delete_pos : res = delete_any_pos();
                                  (res == 1) ? fprintf(stdout, "deletion \
                                          \rsuccessfull\n") : fprintf(stdout,"\
                                          \rdeletion failed\n");
                                  display();
                                  break;

            case Search_node    : res = search_node();
                                  (res == 1) ? fprintf(stdout, "Searching is \
                                          \rsuccessfull\n") : fprintf(stdout,"\
                                          \relement Not found \n");
                                  break;

          /*  case reverse_list   : res = reverse_list();
                                  (res == 1) ? fprintf(stdout, "Reverse is\
                                          \rsuccessfull\n") : fprintf(stdout,"\
                                          \rReverse failed\n");
                                  display();
                                  break;*/

            default             : fprintf(stdout, "wrong choice select the cor\
                                      \rrect choice\n") ;
                                  break;      
        }

    }
    return 0;
}
