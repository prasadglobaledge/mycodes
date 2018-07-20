#include <stdio.h>
#include <stdlib.h>
struct tag{
    struct tag1 {
    int a :10;
    int *b;
    };
};

int main (void) 
{

    printf ("%d\n", sizeof (struct tag));
    
    return 0;
}
