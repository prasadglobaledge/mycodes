#include"header.h"


NODE *front=NULL;
int main()
{
    float &details;
    NODE *newnode;
    newnode=create_node();
    int i,j;

    for(i=0;i<3;i++)
    {
        printf("enter the details of sessions\n");
        scanf("%lf",&details);
        
        if(details > newnode->class_session)
            {
                strcpy(newnode->*excetion_ind[i],"Efoort is lower than average");
            }
        else if(details < newnode->class_session)
        {
            strcpy(newnode->*exception_ind[i],"GREAT work keep it up");        
        }
        else
        {
            nenode->*exception_ind[i]='\n';
        }
    }
    printf("-----------------------------------------------------------------\n");
    printf("#\n\n 1.\n\n 2.\n\n 3.\r\t Running daily \n\t Average\n\n 4.5\n\n 2.5\n\n 5.5\r\t\t Today's effort\n\t\t in Hours\n\n ");

}
NODE *create_node()
{
    NODE *newnode;

    newnode=(NOdE *)malloc(sizeof(NODE));
    if(newnode==NULL)
    {
        printf("MA failed\n");
        exit(1);
    }
    printf("enter the date\n");
    fgets(newnode->date,SIZE,stdin);

    printf("enter the classroom session timings\n ");
    scanf("%lf",&newnode->class_session);

    printf("enter the assignment timings\n");
    scanf("%lf",&newnode->assignment);

    printf("enter the self study timings\n");
    scanf("%lf",&newnode->self_study);

    newnode->next=NULL;
    return newnode;
}
