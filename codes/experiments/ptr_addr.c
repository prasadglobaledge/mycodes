#include<stdio.h>
#include<stdlib.h>
int main (void)
{
    int a = 10;
    int **p = NULL;

    p =  malloc(sizeof(int *));
    *p = malloc(sizeof(int ));

    if(p == NULL)
    {
        exit(1);
    }
    *p=&a;

    printf("%p\n %p\n %p\n %p\n %d\n %d\n %d\n", p, p++, *p, *p++, **p, **p++, *(p)++);
    return 0;
}
