#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
int *fun()
{
    static int a = 0;
    a++;

    printf("%d\n",a);
    if((a ^ 0xf) && (main() == 10)){
        --a;
        return &a;
    }
}
int main()
{
    
    printf("%d\n", getpid());
//    getchar();
    printf("%p\n", ((*fun())));
}
