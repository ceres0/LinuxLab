#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/sched/signal.h> // 在4.11内核中，for_each_process从<linux/sched.h>移到了<linux/sched/signal.h>中
static int init_hello(void)
{
	printk(KERN_INFO "Hello, World!\n");    
	printk(KERN_ALERT "pid=%i   command=%s ",current->pid,current->comm);
    printk(KERN_ALERT "\n");

    int pid_no=current->pid;
    struct task_struct * task=current;
    for_each_process(task) 
   	{
        if(task->pid==pid_no) break;
           printk(KERN_ALERT "process id = %d command= %s",(int)task->pid,task->comm);
   	}
	printk(KERN_ALERT "\n");
	return 0;
}
static void cleanup_hello(void)
{
	printk(KERN_INFO "Goodbye, world!\n");
}
module_init(init_hello);
module_exit(cleanup_hello);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ceres");
MODULE_DESCRIPTION("A test project");
