#include "headers.h"

int main (void) 
{
    struct sockaddr_in socket1;
    struct sockaddr_in socket2;
    int sfd;
//    int sfd1;
    int status = 0;
    ssize_t num = 0;
    char *str = NULL;
    char *str1 = NULL;

    str = (char *) malloc (sizeof (char) * 100);
    if (str == NULL){
        perror ("malloc\n");
    }
	str1 = (char *) malloc (sizeof (char) * 100);
    if (str1 == NULL){
        perror ("malloc\n");
    }


    str = "172.16.5.147";

    socket1.sin_family = AF_INET;
    socket1.sin_port = htons (9000);
	socket1.sin_addr.s_addr = inet_addr (str);


    socket2.sin_family = AF_INET;
    socket2.sin_port = htons (9000);
	socket2.sin_addr.s_addr = inet_addr ("172.16.5.227");

    sfd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sfd == -1){
        perror ("socket failed\n");
    }    
	else
	printf("Socket success\n");

    status = bind (sfd, (struct sockaddr *) &socket1, sizeof (struct sockaddr_in));
      if (status == -1){                                                          
           perror ("bind failed\n");                                               
     }                                                                           
     else                                                                        
        printf("Bind success\n");   

    status = connect (sfd, (struct sockaddr *) &socket1, sizeof (struct sockaddr_in));
    if (status != 0){
        perror ("connect failed\n");
    }
	else
	printf("connect success\n");

    printf ("enter the string\n");
    __fpurge (stdin);
    fgets (str1, 100, stdin);
    printf ("%s\n", str1);
    num = write (sfd, str1, 100);
    if (num == -1){
        perror ("read failed\n");
    }
    
    close (sfd);
}
