/** file to initialise(open) and release the device 
 * the headers used in this code they are not present in /usr/include*/

///Headers files
#include <linux/init.h> 
#include <linux/module.h> 
#include <linux/fs.h> 
#include <linux/sched.h> 
#include <linux/cdev.h>
#include <asm/uaccess.h> 
#include <linux/device.h> 
#include <linux/slab.h> 
#include <asm/current.h>
#include <asm/pgtable.h>
#include <asm/pgtable_32.h>
#include <asm/highmem.h>
#include <linux/mm.h>

MODULE_LICENSE("Dual BSD/GPL");
/**constants*/

#define FIRST_MINOR 10 //minor number macro definition
#define NR_DEVS 1 //number of devices macro definition

///function declaratons for syscall definitions
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl(struct file *fp, unsigned int request, unsigned long num);

///initializations routines
static int myInit(void);
static void myExit(void);

struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = myOpen,
    .release = myRelease,
    .unlocked_ioctl = myIoctl
};
/**Global variables*/
char *devname; //contains device name
int majNo; //major number
static dev_t mydev;//encodes major number and minor numbers
struct cdev *my_cdev;//holds character device driver descriptor

/*to accept input from the command line*/
module_param(devname, charp, 0000);

///class AND device structures
static struct class *mychar_class;
static struct device *mychar_device;

/*
 * myIoctl : open fuction for input output control
 *
 * */
long myIoctl(struct file *fp, unsigned int request, unsigned long num)
{
	pgd_t *pgd_addr = NULL;
	pte_t *pte_addr = NULL;
	unsigned int *ptr1 = NULL;
	unsigned int *ptr2 = NULL;
	unsigned int *ptr3 = NULL;
	unsigned long var1 = 0;
	unsigned long var2 = 0;
	void *seg_addr = NULL;
	
	pgd_addr = current -> mm -> pgd;
	ptr1 = (unsigned int *)(pgd_addr + (num >> 22));
	var1 = *ptr1;
	var1 = var1 >> 12;
	pte_addr = kmap(pfn_to_page(var1));

	ptr2 = (unsigned int *)(pte_addr + ((num << 10) >> 22));
	var2 = *ptr2;
	var2 = var2 >> 12;
	seg_addr = kmap(pfn_to_page(var2));

	ptr3 = (unsigned int *)(seg_addr + (num & 0x00000fff));
	
	*ptr3 = 50;

	return 0;
	
}
/*
 * myopen : open function of the pseudo driver
 *
 */


int myOpen(struct inode *inode, struct file *filep)
{
    printk(KERN_INFO "open successfull\n");
    return 0;
}

/*
 * myrealse : close function of the pseudo driver
 *
 */

int myRelease(struct inode *in, struct file *fp)
{
    printk(KERN_INFO "file released\n");
    return 0;
}

/*
 * myInit : ini function of the kernel module
 *
 */

static int __init myInit(void)
{
    int ret = -ENODEV;
    int status;

    printk(KERN_INFO "initializing character device\n");
    ///allocating device numbers
    status =alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);

    if(status < 0){
        printk(KERN_NOTICE "device number allocation failed : %d\n",status);
        goto err;
    }
    printk(KERN_INFO "major number allocated = %d\n",MAJOR(mydev));
    my_cdev = cdev_alloc();//allocate memory for my_cdev
    if(my_cdev == NULL){
        printk(KERN_ERR "cdev_alloc failed\n");
        goto err_cdev_alloc;
    }
    cdev_init(my_cdev, &fops);//initialize my_cdev with fops
    my_cdev -> owner = THIS_MODULE;

    status = cdev_add(my_cdev, mydev, NR_DEVS);//add my_cdevs to the list
    if(status){
        printk(KERN_ERR "cdev_add failed\n");
        goto err_cdev_add;
    }
    //create a class and an entry in sysfs

    mychar_class = class_create(THIS_MODULE, devname);
    if(IS_ERR(mychar_class)){
        printk(KERN_ERR "class_create failed\n");
        goto err_class_create;
    }

    //create mychar device in sysfs and an device entry will be made in /dev
    //directory

    mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
    if(IS_ERR(mychar_device)){
        printk(KERN_ERR "device_create failed\n");
        goto err_device_create;
    }
    return 0;

err_device_create :
    class_destroy(mychar_class);

err_class_create :
    cdev_del(my_cdev);

err_cdev_add :
    kfree(my_cdev);

err_cdev_alloc :
    unregister_chrdev_region(mydev, NR_DEVS);

err :
    return ret;

}
/*
 * myexit() : cleanup functon of the kernel module
 *
 */

static void myExit(void)
{
    printk(KERN_INFO "exiting the character driver\n");
    device_destroy(mychar_class, mydev);
    class_destroy(mychar_class);
    cdev_del(my_cdev);
    unregister_chrdev_region(mydev, NR_DEVS);
    return;
}

module_init(myInit);
module_exit(myExit);
