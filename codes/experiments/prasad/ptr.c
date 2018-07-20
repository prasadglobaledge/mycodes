#include <stdio.h>
#include <stdlib.h>

int main (void) 
{
    int **ptr = NULL;
    int index = 0;

    ptr = (int **) malloc (sizeof (int *) * 2);
    while (index < 4){
        *(ptr + index) = (int *) malloc (sizeof (int) * 4);
        index++;
    }
    
    return 0;


}
