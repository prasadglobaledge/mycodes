#include"employee_cll.h"

NODE *first = NULL;

NODE *create_node()
{
    int id;
    int date, month, year;
    char *str = NULL;
    NODE *newnode = NULL;

    str = (char *)malloc(sizeof(char) * SIZE);
    if(str == NULL){

        printf("MA failed\n");
        exit(1);
    }

    newnode = (NODE *)malloc(sizeof(NODE));
    if(newnode == NULL){

        printf("node creation failed\n");
        exit(1);
    }
    printf("enter the employee id number\n");
    __fpurge(stdin);
    fgets(str, SIZE, stdin);
    id = atoi(str);

    newnode->id_num = id;

    printf("enter the Name\n");
    __fpurge(stdin);
    fgets(str, SIZE, stdin);

    strcpy(newnode->name, str);

    printf("enter the blood group\n");
    __fpurge(stdin);
    fgets(str, SIZE, stdin);

   strcpy(newnode->blood, str);

    printf("enter the date and month and year\n ");
    __fpurge(stdin);
    fgets(str, SIZE, stdin);
    date = atoi(str);

    newnode->a.day = date;

    __fpurge(stdin);
    fgets(str, SIZE, stdin);
    month = atoi(str);

    newnode->a.month = month;
 
    __fpurge(stdin);
   year = atoi(fgets(str, SIZE, stdin));

    newnode->a.year = year;

    newnode->next = NULL;
    return newnode;
}

int insert_begin()
{
    NODE *cur = NULL;
    NODE *newnode = NULL;
    newnode = create_node();
    
    if(first == NULL){

        first = newnode;
        return SUCCESS;
    }
    cur = first;
    while(cur->next != first){

        cur = cur->next;
    }
    cur->next = newnode;
    newnode->next = first->next;
    first = newnode;
    return SUCCESS;
}
int insert_end()
{
    NODE *cur = NULL;
    NODE *newnode = NULL;

    newnode = create_node();
    if(first == NULL){

        first = newnode;
        return SUCCESS;
    }
    cur = first;
    while(cur->next != first){
        cur = cur->next;
    }
    cur->next = newnode;
    newnode->next = first;
    return SUCCESS;
}
int insert_at_pos()
{
    NODE *cur = NULL;
    NODE *prev = NULL;
    NODE *newnode = create_node();
    int pos;
    int i = 1;
    char *str = NULL;

    str = (char *)malloc(SIZE * sizeof(char));
    if(str == NULL){

        printf("MA failed\n");
        exit(1);
    }
    printf("enter the postion to insert\n");
    __fpurge(stdin);
    pos = atoi(fgets(str, SIZE, stdin));

    ///if position entered is zero or  negative///

    if(pos <= 0){
        printf("entered position is negative!!! enter proper position\n");
        return FAIL;
    }

    ///if link is empty////
    
    if(first == NULL && pos == 1){
        first = newnode;
        return SUCCESS;
    }
    if(first == NULL && pos > 1){
        printf("entered position is invalid since there is no list present\n");
        return FAIL;
    }

    ////if list is present////
    
    cur =first;
    while(cur->next != first){
        cur = cur->next;
    }
    if(pos == 1){
        newnode->next = first;
        cur->next = newnode;
        first = newnode;
        return SUCCESS;
    }
    cur = first;
    while(cur->next != first && i < pos){
        prev = cur;
        cur = cur->next;
        i++;
    }
    if(cur->next == first && pos == (i+1)){
        cur->next = newnode;
        newnode->next = first;
        return SUCCESS;
    }
    if(cur->next == first && pos > (i+1))
    {
        printf("invalid position\n");
        return FAIL;
    }
    newnode->next = prev->next;
    prev->next = newnode;
    return SUCCESS;
}
/*void display(NODE *first)
{
    NODE *cur = NULL;

    if(first == NULL){
        printf("nothing to display list is empty!!!\n");
    }
    cur = first;
    while(cur->next != first){

        printf("the id no is : %d\n", cur->id_num);
        printf("name of the employee is :");
    //    __fpurge(stdout);
        puts(cur->name);
  //      __fpurge(stdout);
        printf("date of birth of the employee is: %d-%d-%d\n\
                \r" ,cur->a.day, cur->a.month, cur->a.year);
        printf("blood group is :");
//        __fpurge(stdout);
        puts(cur->blood);
        cur = cur->next;
    }
//    return SUCCESS;

}*/
