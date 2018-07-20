/**@brief Pseudo driver module adding and removing to kernel*/
///header files
#include <string.h>
#include <stdio.h> 
#include <fcntl.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>

int num = 10;

void *thread_create1(void *p)
{
	int fd;
	int ret;

	fd = open("/dev/mychar", O_RDWR);
	if(fd < 0){
		printf("unable to open the file\n");
	}
	ret = ioctl (fd, 1, &num);
	
        printf("i am a thread from a thread\n");
        printf("thread2 t_tid = %ld\nt_tgid = %d\n", syscall(SYS_gettid), getpid());
}
void *thread_create (void *p)
{
        int status;
        pid_t pd;
	int ret;
	int fd;

        pthread_t th1_id;

        pd= fork();

        if(pd > 0){
                printf("process from thread :%d\n", getpid());
                status = pthread_create(&th1_id, NULL, thread_create1, NULL);
                if(status != 0){
                        printf("thread is not created : %d\n", strerror(status));
                }

	fd = open("/dev/mychar", O_RDWR);
	if(fd < 0){
		printf("unable to open the file\n");
	}
	ret = ioctl (fd, 1, &num);
        }
        else{
                printf("child process from thread : %d\n",  getpid());
	fd = open("/dev/mychar", O_RDWR);
	if(fd < 0){
		printf("unable to open the file\n");
	}
	ret = ioctl (fd, 1, &num);
        }
    printf("thread1 t_tgid = %d\nt_tid = %ld\n", getpid(), syscall(SYS_gettid));
}

int main (void)
{
    pthread_t th_id;
    int status;
    pid_t pd;
    int fd;
    int ret;

   pd = fork();

   if(pd > 0){
        printf("parent pid is : %d\n", getpid());
         status = pthread_create(&th_id, NULL, thread_create, NULL);

	 if(status != 0){
         printf("thread is not created : %d\n ", strerror(status));
        }
	fd = open("/dev/mychar", O_RDWR);
	if(fd < 0){
		printf("unable to open the file\n");
	}
	ret = ioctl (fd, 1, &num);
   }
   else{
        printf("child pid  : %d\n", getpid());
	fd = open("/dev/mychar", O_RDWR);
	if(fd < 0){
		printf("unable to open the file\n");
	}
	ret = ioctl (fd, 1, &num);
    }
    printf("t_tgid = %d\nt_tid = %ld\n", getpid(), syscall(SYS_gettid));

    pthread_exit(NULL);

    return 0;
}
       
