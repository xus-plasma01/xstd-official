#ifndef _sys_nums_hh
#define _sys_nums_hh

#ifdef __x86_64__
#	define HLT		231
#	define EXIT		60
#	define WRITE	1
#	define READ		0
#elif defined(__i386__)
#	define HLT		252
#	define EXIT		1
#	define WRITE 	4
#	define READ		3
#endif

#endif
