#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sched.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

#define SIZE 8192

void *thread (void *p)
{
    printf("I am in a thread with tid :%d\n", gettid());
}

int main (void) 
{
    int pd;
    int *ptr = NULL;

    ptr = (int *) malloc (SIZE);
    assert (ptr);

    pd = clone (thread, ptr, CLONE_VFORK, NULL);
    if (pd == -1){
        printf("clone error\n");
        exit(1);
    }
}
