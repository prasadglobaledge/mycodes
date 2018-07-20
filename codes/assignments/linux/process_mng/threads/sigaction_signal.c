#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <assert.h>

void signal_handle (int signal)
{
    printf("signal changed and handled\n");
    fflush(stdin);
}

int main (void) 
{
    int status;
//    struct sigaction *signal = NULL;

  //  signal -> sa_handler = SIG_IGN;
        
    status = sigaction (SIGINT, SIG_IGN, NULL);
    
    pause();

    if (status != 0){
        printf ("sigaction is failed : %s\n", strerror (status));
    }
    return 0;
}
