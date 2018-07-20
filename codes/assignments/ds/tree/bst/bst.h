/**
 * @brief bst header file
 * ***/
#include <stdio_ext.h>
#define SIZE 10
///Structure declaration
typedef struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
}bst_t;
char str[SIZE];
int value;
///Prototype of all functions
bst_t* insert_element(bst_t *root);
bst_t* insert_value(bst_t *root, int value);
bst_t* create_node(int value);
void display_tree(bst_t *root);
void in_order(bst_t *root);
void pre_order(bst_t *root);
void post_order(bst_t *root);
void search_tree(bst_t *root);
bst_t* search_element(bst_t *root, int value);
void find_min(bst_t *root);
bst_t* find_min_element(bst_t *root);
bst_t* find_max_element(bst_t *root);
void find_max(bst_t *root);
bst_t* delete_element(bst_t *root);
bst_t* delete_node_val(bst_t *root, int value);
