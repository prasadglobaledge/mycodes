#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) 
{
    pid_t pd;

    pd = fork ();
    if (pd > 0){
        execve(argv[1], argv[2], NULL);
        printf ("i am a parent process with pid = %d\n", getpid());
        wait(NULL);
    }
    else{
        execve(argv[1], argv[2], NULL);
    }
    return 0;

}
