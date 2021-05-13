#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>


#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fcntl.h> /*Helps fix O_ACCMODE*/
#include <linux/sched.h> /*Helps fix TASK_UNINTERRUPTIBLE */
#include <linux/fs.h> /*Helps fix the struct intializer */

#include<linux/slab.h>                 //kmalloc()
#include<linux/uaccess.h>              //copy_to/from_user()
#include <linux/ioctl.h>

#include <linux/proc_fs.h>    // proc file system
#include <linux/compiler.h>
#include <linux/types.h>
#include <linux/proc_ns.h>

#include <linux/kobject.h>

#include <linux/interrupt.h>

#include <linux/kthread.h> // therad 
#include <linux/delay.h>   // sleep 
#include <linux/sched.h>               //task_struct

#include <linux/timer.h>
#include <linux/jiffies.h>

#include <linux/workqueue.h> // Required for workqueues

#include <linux/proc_fs.h>
#include <linux/jiffies.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Johny");
MODULE_DESCRIPTION(" tasklet  driver");
MODULE_VERSION("1.0.0");

static int my_tasklet_function(void);
static void my_tasklet_exit(void);




static void my_tasklet_handler(unsigned long flag);

DECLARE_TASKLET(my_tasklet,my_tasklet_handler,0);

static void my_tasklet_handler(unsigned long flag)
{
	//tasklet_disable(&my_tasklet);
	printk(KERN_INFO"My tasklet handler function");
	//tasklet_enable(&my_tasklet);
}


static int  my_tasklet_function(void)
{
	printk(KERN_INFO"My tasklet function start ");
	//Schedule the tasklet 
	tasklet_schedule(&my_tasklet);
	return 0;
}

static void  my_tasklet_exit()
{
	tasklet_kill(&my_tasklet);
	printk(KERN_INFO"My tasklet function exit");
}

module_init(my_tasklet_function);
module_exit(my_tasklet_exit);
