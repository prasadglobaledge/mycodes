#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
void *thread_create1(void *p)
{
	printf("i am a thread from a thread\n");
	printf("thread2 t_tid = %ld\nt_tgid = %d\n", syscall(SYS_gettid), getpid());
	sleep(10);
}
void *thread_create (void *p)
{
	int status;
	pid_t pd;
	
	pthread_t th1_id;
	printf("th_id %x\n", pthread_self());
	pd= fork();

	if(pd > 0){
		printf("process from thread1 :%d\n", getpid());
		status = pthread_create(&th1_id, NULL, thread_create1, NULL);
		if(status != 0){
			printf("thread is not created : %d\n", strerror(status));
		}
		wait(NULL);
	}
	else{
		printf("child process from thread : %d\n",  getpid());
		sleep(2);
	}
    printf("thread1 t_tgid = %d\nt_tid = %ld\n", getpid(), syscall(SYS_gettid));
}

int main (void)
{
    pthread_t th_id;
    int status;
    pid_t pd;

   pd = fork();

   if(pd > 0){
	printf("parent pid is : %d\n", getpid());
   	 status = pthread_create(&th_id, NULL, thread_create, NULL);
    	 if(status != 0){
         printf("thread is not created : %d\n ", strerror(status));
    	}
	sleep(5);
   }
   else{
	printf("child pid  : %d\n", getpid());
	sleep(4);
	
	}
    printf("t_tgid = %d\nt_tid = %ld\n", getpid(), syscall(SYS_gettid));

	printf("tid by self%u\n", pthread_self());
    pthread_exit(NULL);
    
    return 0;
}
