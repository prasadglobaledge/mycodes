/* Basava prasad s j (31067)
 *14th april 2018 : started to create a single linked list with all possible
                    conditions*/


#ifndef SLL_HEADERS_H   /** including header guards*/
#define SLL_HEADERS_H  /**defining the header if it is not defined*/

#include "headers.h"  /**including header file*/

#define SIZE 100   ///macro definition
#define SUCCESS 1 ///macro definition
#define FAIL -1  ///macro definition
#define EMPTY 0 ///macro definition


///@var

typedef struct node{      
                            /**@brief structure with two fields info and address of next*/
    int info;       
    struct node *next;
}NODE;


//NODE *head = NULL;    /*if head node is not declared globally then after all 
                        // the operation return the head node*/

enum tag{Insert_begin = 1, Insert_end, Insert_pos, Display, Delete_begin,
        Delete_end, Delete_pos, Search_node, /*reverse_list*/}; /**enum datatyp
                                        e to specify the operation*/

/// function declarations ///

NODE *create_node(); 
int insert_begin(); 
int insert_end();
int insert_any_pos();
int delete_begin();
int delete_end();
int delete_any_pos();
int display();
int search_node();

#endif   ///end of conditional compilations
//int reverse_list();

/*if the head node is not declared globally pass the head node as arguement to
the function and return the head node after completion*/
