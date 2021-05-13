#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0xc79d2779, "module_layout" },
	{ 0x7d5a7d0b, "kthread_stop" },
	{ 0x3129b92e, "wake_up_process" },
	{ 0x4f38cf60, "kthread_create_on_node" },
	{ 0x4e0ecf27, "current_task" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc5850110, "printk" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x6df1aaf1, "kernel_sigaction" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "10B703B6889205C28C42E3A");
