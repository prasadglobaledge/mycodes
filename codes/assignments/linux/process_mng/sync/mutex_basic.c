#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static int a = 10;

void *thread (void *ptr)
{
    while (a < 25){
       pthread_mutex_lock(&mutex);
        printf("i am a sub thread1 : %d\n", ++(a));
        pthread_mutex_unlock(&mutex);
    }
}
void *thread1 (void *ptr)
{
    while (a < 50){
        pthread_mutex_lock(&mutex);
        printf("i am a sub thread2 : %d\n", ++(a));
        pthread_mutex_unlock(&mutex);
    }
}




int main (void)     
{
    pthread_t th_id;
    int status;
    pthread_t th1_id;

    /*a = (int) malloc (sizeof(int));
    assert(a);

    a = 25;
    pthread_mutex_init (&mutex, NULL);*/

    status = pthread_create(&th_id, NULL, thread, NULL);
    if(status != 0){
        printf("thread is not created : %s\n", strerror(status));
    }
//    pthread_join (th_id, NULL);

    status = pthread_create(&th1_id, NULL, thread1, NULL);
    if(status != 0){
        printf("thread is not created : %s\n", strerror(status));
    }
    /*while (a < 25){
        pthread_mutex_lock(&mutex);
        printf("i am a main thread : %d\n", ++a);
        pthread_mutex_unlock(&mutex);
    }*/
    pthread_join(th1_id, NULL);
    pthread_mutex_destroy (&mutex);
    return 0;

}

