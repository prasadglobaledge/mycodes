#include<stdio.h>
#include<stdlib.h>
#define SIZE 100 //size of the array

int main (void)
{
    int *arr = NULL; //pointer to array 
    int index;
    int flag = 0;  //index valuei

   if(NULL == (arr = (int *) malloc ( SIZE * sizeof(int) ))) //memory allocated dynamically
           {
             printf("MA failed\n");
             exit(1);
           }

    for ( index = 0; index < SIZE; index++)
    {
        *(arr + index) = rand() % 100 + 1;
        if(*(arr+index) == index)     //comparing index with value
        {
            flag++;
            if(flag == 2)
            {
                *(arr + index) = rand() % 1; /*replacing the other matched 
                                                value with random value*/
                printf("%d\t%d\n", index, *(arr + index));\
                continue;
            }
            printf("%d\t%d\n", index, *(arr + index));
            printf("element entered and the array index are same : %d==%d\n"\
                    , index, *(arr + index));
           // break;
        }
        printf("%d\t%d\n", index, *(arr + index));
    }
    return 0;
}
