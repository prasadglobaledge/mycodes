/**
 * @brief Function to delete a particular node from tree
 * ***/
#include "bst.h"
#include <stdlib.h>
///Function definition for node deletion
bst_t* delete_element(bst_t *root)
{
    ///Checking for empty tree
    if(root == NULL)
    {
        printf("Tree already empty\n");
        return;
    }
    ///Prompt for element to be deleted
    printf("Enter the element to be deleted\n");
    fgets(str, SIZE, stdin);
    __fpurge(stdin);
    value = my_atoi(str);
    ///Function call to delete node
    root = delete_node_val(root, value);
    return root;
}
///Function definition to delete a node
bst_t *delete_node_val(bst_t *root, int value)
{
    if(root == NULL)
        printf("Element not found\n");
    ///Recursive function call to find node to be deleted
    else if(root->data > value)
        root->left = delete_node_val(root->left, value);
    else if(root->data < value)
        root->right = delete_node_val(root->right, value);
    else
    {
    ///If node is a leaf node
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        root = NULL;
    }
    ///Node has a right child case
    else if(root->left == NULL)
    {
        bst_t *ret = root;
        root = root->right;
        free(ret);
    }
    ///Node has a left child
    else if(root->right == NULL)
    {
        bst_t *ret = root;
        root = root->left;
        free(ret);
    }
    ///Two child case
    else 
    {
        bst_t *ret = root;
        ///Finding successor(min element from the right child)
        bst_t *temp = find_min_element(root->right);
        root->data = temp->data;
        root->right = delete_node_val(root->right, temp->data);
    }
    }
    return root;
}        
