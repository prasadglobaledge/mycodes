#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 200

FILE *fp = NULL;
FILE *fp1 = NULL;
char *str = NULL;

void *thread_create1(void *p)
{
	int count = 0;
	int res = file_size(fp, count);
	int blocks = (res/4);
	
	rewind(fp);	
	
	fread(str, blocks, 1, fp);
        fwrite(str,blocks, 1, fp1);
}

void *thread_create2(void *p)
{
        int count = 0;
        int res = file_size(fp, count);
        int blocks = (res/4);
	
	rewind(fp);	
	fseek (fp, blocks, SEEK_SET);
        fread(str, blocks, 1, fp);
        fwrite(str,blocks, 1, fp1);
}

void *thread_create3(void *p)
{
        int count = 0;
        int res = file_size(fp, count);
        int blocks = (res/4);

	rewind(fp);	
	fseek (fp, (blocks * 2), SEEK_SET);
        fread(str, blocks, 1, fp);
        fwrite(str,blocks, 1, fp1);
}

void *thread_create4(void *p)
{
        int count = 0;
        int res = file_size(fp, count);
        int blocks = (res/4);

	rewind(fp);	
	fseek (fp, (blocks * 3), SEEK_SET);
        fread(str, blocks, 1, fp);
        fwrite(str,blocks, 1, fp1);
}

int main (void)
{
	int status;
	pthread_t th_id;
	pthread_t th_id1;
	pthread_t th_id2;
	pthread_t th_id3;

	fp = fopen ("file1.txt", "r");
	fp1 = fopen ("file2.txt", "w");

	assert(fp);
	assert(fp1);

	str = (char *)malloc(SIZE * sizeof(char));
	assert(str);

	status = pthread_create (&th_id, NULL, *thread_create1, NULL);
	if(status != 0){
		printf("thread is not created : %s\n", strerror(status));
	}
	pthread_join(th_id, NULL);

	status = pthread_create (&th_id1, NULL, *thread_create2, NULL);
	if(status != 0){
		printf("thread is not created : %s\n", strerror(status));
	}
	pthread_join(th_id1, NULL);
	
	status = pthread_create (&th_id2, NULL, *thread_create3, NULL);
	if(status != 0){
		printf("thread is not created : %s\n", strerror(status));
	}
	pthread_join(th_id2, NULL);
	
	status = pthread_create (&th_id3, NULL, *thread_create4, NULL);
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

