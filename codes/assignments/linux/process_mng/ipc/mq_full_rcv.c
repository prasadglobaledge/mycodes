#include "header.h"

#define SIZE 50
#define SIZE1 200
#define MAX_MSG 10
#define MAX_MSGSZ 100
#define NO_MSG 0
#define FLAG 0

int main (int argc, char *argv[]) 
{
    mqd_t md;
    mqd_t md1;
    char *str = NULL;
    int choice = 0;
    struct mq_attr *attr;
    int status;
    char *str1 = NULL;

    str = (char *) malloc (SIZE * sizeof (char));
    assert (str);
    str1 = (char *) malloc (SIZE1 * sizeof (char));
    assert (str);


    attr -> mq_flags = FLAG;
    attr -> mq_maxmsg = MAX_MSG;
    attr -> mq_msgsize = MAX_MSGSZ;
    attr -> mq_curmsgs = NO_MSG;

    while (1){

                 md1 = mq_open (*(argv + 2), O_CREAT | O_WRONLY, 0777, attr);
                 if (md1 == -1){
                     perror ("mq_open failed\n");
                     exit (1);
                }

                while (1){
                    printf ("enter the messgage\n");
                    fgets (str, SIZE, stdin);
                    status = mq_send (md1, str, strlen(str), 0);
                    if (status != 0){
                        perror ("message sending failed\n");
                        exit (1);
                    }
		        if (strcmp (str, "end\n") == 0){
                    printf ("terminating the mq\n");
                    exit (1);
		            }
                }   
                
            md = mq_open (*(argv + 1), O_RDONLY);
            if (md == -1){
                perror ("opening a mq is failed\n");
                exit (1);
            }
    
            while (1){
                status = mq_receive(md, str1, SIZE1, NULL);
	            if (strcmp ("end\n", str1) == 0){
		        break;
	            }
                if (status < 0){
                perror ("receiving of messages is failed\n");
                exit (1);
                }
                if (strcmp (str1, "end\n") == 0){
                    printf ("terminating the mq\n");
                    exit(1);
                }
            printf ("the received msg is : %s\n", str1);
            }
        }

    mq_unlink (*(argv + 1));
    mq_unlink (*(argv + 2));
    mq_close (md);

    return 0;

}
