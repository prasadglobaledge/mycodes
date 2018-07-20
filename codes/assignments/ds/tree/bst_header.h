#ifndef BST_HEADER_H
#define BST_HEADER_H

#include "header.h"

#define SUCCESS 1
#define FAIL 0

typedef struct node{
    struct node *lnext;
    int info;
    struct node *rnext;
}NODE;

enum tag {Insertion = 1, Deletion, Post_Traversal, Pre_traversal, In_Traversal,
          Search_node};

NODE *create_node();
int insertion();
int deletion();
int post_traversal();
int pre_traversal();
int in_traversal();
int search_node();

#endif

