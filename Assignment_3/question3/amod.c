#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/kthread.h>
#include<linux/sched.h>
#include<linux/time.h>
#include<linux/sched/signal.h>


char* proName="bash";
module_param(proName,charp,S_IRUGO);
MODULE_LICENSE("GPL");
int init_module(void){
	struct task_struct *p;
	for_each_process(p){
		if(strcmp(p->comm,proName)==0){
			
			printk(KERN_INFO"Process ID: %d",p->pid);
			printk(KERN_INFO"Group ID: %d",p->cred->gid);
			printk(KERN_INFO"User ID: %d",p->cred->uid);
			printk("end");
			
		}
	}
	return 0;
}
void cleanup_module(void){
	printk(KERN_INFO"exit");
}

