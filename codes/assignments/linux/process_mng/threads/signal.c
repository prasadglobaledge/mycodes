#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

void catch_signal (int num)
{
    printf("now the signal has been occured\n");
   fflush (stdin);
   exit(1);
}
int main (void) 
{
    pthread_t th_id;
    int status;
   
    status = signal (SIGINT, catch_signal);
   while (1){
       printf("i");
   } 

    pause();
   // kill(getpid(), SIGINT);
    if(status != 0){
        printf("signal is not occured : %s\n", strerror (status));
    }
    return 0;
}
