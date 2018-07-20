#include "header.h"

void *thread1 (void *p);
void *thread2 (void *p);
void *thread3 (void *p);
void *thread4 (void *p);

int a = 1;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *thread1 (void *ptr)
{
    pthread_mutex_lock (&mutex);
    while (a < 5){
        a++;
    }
    if (a >= 5){
        pthread_cond_signal (&cond);
    }
    pthread_mutex_unlock (&mutex);
    printf("the value of a after thread1 is : %d\n", a);
}

void *thread2 (void *ptr)
{
    if (a < 5){
        pthread_cond_wait (&cond, &mutex);
    }
    pthread_mutex_lock (&mutex);
    while (a < 10){
        a++;
    }
    if (a >= 10){
        pthread_cond_signal (&cond);
    }
    pthread_mutex_unlock (&mutex);
    printf("the value of a after thread2 is : %d\n", a);
}
void *thread3 (void *ptr)
{
    if (a < 10){
        pthread_cond_wait (&cond, &mutex);
    }
    pthread_mutex_lock (&mutex);
    while (a < 15){
        a++;
    }
    if (a >= 15){
      pthread_cond_signal (&cond);
    }
    pthread_mutex_unlock (&mutex);
    printf("the value of a after thread3 is : %d\n", a);
}
void *thread4 (void *ptr)
{
    if (a < 15){
        pthread_cond_wait (&cond, &mutex);
    }
    pthread_mutex_lock (&mutex);
    while (a < 20){
        a++;
    }
    if (a >= 20){
        pthread_cond_signal (&cond);
    }
    pthread_mutex_unlock (&mutex);
    printf("the value of a after thread4 is : %d\n", a);
}

int main (void) 
{
    pthread_t th1;
    pthread_t th2;
    pthread_t th3;
    pthread_t th4;
    int status1;
    int status2;
    int status3;
    int status4;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init (&cond, NULL);

    status1 = pthread_create (&th1, NULL, thread1, NULL);
    if (status1 != 0){
        printf ("creating a thread is failed : %s\n", strerror (status1));
        exit (1);
    }
    pthread_join (th1, NULL);
    
    status2 = pthread_create (&th2, NULL, thread2, NULL);
    if (status2 != 0){
        printf ("creating a thread is failed : %s\n", strerror (status2));
        exit (1);
    }
    pthread_join (th2, NULL);

    status3 = pthread_create (&th3, NULL, thread3, NULL);
    if (status3 != 0){
        printf ("creating a thread is faile : %s\n", strerror (status3));
        exit (1);
    }
    pthread_join (th3, NULL);

    status4 = pthread_create (&th4, NULL, thread4, NULL);
    if (status4 != 0){
        printf ("creating a thread is faile : %s\n", strerror (status4));
        exit (1);
    }
    pthread_join (th4, NULL);

    printf ("value of a after the completon of all threads : %d\n", a);

    pthread_cond_destroy (&cond);
    pthread_mutex_destroy (&mutex);
    pthread_exit (NULL);

    return 0;
}
