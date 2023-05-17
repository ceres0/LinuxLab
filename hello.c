#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
static int init_hello(void)
{
	printk(KERN_INFO "Hello, World!\n");
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
