#ifndef _sys_nums_hh
#define _sys_nums_hh

#ifdef __x86_64__
#	define WHLT		231
#	define WEXIT	60
#	define WWRITE	1
#	define WREAD	0
#elif defined(__i386__)
#	define WHLT		252
#	define WEXIT	1
#	define WWRITE 	4
#	define WREAD	3
#endif

#endif
