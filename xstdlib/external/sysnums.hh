#ifndef _sys_nums_hh
#define _sys_nums_hh

#ifdef __x86_64__
<<<<<<< HEAD
	inline constexpr long HLT	= 231;
	inline constexpr long EXIT	= 60;
#elif defined(__i386__)
	inline constexpr long HLT	= 252;
	inline constexpr long EXIT	= 1;
=======
#	define HLT		231
#	define EXIT		60
#	define WRITE	1
#	define READ		0
#elif defined(__i386__)
#	define HLT		252
#	define EXIT		1
#	define WRITE 	4
#	define READ		3
>>>>>>> cfb77316 ([commit 14] added an array feature (xstdarray))
#endif

#endif
