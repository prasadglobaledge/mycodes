/**
 * @brief Display function to print elements of tree 
 * **/
#include "bst.h"
///Function definition for displaying tree elements
void display_tree(bst_t *root)
{
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    ///Prompt for evaluation order
    printf("Choose order of printing\n");
    printf("1.In_order\n2.Pre_order\n3.Post_order\n");
    fgets(str, SIZE, stdin);
    __fpurge(stdin);
    value = my_atoi(str);
    switch(value)
    {
        ///In order evaluation
        case 1:printf("In order evaluation of tree\n");
               in_order(root);
               break;
               ///Pre order evaluation
        case 2:printf("Pre order evaluation of tree\n");
               pre_order(root);
               break;
               ///Post order evaluation
        case 3:printf("Post order evaluation of tree\n");
               post_order(root);
               break;
        default:printf("ERROR!Invalid input\n");
                break;
    }
}
///Function definition for in order
void in_order(bst_t *root)
{
    if(root != NULL)
    {
        ///Recursively moving to left node
        in_order(root->left);
        printf("%d\n", root->data);
        ///Recursively moving to right node
        in_order(root->right);
    }
}
///Function definition for pre order
void pre_order(bst_t *root)
{
    if(root != NULL)
    {
        ///Printing parent data
        printf("%d\n", root->data);
        ///Recursively moving to left and right nodes
        pre_order(root->left);
        pre_order(root->right);
    }
}
///Function definition for post order
void post_order(bst_t *root)
{
    if(root != NULL)
    {
        ///Recursively moving to left and right nodes
        post_order(root->left);
        post_order(root->right);
        printf("%d\n", root->data);
    }
}
