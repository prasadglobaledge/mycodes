/**
 * @brief function for creating a new node
 * ***/
#include "bst.h"
#include <stdlib.h>
///Function definition for create node
bst_t* create_node(int value)
{
    ///Allocating memory for new node
    bst_t* new = malloc(sizeof(bst_t));
    if (NULL == new)
    {
        printf("ERROR!Failure in memory allocation\n");
        return;
    }
    new->left = NULL;
    ///Inserting value  
    new->data = value;
    new->right = NULL;
    return new;
}
