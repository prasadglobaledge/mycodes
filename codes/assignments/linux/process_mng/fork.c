#include <stdio.h>
#include <unistd.h>
int main (void)
{
    pid_t pd;

    pd = fork();
    printf("%d\n", pd);

    if(pd > 0){
        printf("the process id of parent is :%d\n", getpid());
	getchar();
    }
    else{
        printf("child process id is:%d\n", getpid());
    }

    return 0;
    
}
