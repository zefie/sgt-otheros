XVM = sub-projects/allocators/xvmalloc-kmod
EXTRA_CFLAGS	:=	-DCONFIG_RAMZSWAP_STATS		\
			-Wall

obj-$(CONFIG_SGT_COMPCACHE)	+=	ramzswap.o
ramzswap-objs	:=	ramzswap_drv.o $(XVM)/xvmalloc.o
