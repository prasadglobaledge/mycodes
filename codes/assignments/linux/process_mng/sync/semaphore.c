#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sem;
int val = 0;
int data = 0;

void *thread1 (void *ptr)
{
    int i = 0;
    sem_getvalue (&sem, &val);
    while (val != 4){
        sem_getvalue (&sem, &val);
//        printf ("thread1\n");
    }
    printf ("entering thread1\n");
    for (i = 0; i < 5; i++){
        sem_post (&sem);
        printf ("%d\n", ++data);
        sem_wait (&sem);
    }

//    sleep (4);
    printf ("leaving thread1\n");

    sem_wait (&sem);
}

void *thread2 (void *ptr)
{
    int i = 0;
    sem_getvalue (&sem, &val);
    while (val != 3){
        sem_getvalue (&sem, &val);
    //    printf ("thread2\n");
    }
    printf ("entering thread2\n");
      for (i = 0 ; i < 5; i++){
        sem_post (&sem);
        printf ("%d\n", ++data);
        sem_wait (&sem);
    }

    printf ("leaving thread2\n");
  //  sleep (4);

    sem_wait (&sem);
}

void *thread3 (void *ptr)
{
    int i = 0;
    sem_getvalue (&sem, &val);
    while (val != 2){
        sem_getvalue (&sem, &val);
    //    printf ("thread3\n");
    }
    printf ("entering thread3\n");
    for (i = 0; i < 5; i++){
        sem_post (&sem);
        printf ("%d\n", ++data);
        sem_wait (&sem);
    }

   // sleep (4);
    printf ("leaving thread3\n");

    sem_wait (&sem);
}

void *thread4 (void *ptr)
{
    int i = 0;
    sem_getvalue (&sem, &val);
    while (val != 1){
        sem_getvalue (&sem, &val);
    //    printf ("thread4\n");
    }
    printf ("entering thread4\n");
    for (i = 0; i < 5; i++){
        sem_post (&sem);
        printf ("%d\n", ++data);
        sem_wait (&sem);
    }

   // sleep (4);
    printf ("leaving thread4\n");

    sem_wait (&sem);
}
int main (void) 
{
    pthread_t th1, th2, th3, th4;
    pthread_t status = 0;
   // sem_t *sem_val = NULL;

    sem_init (&sem, 0, 4);

    status = pthread_create (&th1, NULL, thread1, NULL);
    if (status < 0){
        perror ("pthread_create1\n");
        exit (0);
    }
    status = pthread_create (&th2, NULL, thread2, NULL);
    if (status < 0){
        perror ("pthread_create2\n");
        exit (0);
    }
    status = pthread_create (&th3, NULL, thread3, NULL);
    if (status < 0){
        perror ("pthread_create3\n");
        exit (0);
    }
    status = pthread_create (&th4, NULL, thread4, NULL);
    if (status < 0){
        perror ("pthread_create4\n");
        exit (0);
    }
    
    sem_destroy (&sem);
    pthread_exit (NULL);

    return 0;
}



