#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/string.h>

#define DEVICE_NAME "mydrv"
#define MYDRV_MAX_LENGTH 100 // 100byte
#define DATA_SIZE 20

struct class* myclass;
struct cdev* mycdev;
struct device* mydevice;
dev_t mydev;

static char* mydrv_data;
static int mydrv_read_offset,mydrv_write_offset;

void strupr2(char* buf,size_t count) {
	int i = 0;
	while (i < count) {
		if (buf[i] >= 'A' && buf[i] <= 'Z') {
			buf[i] = buf[i] + 32;
		}else if(buf[i] >= 'a' && buf[i] <= 'z'){
			buf[i] = buf[i] - 32;
		}
		i++;
	}

	return;
}


static ssize_t mydrv_write(struct file* file,const char* buf,size_t count,loff_t* ppos){

	
	if(mydrv_write_offset >= MYDRV_MAX_LENGTH){
                mydrv_write_offset = 0;
        }

	if(copy_from_user(mydrv_data+mydrv_write_offset,buf,count)){
			return -1;
	}

	strupr2(mydrv_data+mydrv_write_offset,count);

	mydrv_write_offset += count;

	return count;
}

static ssize_t mydrv_read(struct file* file, char* buf, size_t count, loff_t* ppos){
	if(mydrv_read_offset >= MYDRV_MAX_LENGTH){
		mydrv_read_offset = 0;
	}

	if(copy_to_user(buf,mydrv_data+mydrv_read_offset,count)){
		return -1;
	}
	mydrv_read_offset += count;

	return count;
}

struct file_operations mydrv_fops={
        .owner = THIS_MODULE,
        .read = mydrv_read,
        .write = mydrv_write,
//      .open = mydrv_open,
//      .release = mydrv_release,
};


int mydrv_init(void){
	printk("Hello~~~\n");
	if( alloc_chrdev_region(&mydev,0,1,DEVICE_NAME)<0){
		return -EBUSY;
	}
	myclass = class_create(THIS_MODULE,"mycharclass");
	if(IS_ERR(myclass)){
		unregister_chrdev_region(mydev,1);
		return PTR_ERR(myclass);
	}
	mydevice = device_create(myclass,NULL,mydev,NULL,"mydevicefile");
	if( IS_ERR(mydevice)){
		class_destroy(myclass);
		unregister_chrdev_region(mydev,1);
		return PTR_ERR(mydevice);
	}
	mycdev = cdev_alloc();
	mycdev->ops = &mydrv_fops;
	mycdev->owner = THIS_MODULE;
	if(cdev_add(mycdev,mydev,1)<0){
		device_destroy(myclass,mydev);
		class_destroy(myclass);
		unregister_chrdev_region(mydev,1);
		return -EBUSY;
	}

	mydrv_data = (char*)kmalloc(MYDRV_MAX_LENGTH*sizeof(char),GFP_KERNEL);
	mydrv_read_offset = mydrv_write_offset = 0;
	return 0;
}

void mydrv_cleanup(void){
	kfree(mydrv_data);
	cdev_del(mycdev);
	device_destroy(myclass,mydev);
	class_destroy(myclass);
	unregister_chrdev_region(mydev,1);
	printk("Goodbye\n");
}

module_init(mydrv_init);
module_exit(mydrv_cleanup);

MODULE_LICENSE("GPL");


