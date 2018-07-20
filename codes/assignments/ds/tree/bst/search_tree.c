/**
 * @brief Searching for any element present in tree or not
 * **/
#include "bst.h"
///Function definition for searching element
void search_tree(bst_t *root)
{
    ///Empty tree
    if(root == NULL)
    {
        printf("Tree already empty\n");
        return;
    }
    bst_t *ret = NULL;
    ///Prompt for search key
    printf("Enter value to be searched\n");
    fgets(str, SIZE, stdin);
    __fpurge(stdin);
    value = my_atoi(str);

    ///Function call for searching
    ret = search_element(root, value);
    (ret == NULL)?printf("Value not found\n"): printf("%d found\n", ret->data);
}
///Function definition for search
bst_t* search_element(bst_t *root, int value)
{
    if(root != NULL)
    {
        ///Recursive search call till value matches or NULL occurs
        if(root->data > value)
            return search_element(root->left, value);
        else if(root->data < value)
            return search_element(root->right, value);
        else
            return root;
    }
    return NULL;
}
