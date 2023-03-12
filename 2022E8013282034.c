#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/ioport.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("haoranx98");
MODULE_DESCRIPTION("A simple example of kmalloc.");
MODULE_VERSION("0.01");

static int __init request_region_InitFunc(void);
static void __exit request_region_ExitFunc(void);

unsigned long from = 0xd300;
unsigned long num = 0xff;
char* name = "Haoran Xu's IO port";
bool flag = 0;

int __init request_region_InitFunc(void){

	if(request_region(from, num, name) != NULL){
		printk("apply IO port successfully!!!\n");
		flag = 1;
	}else{
		printk("apply IO port failed!!!!\n");
	}
	return 0;

}

void __exit request_region_ExitFunc(void){
	
	if(flag == 1){
		release_region(from, num);
		printk("release IO port successfully!!!\n");
	}
}

module_init(request_region_InitFunc);
module_exit(request_region_ExitFunc);
