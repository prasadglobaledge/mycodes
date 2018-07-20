#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100
#define SUCCESS 1
#define FAIL -1
#define EMPTY 0

struct employee
{
    char name[SIZE];
    int id_num;
    struct DOB
    {
        int day;
        int month;
        int year;
    }a;
    char blood[SIZE];
    struct employee *next;
}b;
typedef struct employee NODE;
//typedef struct DOB dob;

NODE *create_node();
int insert_begin();
int insert_end();
int insert_at_pos();
void display();
/*int delete_begin();
int delete_end();
int delete_at_pos();
int search();
int reverse();*/
