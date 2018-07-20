/// function definitions of all operations on SLL
///@file sll_lib.c
///@date 02-05-2018

#include "sll_headers.h" /**including the header file*/

extern  NODE *head;    /**@var head node declared globally if head node is not 
                         declared globally then after all    
                           the operation return the head node*/  
NODE *create_node(){

    NODE *newnode = NULL; /**pointer of type NODE*/
    int element;   /**@var to collect the data element*/
    char *str = NULL; ///@var 

    str = (char *) malloc(sizeof(int)); /**str for collecting element*/
    assert(str);      /// assert() is to keep track of expression 
    

    newnode = (NODE *) malloc(sizeof(NODE));///to create newnode
    assert(newnode); /**to keep track of expression*/


    fprintf(stdout, "enter the element to insert\n");
    element = atoi(fgets(str, sizeof(int), stdin));
    
    newnode -> info = element; /**placing element in info field  and next field
                                    with NULL*/
    newnode -> next = NULL;
    
    return newnode;
}

int insert_begin(){

        NODE *newnode = create_node();/**creating node to insert*/

        if(head == NULL){          ///if list is not created
            head = newnode;         
            return SUCCESS;
        }
        newnode -> next = head; ///if list is present insert at beginning
        head = newnode;
        return SUCCESS;
}

int insert_end(){

        NODE *newnode = NULL; ///@var
        NODE *cur = NULL; ///@var

        newnode = create_node(); /** creating a node to insert*/

        if(head == NULL){             ///if list is not created
            head = newnode;
             return SUCCESS;
        }

        cur = head;  ///if list is present traverse till end
        while(cur -> next != NULL){
            cur = cur -> next;
        }

        cur -> next = newnode;  ///insertion at the end
        return SUCCESS;
}

int insert_any_pos(){
    
        NODE *newnode = NULL; ///@var
        NODE *cur = NULL;     ///@var pointer to traverse
        int i = 1;            /// @var initial value of position
        int pos;            ///@var variable to hold pos
        char *str = NULL; ///@var

        newnode = create_node(); ///creating node to insert

        str = (char *) malloc(sizeof(int));///to collect the position value
        assert(str);   ///to keep track of expression
        
        
        fprintf(stdout, "enter the position to insert\n");
        pos = atoi(fgets(str, sizeof(int), stdin));

        if(pos <= 0){    ///if entered  position is zero or negative
            fprintf(stdout, "enter the positive postions only\n");
            return FAIL;
        } 

        if(head == NULL && pos == 1){  ///if pos is one and no list present
            head = newnode;
            return SUCCESS;
        }

        if(head == NULL && pos > 1){  ///if list is not present and pos > 1
            fprintf(stderr, "invalid position\n");
            return FAIL;
        }

        if(pos == 1){       ///if list is present and position is 1
            newnode -> next = head;
            head = newnode;
            return SUCCESS;
        }

        cur = head;   ///to traverse till the position
        while(cur -> next != NULL && i < (pos - 1)){  
            cur = cur -> next;
            i++;
        }
    
        if(cur -> next == NULL && pos == (i+1)){  ///if position is at the end
            cur -> next = newnode;
            return SUCCESS;
        }

        if(cur -> next == NULL && pos > (i+1)){   //if position in greater than
            fprintf(stderr, "invalid position\n") ;      ///list
            return FAIL;
        }

        newnode -> next = cur -> next;///inserting at the traversed position
        cur -> next = newnode;
        return SUCCESS;
}

int display(){
 
        NODE *cur = NULL; ///@var

        if(head == NULL){     ///if list is not present
            fprintf(stdout, "list is empty nothing to display\n");
            return FAIL;  ///returning zero on failure
        }
        
        cur = head;
        fprintf(stdout, "the elements of the list are :\n");
        while(cur != NULL){  /// traversing through the list
            fprintf(stdout, "%d\n", cur -> info);
            cur = cur -> next;
        }
        return SUCCESS; ///returning 1 on success
}

int delete_begin(){
        
        NODE *cur = NULL; ///@var
        
        if(head == NULL){     ///if list is not present nothing to delete
            fprintf(stdout, "list is empty nothing to delete\n");
            return FAIL;
        }
        cur = head;          ///deletion at the beginning
        head = head -> next;
        free(cur);       ///deleting the node at the beginning
        cur = NULL;
        return SUCCESS;
}

int delete_end(){

        NODE *cur = NULL; ///@var
        NODE *temp = NULL; ///@var

        if(head == NULL){  ///if list is absent
            fprintf(stdout, "list is empty nothing to delete\n");
            return FAIL;
        }

        cur = head;     ///traversing till the end 
        while(cur -> next != NULL){
            temp = cur;
            cur = cur -> next;
        }

        temp -> next = NULL;
        free(cur); ///delting at the end
        cur = NULL;
        return SUCCESS;
}

int delete_any_pos(){
     
        NODE *temp = NULL;///@var 
        NODE *cur = NULL;     ///@var pointers to traverse
        int i = 1;            ///@var  initial value of position
        int pos;            ///@var variable to hold pos
        char *str = NULL;///@var

        str = (char *) malloc(sizeof(int));///to collect the position value
        assert(str); ///to keep track of the expression
        
        
        fprintf(stdout, "enter the position to delete\n");
        pos = atoi(fgets(str, sizeof(int), stdin));

        if(pos <= 0){    ///if entered  position is zero or negative
            fprintf(stdout, "enter the positive postions only\n");
            return FAIL;
        } 

        if(head == NULL && pos == 1){  ///if pos is one and no list present
            fprintf(stdout, "no list is present nothing to delete\n");
            return FAIL;
        }

        if(head == NULL && pos > 1){  ///if list is not present and pos > 1
            fprintf(stderr, "invalid position\n");
            return FAIL;
        }

        if(pos == 1){       ///if list is present and position is 1
            cur = head; 
            head = head -> next;
            free(cur);
            cur = NULL;
            return SUCCESS;
        }

        cur = head;   ///to traverse till the position
        while(cur -> next != NULL && i < pos){  
            temp = cur;
            cur = cur -> next;
            i++;
        }
    
        if(cur -> next == NULL && pos == i){  ///if position is at the end
            temp -> next = NULL;
            free(cur);
            cur = NULL;
            return SUCCESS;
        }

        if(cur -> next == NULL && pos > (i+1)){   ///if position in greater than
            fprintf(stderr, "invalid position\n") ;      //list
            return FAIL;
        }

        temp -> next = cur -> next; ///deleting at the traversed position
        free(cur);
        cur = NULL;
        return SUCCESS;
}

int search_node(){

        int key = 0; ///@ var key element to search in the list (linaer search)
        NODE *cur = NULL; ///@var popinter to traverse

        if(head == NULL){   ///if list is empty nothing to search
            fprintf(stderr, "list is empty nothing to search\n");
            return FAIL;
        }
        cur = head;     

        while(cur -> next != NULL){ ///traversing and checking for the element
            if(cur -> info == key){
                fprintf(stdout, "key element found\n");
                return SUCCESS;
            }
            cur = cur -> next;
        }
        return FAIL;
}

