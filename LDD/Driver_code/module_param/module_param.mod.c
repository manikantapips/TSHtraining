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
	{ 0x8848086a, "param_ops_charp" },
	{ 0x3184b6ef, "param_ops_int" },
	{ 0xf5bb7b3b, "param_array_ops" },
	{ 0xd3a57ee7, "param_get_int" },
	{ 0xc5850110, "printk" },
	{ 0x1b6707d2, "param_set_int" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DBFD58978D63932E3816335");
