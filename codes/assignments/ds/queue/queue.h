#include<stdio.h>
#include<stdlib.h>
#define SIZE 8

int queue[SIZE];

void enqueue(int element);
void dequeue();
void isempty();
void isfull();
int size();
int front_element();
int rear_element();
void display();
