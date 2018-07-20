#include"employee_cll.h"

int main()
{
    int choice;
    char *str = NULL;
    int res;

    str = (char *)malloc(sizeof(char) * SIZE);
    if(str == NULL){

        printf("MA failed\n");
        exit(1);
    }
    for(;;){

        printf("enter the choice :\n1.Insert_begin\n2.Insert_end\
              \n3.Insert_at_pos\n4.delete_begin\n5.delete_end\
              \n6.delete_at_pos\n7.search\n8.reverse\n9.display\n");
        fgets(str, SIZE, stdin);
        choice = atoi(str);

        switch(choice){

            case 1: res = insert_begin();
                    printf("the status of insert is : %d\n",res);
//                    display();
                    break;
            case 2: res = insert_end();
                    printf("the status of insert is : %d\n",res);
  //                  display();
                    break;
            case 3: res = insert_at_pos();
                    printf("the status of insert is : %d\n",res);
    //                display();
                    break;
    /*        case 4: delete_begin();
                    break;
            case 5: delete_end();
                    break;
            case 6: delete_at_pos();
                    break;
            case 7: search();
                    break;
            case 8: reverse();
                    break;
            case 9: display();
                    break;*/
            default : printf("wrong choice enter the correct choice\n");
                      break;          
        }
    }
    return 0;
}
