obj-m := vfs_exam2.o

vfs_exam2.ko: vfs_exam2.c
	make -C /usr/src/linux-3.18.36/ SUBDIRS=$(PWD) modules

clean:
	make -C /usr/src/linux-3.18.36/ SUBDIRS=$(PWD) clean
