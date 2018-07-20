#include"header.h"
NODE *front==NULL:
int main()
{
    int i=0;
    NODE *newnode;
    for(i=0;i<20;i++)
    {




}
NODE *create_node()
{
    NODE *newnode;
    int i=0;

    newnode=(NODE *)malloc(sizeof(NODE));
    if(newnode==NULL)
    {
        printf("MA failed\n");
        exit(1);
    }
    
    printf("enter the name of contributor\n");
    fgets(nenode->name,columns,stdin);

    printf("enter the suggestions\n");
    for(i=0;i<3;i++)
    {
        fgets(newnode->*sugg[i],columns,stdin);    
    }
    printf("enter the difference\n");
    for(i=0;i<3;i++)
    {
        fgets(newnode->*diff[i],columns,stdin);
    }
    newnode->next=NULL;
    return newnode;
}

