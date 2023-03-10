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

int __init request_region_InitFunc(void){

	request_region(from, num, name);
	printk("apply IO port successfully!!!");
	return 0;

}

void __exit request_region_ExitFunc(void){
	release_region(from, num);
	printk("release IO port successfully!!!");
}

module_init(request_region_InitFunc);
module_exit(request_region_ExitFunc);
