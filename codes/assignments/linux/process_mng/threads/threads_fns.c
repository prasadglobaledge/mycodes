#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>

static int a = 10;

void *thread_create (void *p)
{
    a = 30;
    printf("now i am in thread1: %d\n", (int)pthread_self());
}

void *thread1_create (void *p)
{
    printf("i am thread2 now\n");
}

int main (void) 
{
    pthread_t th_id;
    pthread_t th1_id;
    int status;

    status = pthread_create (&th_id, NULL, thread_create, NULL);
    pthread_detach(th_id);
    if(status != 0){
       printf("creation of thread failed : %s\n", strerror(status));
    }
    
    printf("thread1 is completed\n");

    status = pthread_create (&th1_id, NULL, thread1_create, NULL);
    if(status != 0){
        printf("creation of thread failed : %s\n", strerror(status));
    }
    pthread_detach (th_id);
    pthread_detach (th_id);
    pthread_join (th_id, NULL);
    printf("thread2 is completed\n");
    pthread_exit(NULL);    

    return 0;
}
