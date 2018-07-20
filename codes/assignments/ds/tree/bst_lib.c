#include "bst_header.h"

extern NODE *root;

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
    newnode -> lnext = NULL;
    newnode -> rnext = NULL;
    
    return newnode;
}

int insertion(){

    NODE *newnode = create_node();
    NODE *temp = NULL;

    if(root == NULL){
        root = newnode;
        return SUCCESS;
    }
    if(root -> lnext == NULL && root -> rnext == NULL){
        if(root -> info > newnode -> info){
            root -> lnext = newnode;
            return SUCCESS;
        }
        else if(root -> info < newnode -> info){
            root -> rnext = newnode;
            return SUCCESS;
        }
        else{
            fprintf(stdout, "elements are same so insertion is not done\n");
            return SUCCESS;
        }
    }
    temp = root;
    while(temp -> lnext != NULL && temp -> rnext != NULL){
        if(temp -> next == NULL && temp -> rnext == NULL && (temp -> info >
                    newnode -> info) ){
            temp -> lnext = newnode;
            return SUCCESS;
        }
        else if(temp -> next == NULL && temp -> rnext == NULL && (temp -> info 
                     < newnode -> info) ){
            temp -> rnext = newnode;
            return SUCCESS;
        }
        else if(temp -> next == NULL && temp -> rnext == NULL && (temp -> info 
                  == newnode -> info) ){
            fprintf(stdout, "elements are same !! not inserted\n");
            return FAIL;
        }
        else{
            if(temp -> info > newnode -> info){
                temp = temp ->
                return SUCCESS;
            }
            else if(root -> info < newnode -> info){
                root -> rnext = newnode;
                return SUCCESS;
            }   
            else{
                fprintf(stdout, "elements are same so insertion is not done\n");
                return SUCCESS;
            }
        }
    }
