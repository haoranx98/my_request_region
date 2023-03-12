obj-m += 2022E8013282034.o
CONFIG_MODULE_SIG=n
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

