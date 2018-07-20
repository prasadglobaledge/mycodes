#include "headers.h"

int main (void) 
{
    int sock_sfd = 0;
    int status = 0;
    int sock_sfd1 = 0;
    struct sockaddr_in *sock = (struct sockaddr_in *) malloc (sizeof (struct sockaddr_in));
    struct sockaddr_in *client = (struct sockaddr_in *) malloc (sizeof (struct sockaddr_in));
    assert (sock);
    assert (client);
    ssize_t num = 0;
    char *str = NULL;
    socklen_t len = sizeof (struct sockaddr_in);

    str = (char *) malloc (sizeof (char) * 100);
    assert (str);

    sock -> sin_family = AF_INET;
    sock -> sin_port = htons (5022);
    sock -> sin_addr.s_addr = INADDR_ANY;

    sock_sfd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_sfd < 0){
        perror ("socket\n");
        exit (0);
    }
    printf ("1");
    status = bind (sock_sfd, (struct sockaddr *)sock, (socklen_t) sizeof (struct sockaddr_in));
    if (status < 0){
        perror ("bind\n");
        exit (0);
    }
    printf ("1");
    status = listen (sock_sfd, 1);
    if (status < 0){
        perror ("listen\n");
        exit (0);
    }
    printf ("1");

    sock_sfd1 = accept (sock_sfd, (struct sockaddr *) client, &len);
    if (sock_sfd1< 0){
        perror ("accept\n");
        exit (0);
    }
    printf ("1");

    num = read (sock_sfd1, str, 100);
    if (num < 0){
        perror ("read\n");
        exit (0);
    }
    printf ("1");

    close (sock_sfd1);
    close (sock_sfd);

    return 0;
}


