#include <stdio.h>
#include <errno.h>
#include <assert.h>
int main(void)
{
    FILE *fp = NULL;

    fp = fopen("da", "r");    
    printf("file not opened : %d\n %s\n", errno, strerror(errno));
    return 0;
}
