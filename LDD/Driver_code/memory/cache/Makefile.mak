
obj-m +=tasklet.o
obj-m +=workqueue1.o
KDIR = /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(shell pwd) modules
	
clean:
	make -C $(KDIR) M=$(shell pwd) clean
