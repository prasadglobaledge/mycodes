/**@brief Implementation of Dynamic circular dobly linked list*/

///header guards
#ifndef CDLL_HEADERS_H
#define CDLL_HEADERS_H

///header files
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

///structure decalration
typedef struct main_list{
    struct main_list *prev; //to hold the address of previous node
    struct mani_list *below; //to hold the address of sublist
    int info = 0;  //to hold the data
    struct main_list *next; //to hold the address of next node
}MAIN;

///structure declarations
typedef struct sub_list{
    struct sub_list *pr_sub; //to hold the address of the previous node
    int data; //to hold the data
    struct sub_list *nxt_sub; //to hold the address of the next node
}SUB;

///enum declaration
enum tag {Create_begin = 1, Create_end, Insert_value, Delete_value, Search, 
          Display, Exit}; //to select the choice of operations

///functions declarations
MAIN create_begin(MAIN *head);
MAIN create_end(MAIN *head);
MAIN insert_pos()
