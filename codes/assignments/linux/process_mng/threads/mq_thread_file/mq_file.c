#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>


#define SIZE 200

FILE *fp = NULL;
char *str = NULL;
FILE *fp1 = NULL;

void *thread_create1(void *mq)
{
	int count = 0;
    	ssize_t status = 0;
	int res = file_size(fp, count);
	int blocks = (res/4);
	int *ptr = NULL;
	ptr = (int *)mq;

    status = mq_receive (*ptr, str, SIZE, NULL);
    printf("%s\n", str);
    if(status == -1){
        printf ("receive failed in th1 : %s\n", strerror (status));
        exit (1);
    }
    fwrite (str, sizeof (char), blocks, fp1);    
}

void *thread_create2(void *mq)
{
    int count = 0;
    ssize_t status = 0;
    int res = file_size(fp, count);
    int blocks = (res/4);
	int *ptr = NULL;
	ptr = (int *)mq;
   
    status = mq_receive (*ptr, str, SIZE, NULL);
    if(status == -1){
        printf ("receive failed in th1 : %s\n", strerror (status));
        exit (1);
    }
    fwrite (str, sizeof (char), blocks, fp1);    
	
}

void *thread_create3(void *mq)
{
    int count = 0;
    ssize_t status = 0;
    int res = file_size(fp, count);
    int blocks = (res/4);
	int *ptr = NULL;
	ptr = (int *)mq;

    status = mq_receive (*ptr, str, SIZE, NULL);
    if(status == -1){
        printf ("receive failed in th1 : %s\n", strerror (status));
        exit (1);
    }
    fwrite (str, sizeof (char), blocks, fp1);    

}

void *thread_create4(void *mq)
{
    int count = 0;
    int res = file_size(fp, count);
    ssize_t status = 0;
    int blocks = (res/4);
	int *ptr = NULL;
	ptr = (int *)mq;

    status = mq_receive (*ptr, str, SIZE, NULL);
    if(status == -1){
        printf ("receive failed in th1 : %s\n", strerror (status));
        exit (1);
    }
    fwrite (str, sizeof (char), blocks, fp1);    

}

int main (int argc, char *argv[])
{
	int status;
	pthread_t th_id;
	pthread_t th_id1;
	pthread_t th_id2;
	pthread_t th_id3;
    mqd_t mq;

	fp = fopen (*(argv + 1), "r");
	assert(fp);
    fp1 = fopen (*(argv + 2), "w");
    assert (fp1);

	str = (char *)malloc(SIZE * sizeof(char));
	assert(str);

    mq = mq_open (*(argv + 3), O_RDONLY);
    if (mq == -1){
        printf("mq open failed : %s\n", strerror (mq));
        exit (1);
    }

	status = pthread_create (&th_id, NULL, *thread_create1, &mq);
	if(status != 0){
		printf("thread is not created : %s\n", strerror(status));
	}
	pthread_join(th_id, NULL);

	status = pthread_create (&th_id1, NULL, *thread_create2, &mq);
	if(status != 0){
		printf("thread is not created : %s\n", strerror(status));
	}
	pthread_join(th_id1, NULL);
	
	status = pthread_create (&th_id2, NULL, *thread_create3, &mq);
	if(status != 0){
		printf("thread is not created : %s\n", strerror(status));
	}
	pthread_join(th_id2, NULL);
	
	status = pthread_create (&th_id3, NULL, *thread_create4, &mq);
	if(status != 0){
		printf("thread is not created : %s\n", strerror(status));
	}
	pthread_join(th_id3, NULL);

	fclose(fp);
    fclose(fp1);

	return 0;
}
int file_size(FILE *fp,long int count)
{
    fseek(fp, 0, SEEK_END);
    count = ftell(fp);

    return count;
}

