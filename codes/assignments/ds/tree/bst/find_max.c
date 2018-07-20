/**
 * @brief Function to find maximum value in tree
 * **/
#include "bst.h"
///Function definition to get maximum value of tree
void find_max(bst_t *root)
{
    ///Checking for empty tree
    if(root == NULL)
    {
        printf("Tree already empty\n");
        return;
    }
    ///Function call to find maximum
    bst_t *temp = find_max_element(root);
    printf("Maximum value in tree is %d\n", temp->data);
}
///Definition for find maximum
bst_t* find_max_element(bst_t *root)
{
    ///Recursively moving to right node
    if(root->right != NULL)
        return find_max_element(root->right);
    return root;
}
