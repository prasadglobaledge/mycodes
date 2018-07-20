/**
 * @brief To find the minimum value in the tree
 * **/
#include "bst.h"
///Function definition to print minimum value of tree
void find_min(bst_t *root)
{
    ///Checking for empty tree
    if(root == NULL)
    {
        printf("Tree already empty\n");
        return;
    }
    ///Function call to find minimum
    bst_t *temp = find_min_element(root);
    printf("Minimum value in tree is %d\n", temp->data);
}
bst_t* find_min_element(bst_t *root)
{
    ///Recursively moving to left node
    if(root->left != NULL)
        return find_min_element(root->left);
    return root;
}
