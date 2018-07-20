#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    int total;
    while(1){
        ptr = malloc(1);
        total = malloc_stats(ptr);
        printf("%d\n",total);
    }
    free(ptr);
    return 0;
}
