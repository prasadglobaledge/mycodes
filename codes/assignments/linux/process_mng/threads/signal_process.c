#include "signal_p.h"

void sig_handler (int signum);
void *thread (void *ptr);

int main (void) 
{
    pthread_t th_id;
    struct sigaction signal1;
    int status; 
    pid_t pd;
    int stat = 0;

    pd = fork ();

    if (pd > 0){
        printf ("i am a PARENT process with pid : %d\n", getpid ());
        stat = pthread_create (&th_id, NULL, thread, NULL);
        pthread_join (th_id, NULL);
        signal(SIGALRM, sig_handler);
        alarm(2);
        pause ();
        kill (getpid (), SIGINT);
    }
    else{
        printf ("child process : %d\n", getpid ());

        signal1.sa_handler = sig_handler;
        sigemptyset (&signal1.sa_mask);
        signal1.sa_flags = 0;

        status = sigaction (SIGINT, &signal1, NULL);
        kill (getppid (), SIGINT);
    }
    return 0;
}

void *thread (void *ptr)
{
    printf("i am a thread\n");
}

void sig_handler (int signum)
{
    printf ("now i am executing the signal\n");
}
