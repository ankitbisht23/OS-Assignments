obj-m += amod.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	sudo insmod amod.ko
	
	sudo dmesg
	
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	sudo rmmod amod.ko
	
