/**@brief Pseudo driver module adding and removing to kernel*/
///header files
#include <stdio.h> 
#include <fcntl.h>
#include <sys/ioctl.h>
int main(void) ///main function definition
{
    int fd; ///@var @brief file descriptor number
    int ret = 0;      
    fd = open("/dev/mychar", O_RDWR); ///@brief opening a file with W/R
    if(fd < 0){ ///checking condition wheather the fd value is < zero or not
        perror("unable to open the device");///displaying the error message
    }
    else{
        printf("file opened successfully %d\n", fd);///else open successfull
    }

    ret = ioctl(fd, 1, 2);
    close(fd);///closing the opened device
    return 0;
}
