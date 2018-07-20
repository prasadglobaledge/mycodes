/* main file to call the sorting functions */

#include "sort_headers.h"

int main (void)
{
    int choice;  // to get the choice of sorting from user
    char *str = NULL;
    int index;
    int res;  // to store the results 

    str = (char *) malloc(sizeof(int));

    if(str == NULL){
        fprintf(stdout, "malloc");
        assert(ptr);
    }

    fprintf(stdout, "enter the elements of the array to sort\n");

    for(index = 0; index < SIZE; index++){
        __fpurge(stdin);
        *(array + index) = atoi(fgets(str, sizeof(int), stdin));
    }
    
    for(; ;){                                   //user choice
        fprintf(stdout, "enter the choice :\
                        \n1.Selection_A\
                        \n2.Selection_D\
                        \n3.Bubble_A\
                        \n4.Bubble_D\
                        \n5.Insertion_A\
                        \n6.Insertion_D\
                        \n7.Merge_A\
                        \n8.Merge_D\
                        \n9.Quick_A\
                        \n10.Quick_D\n");
        __fpurge(stdin);
        choice = atoi(fgets(str, sizeof(int), stdin));

        switch(choice){
                
                case Selection_A :  res = selection_ascending();
                                    (res == 1) ? fprintf(stdout, "successfully\
                                    \rsorted\n") : fprintf(stdout, "failed\n");
                                    break;

                case Selection_D :  res = selection_descending();
                                    (res == 1) ? fprintf(stdout, "successfully\
                                    \rsorted\n") : fprintf(stdout, "failed\n");
                                    break;
        
                case Bubble_A    :  res = bubble_ascending();
                                    (res == 1) ? fprintf(stdout, "successfully\
                                    \rsorted\n") : fprintf(stdout, "failed\n");
                                    break;

                case Bubble_D    :  res = bubble_descending();
                                    (res == 1) ? fprintf(stdout, "successfully\
                                    \rsorted\n") : fprintf(stdout, "failed\n");
                                    break;
                 
                case Insertion_A :  res = insertion_ascending();
                                    (res == 1) ? fprintf(stdout, "successfully\
                                    \rsorted\n") : fprintf(stdout, "failed\n");
                                    break;
        
                case Insertion_D :  res = insertion_descending();
                                    (res == 1) ? fprintf(stdout, "successfully\
                                    \rsorted\n") : fprintf(stdout, "failed\n");
                                    break;

                case Merge_A     :  res = merge_ascending();
                                    (res == 1) ? fprintf(stdout, "successfully\
                                    \rsorted\n") : fprintf(stdout, "failed\n");
                                    break;

                case Merge_D     :  res = merge_descending();
                                    (res == 1) ? fprintf(stdout, "successfully\
                                    \rsorted\n") : fprintf(stdout, "failed\n");
                                    break;


                case Quick_A     :  res = quick_ascending();
                                    (res == 1) ? fprintf(stdout, "successfully\
                                    \rsorted\n") : fprintf(stdout, "failed\n");
                                    break;

                case Quick_D     :  res = quick_descending();
                                    (res == 1) ? fprintf(stdout, "successfully\
                                    \rsorted\n") : fprintf(stdout, "failed\n");
                                    break;


                default          :  fprintf(stdout, "wrong choice entered ente\
                                            \rr the correct choice\n");
                                    break;
        }
    
    }
    return 0;
}
