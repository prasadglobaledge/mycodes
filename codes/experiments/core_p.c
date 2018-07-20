#include <stdio.h>
#include <unistd.h>
int main(void)
{
    int *ptr = NULL;
    printf("%d\n",getpid());
    getchar();
    return 0;
}
