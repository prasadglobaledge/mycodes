/**@brief Pseudo driver module adding and removing to kernel*/
///header files
#include <stdio.h> 
#include <fcntl.h>
#include <sys/ioctl.h>
int main(void) ///main function definition
{
    int fd; ///@var @brief file descriptor number
    int shell_num = 5;
    int ret = 0;

    fd = open("/dev/mychar", O_RDWR); ///@brief opening a file with W/R
    if(fd < 0){ ///checking condition wheather the fd value is < zero or not
        perror("unable to open the device");///displaying the error message
    }
    else{
        printf("file opened successfully %d\n", fd);///else open successfull
    }
    
    //printf("value of shell_num before = %d\n", shell_num);

    ret = ioctl(fd, 1, &main);

    //printf("value of shell_num after = %d\n", shell_num);
    close(fd);///closing the opened device
    return 0;
}
