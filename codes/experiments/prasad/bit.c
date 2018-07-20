#include <stdio.h>

struct tag {
    int  :0;

    char b;
}ab;

int main (void)
{
    printf("%d\n", sizeof (ab));

    return 0;
}
