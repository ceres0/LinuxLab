 #include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/mm_types.h>
#include <linux/kprobes.h>

int noop_pre(struct kprobe *p, struct pt_regs *regs) { return 0; }

static struct kprobe kp = {
	.symbol_name = "kallsyms_lookup_name",
};

unsigned long (*kallsyms_lookup_name_fun)(const char *name) = NULL;

// 调用kprobe找到kallsyms_lookup_name的地址位置
int find_kallsyms_lookup_name(void)
{
	int ret = -1;
	kp.pre_handler = noop_pre;
	ret = register_kprobe(&kp);
	if (ret < 0)
	{
		printk(KERN_INFO "register_kprobe failed, error:%d\n", ret);
		return ret;
	}
	printk(KERN_INFO "kallsyms_lookup_name addr: %p\n", kp.addr);
	kallsyms_lookup_name_fun = (void *)kp.addr;
	unregister_kprobe(&kp);
	return ret;
}

static int init_hello(void)
{
	printk(KERN_INFO "Hello, World!\n");
	printk(KERN_ALERT "pid=%i   command=%s ", current->pid, current->comm);

	int pid_no = current->pid;
	struct task_struct *task = current;
    struct mm_struct *mm;
	mm = task -> active_mm;
	printk(KERN_ALERT "process id = %d tpid= %d start_code = %lx", (int)task->pid, (int)task->comm, mm->start_code);
	printk(KERN_ALERT "mm users %d count %d", mm -> mm_users, mm -> mm_count);
	printk(KERN_ALERT "mm owner pid = %d", mm -> owner -> pid);
	
	find_kallsyms_lookup_name();
	struct mm_struct *pos;
	
	struct mm_struct *init_mm = (struct mm_struct *)kallsyms_lookup_name_fun("init_mm");
	printk(KERN_ALERT "init_mm users %d count %d", init_mm -> mm_users, init_mm -> mm_count);
	printk(KERN_ALERT "init_mm users %lx", init_mm -> owner);

	// list_for_each_entry(pos, &init_mm -> mmlist, mmlist){
	// 	printk(KERN_ALERT "1");
	// }
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
