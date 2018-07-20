#include <stdio.h>
#include <unistd.h>
int main (void)
{
    pid_t pd;

    pd = fork();

    if(pd > 0){
        printf("the process id of parent is :%d\n", getpid());

    }


    else{
        printf("child process id is:%d\n", getpid());

    }

   wait(NULL);

    return 0;
    
}
