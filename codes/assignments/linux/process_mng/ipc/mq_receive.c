#include "header.h"

#define SIZE 50
#define SIZE1 200
#define MAX_MSG 10
#define MAX_MSGSZ 100
#define NO_MSG 0
#define FLAG 0

void signal_handle(int signum)
{
    printf ("message transfer is done and program terminating with signa\n");
    fflush(stdin);
}

int main (int argc, char *argv[]) 
{
    mqd_t md;
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

   for(;;){
       printf ("enter\t1.SEND\n2.RECEIVE\n");
       choice = atoi(fgets(str, sizeof(int), stdin));

       switch (choice){
           case 1 :
                 md = mq_open (*(argv + 1), O_CREAT | O_WRONLY, 0777, attr);
                 if (md == -1){
                     perror ("mq_open failed\n");
                     exit (1);
                }

                while (1){
                    printf ("enter the messgage\n");
                    fgets (str, SIZE, stdin);
                    status = mq_send (md, str, strlen(str), 0);
                    if (status != 0){
                        perror ("message sending failed\n");
                        exit (1);
                    }
		    if (strcmp (str, "end\n") == 0){
			break;
		    }
                }
                
                break;
          case 2 :
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
            printf ("the received msg is : %s\n", str1);
            }
            break;

        default : printf ("wrong choice\n");
                  break;
        }
   }

    mq_unlink (*(argv + 1));
    mq_close (md);

    signal(SIGINT, signal_handle);
    kill (getpid (), SIGINT);

    return 0;

}
