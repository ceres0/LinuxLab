#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/mm_types.h>
static int init_hello(void)
{
	printk(KERN_INFO "Hello, World!\n");
	printk(KERN_ALERT "pid=%i   command=%s ", current->pid, current->comm);
	printk(KERN_ALERT "\n");

	int pid_no = current->pid;
	struct task_struct *task = current;
    struct mm_struct *mm;
	mm = task -> active_mm;
	printk(KERN_ALERT "process id = %d tpid= %d start_code = %lx", (int)task->pid, (int)task->comm, mm->start_code);
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
