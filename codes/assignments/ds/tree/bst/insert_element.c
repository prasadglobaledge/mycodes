/**
 * @brief To insert a new given element
 * **/
#include "bst.h"
///Function definition for inserting a new element
bst_t* insert_element(bst_t *root)
{
    ///Prompt for element
    printf("Enter the element\n");
    fgets(str, SIZE, stdin);
    __fpurge(stdin);
    value = my_atoi(str);

    ///Function call for insert value
    root = insert_value(root, value);
    return root;
}
///Function definition for insert element
bst_t* insert_value(bst_t *root, int value)
{
    ///Recursive function call to find exact position of insertion
    if(root == NULL)
        return create_node(value);
    if(root->data > value)
        root->left = insert_value(root->left, value);
    else if (root->data < value)
        root->right = insert_value(root->right, value);
    else
        printf("ERROR!Equal nodes not possible\n");
    return root;
}
