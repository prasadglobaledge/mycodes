/* headers and function declarations of the sorting techniques*/

#ifndef SORT_HEADERS_H
#define SORT_HEADERS_H

#include "headers.h"

#define SIZE 10
#define SUCCESS 1
#define FAIL 0

int array[SIZE];  //defining an array of integers of size SIZE

/// functions declarations ////

int selection_ascending();
int selection_descending();
int bubble_ascending();
int bubble_descending();
int insertion_ascending();
int insertion_descending();
int merge_ascending();
int merge_descending();
int quick_ascending();
int quick_descending();

/// declaring a enum ///

enum tag {Selection_A = 1, Selection_D, Bubble_A, Bubble_D, Insertion_A,
           Insertion_D, Merge_A, Merge_D, Quick_A, Quick_D };

#endif

