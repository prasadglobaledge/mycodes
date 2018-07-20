#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef static int a;

enum tags {};

struct tag{
    int *a;
}*q;

int main (void) 
{
    q = (struct tag *) malloc (sizeof (struct tag));
    assert (q);

    q -> a = (int *) malloc (sizeof (int));
    assert (q -> a);

    return 0;
}
