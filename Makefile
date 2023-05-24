obj-m := hello.o
module-objs := hello.o
default:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
	insmod hello.ko
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
	rmmod hello