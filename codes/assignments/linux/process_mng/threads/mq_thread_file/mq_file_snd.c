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


#define SIZE 100
#define MQ_FLAGS 0
#define MQ_MAXMSG 10
#define MQ_MSGSIZE 100
#define MQ_CURMSGS 0
#define LIMIT 4

int main (int argc, char *argv[])
{
	int status;
    mqd_t mq;
    char *str = NULL;
    FILE *fp = NULL;
    int index = 0;
    int count = 0;
    int block_size = 0;
    struct mq_attr *attr;

	attr -> mq_flags = MQ_FLAGS;
    attr -> mq_maxmsg = MQ_MAXMSG;
    attr -> mq_msgsize = MQ_MSGSIZE;
    attr -> mq_curmsgs = MQ_CURMSGS;

    fp = fopen ("text1", "r");
	assert(fp);
	str = (char *)malloc(SIZE * sizeof(char));
	assert(str);
    
    mq = mq_open (*(argv + 1), O_CREAT | O_WRONLY, 0666, attr);
    if (mq == -1){
        printf ("error in opening a mq : %s\n", strerror (mq));
        exit(1);
    }

    count = file_size (fp, count);
    block_size = (count / 4);
    rewind (fp);
    
    while (index < LIMIT){
        fread (str, sizeof (char), block_size, fp);
        status = mq_send (mq, str, block_size, 1);
        if (status == -1){
            printf ("error in sending a msg : %s\n", strerror (status));
            exit (1);
        }
        index ++;
    }
    
    status = mq_close (mq);
    if (status == -1){
        printf ("closing of mq failed : %s\n",  strerror (status));
        exit(1);
    }

    fclose(fp);
	return 0;
}

int file_size(FILE *fp,long int count)
{
    fseek(fp, 0, SEEK_END);
    count = ftell(fp);

    return count;
}

