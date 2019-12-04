obj-m = mydrv.o

KERNEL_DIR = /lib/modules/$(shell uname -r)/build
PWD = $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules
	gcc -o test.exe test.c -g
clean:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) clean
	rm *.exe
