/* program to swap any two nodes in a list */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 100
#define SUCCESS 1
#define FAIL 0

typedef struct node{
    int info;
    struct node *next;
}NODE;

NODE *head = NULL;

enum tag {Insertion = 1, SWAP, DISPLAY, EXIT};

int swap();
int display();
int insert();
NODE *create_node();

int main (void)
{
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
                        \n2.Swap\
                        \n3.DISPLAY\
                        \n4.EXIT\n");
        choice = atoi(fgets(str, sizeof(int), stdin));

        switch(choice){
            case Insertion : res = insert();
                             (res == 1) ? fprintf(stdout, "successfull inserti\
                             \ron\n") : fprintf(stdout, "failed\n");
                             display();
                             break;
        
            case SWAP      : res = swap();
                             (res == 1) ? fprintf(stdout, "successfull swappin\
                             \rng\n") : fprintf(stdout, "failed\n");
                             display();
                             break;
            
            case DISPLAY   : res = display();
                             (res == 1) ? fprintf(stdout, "successfully displa\
                             \ryed\n") : fprintf(stdout, "failed\n");
                             break;

            case EXIT      : fprintf(stdout, "program terminated\n");
                             exit(1);

            default        : fprintf(stdout, "wrong choice\n");
                             break;
        }
    
    }
    return 0;
}

int insert(){
    
        NODE *newnode = NULL;
        NODE *cur = NULL;     //pointer to traverse
        int i = 1;            // initial value of position
        int pos;            //variable to hold pos
        char *str = NULL;

        newnode = create_node(); //creating node to insert

        str = (char *) malloc(sizeof(int));
        if(str == NULL){
            fprintf(stdout, "malloc\n");
            assert(str);
        }
        
        fprintf(stdout, "enter the position to insert\n");
        pos = atoi(fgets(str, sizeof(int), stdin));

        if(pos <= 0){    //if entered  position is zero or negative
            fprintf(stdout, "enter the positive postions only\n");
            return FAIL;
        } 

        if(head == NULL && pos == 1){  //if pos is one and no list present
            head = newnode;
            return SUCCESS;
        }

        if(head == NULL && pos > 1){  //if list is not present and pos > 1
            fprintf(stdout, "invalid position\n");
            return FAIL;
        }

        if(pos == 1){       //if list is present and position is 1
            newnode -> next = head;
            head = newnode;
            return SUCCESS;
        }

        cur = head;   //to traverse till the position
        while(cur -> next != NULL && i < (pos - 1)){  
            cur = cur -> next;
            i++;
        }
    
        if(cur -> next == NULL && pos == (i+1)){  //if position is at the end
            cur -> next = newnode;
            return SUCCESS;
        }
        newnode -> next = cur -> next;  //inserting at the traversed position
        cur -> next = newnode;
        return SUCCESS;
}

int display(){
 
        NODE *cur = NULL;

        if(head == NULL){     //if list is not present
            fprintf(stdout, "list is empty nothing to display\n");
            return FAIL;
        }
        
        cur = head;
        fprintf(stdout, "the elements of the list are :\n");
        while(cur != NULL){  // traversing through the list
            fprintf(stdout, "%d\n", cur -> info);
            cur = cur -> next;
        }
        return SUCCESS;
}

NODE *create_node(){

    NODE *newnode = NULL; // pointer of type NODE
    int element;
    char *str = NULL;

    str = (char *) malloc(sizeof(int)); //str for collecting element
    if(str == NULL){
        fprintf(stderr, "malloc");
        assert(str);      // assert() is to keep track of expression
    }

    newnode = (NODE *) malloc(sizeof(NODE));
    if(newnode == NULL){
        fprintf(stderr, "malloc");
        assert(newnode);
    }

    fprintf(stdout, "enter the element to insert\n");
    element = atoi(fgets(str, sizeof(int), stdin));
    
    newnode -> info = element; /*placing element in info field  and next field
                                    with NULL*/
    newnode -> next = NULL;
    
    return newnode;
}
int swap(){

    int pos1 = 0;
    int pos2 = 0;
    char *str = NULL;
    NODE *first = NULL;
    NODE *first1 = NULL;
    NODE *last = NULL;
    NODE *last1 = NULL;
    NODE *temp = NULL;
    int index = 1;

    str = (char *) malloc(sizeof(int));
    if(str == NULL){
        fprintf(stdout, "malloc\n");
        assert(str);
    }
    fprintf(stdout, "enter the positions to swap the nodes\n");
    __fpurge(stdin);
    pos1 = atoi(fgets(str, sizeof(int), stdin));
    __fpurge(stdin);
    pos2 = atoi(fgets(str, sizeof(int), stdin));

    if(head == NULL){
        fprintf(stdout, "list is empty nothing to swap\n");
        return FAIL;
    }

    first = head;
    while(index < pos1){
        first1 = first;
        first = first -> next;
        index++;
    }

    last = head;
    index = 1;
    while(index < pos2){
        last1 = last;
        last = last -> next;
        index++;
    }
    if(pos1 == 1){
        temp = last -> next;
        last -> next = first -> next;
        first -> next = temp;
        head = first;
    }
    else{
        temp = last -> next;
        last -> next = first -> next;
        first -> next = temp;
        temp = last1 -> next;
        last1 -> next = first1 -> next;
        first1 -> next = temp;
    }

    return SUCCESS;

}
