#include "signal_p.h"

void sig_handler (int signum);

int main (void) 
{
    printf ("i am a main\n");

    signal(SIGINT, sig_handler);
    //pause ();
    kill(getpid (), SIGINT);
   // pause ();

    return 0;
}

void sig_handler (int signum)
{
    printf("i am a signal handler\n");
    signal (SIGINT, main);
    kill (getpid (), SIGINT);

}
