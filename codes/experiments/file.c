#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
/*#define ERRMSG(msg) do { \
						perror (msg); \
						exit (1); \
					} while (0);	*/
int main (void)
{
	FILE *fp = NULL;

	fp = fopen("text", "r");
//	ERRMSG("file  found");
//	perror("file not opened\n");
 	printf("%d\n %s\n",ENOENT, strerror(errno));
	return 0;
}
