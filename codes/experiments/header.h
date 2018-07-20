#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 1
#define FAIL 0
#define SIZE 100

static int num=1;

struct ram
{
    char date[SIZE];
    float class_session;
    float assignment;
    float self_study;
    char exception_ind[3][100];
    struct sug_dif *next;
};
typedef struct ram NODE;

NODE *create_node();

