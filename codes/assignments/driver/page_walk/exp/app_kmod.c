/**@brief Pseudo driver module adding and removing to kernel*/
///header files
#include <stdio.h> 
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

int num = 10;
int main(void) ///main function definition
{
    int fd; ///@var @brief file descriptor number
    int ret = 0;
    pid_t pd;

    fd = open("/dev/mychar", O_RDWR); ///@brief opening a file with W/R

    if(fd < 0){ ///checking condition wheather the fd value is < zero or not
        perror("unable to open the device");///displaying the error message
    }

    else{
        printf("file opened successfully %d\n", fd);///else open successfull
	pd = fork();
	
	if(pd > 0){
		printf("parent pid is : %d\n", getpid());
		ret = ioctl (fd, 1, &num);
	}
	else if(pd == 0){
		printf("child pid is : %d\nparent's pid is : %d\n", getpid(), getppid());
		num = 30;
		ret = ioctl(fd, 1, &num);
	}

    }
    

    close(fd);///closing the opened device
    return 0;
}
