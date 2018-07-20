#include<stdio.h>
int sort(int arr2[]);
int main()
{
    int *arr1 = NULL;
    int *arr2 = NULL;
    int ind1,ind2=0;
    int count = 0;

    arr1 = (int *) malloc(sizeof(int) * MIN);
    arr2 = (int *) malloc(sizeof(int) * MAX);

    if(arr1 == NULL || arr2 == NULL) 
    {
        printf("MA failed\n");
        exit(1);
    }
    
    while(ind1 < 3)
    {
        *(arr1+ind1) = rand() 
    }

    for(ind1 = 0;ind1 < 7;ind1++)
    {
        if(arr2[ind1])
        {
            count++;
        }
    }
    while(count < 7)
    {
        arr2[count] = arr1[ind2];
        count++;
        ind2++;
    }
    sort(arr2);
    ind1 = 0;
    ind2 = 0;
    while(ind1 < 7)
    {
        if(arr2[ind1] == arr2[ind1+1])
        {
            arr2[ind1] = 0;
        }
        ind1++;
    }
    sort(arr2);
    ind1 = 0;
    printf("the elements of array after insertion and sorting are \n");
    while(ind1 < 7)
    {
        printf("%d\n", arr2[ind1]);
        ind1++;
    }
    return 0;

}

int sort(int arr2[])
{
    int ind1,ind2;
    int temp;

    for(ind1 = 0;ind1 < 7;ind1++)
    {
        for(ind2 = 0;ind2 < 7;ind2++)
        {
            if(arr2[ind1] > arr2[ind2])
            {
                temp = arr2[ind1];
                arr2[ind1] = arr2[ind2];
                arr2[ind2] = temp;
            }
        }
    
    }
}
