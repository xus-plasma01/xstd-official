#ifndef _xstdsys
#define _xstdsys

/// headers
#include "xstdio"
#include "xstdarg"
#include "xstdint"

/// some redundancy
#ifdef __cplusplus
#	pragma once
#endif

/// some wrappers
#ifdef __cplusplus
#	define _asm 			asm
#	define _unoptimizable 	volatile
#elif defined(__GNUC__) || defined(__clang__)
#	define _asm 			__asm__
#	define _unoptimizable 	__volatile__
#else
#	error "unsupported compiler"
#	error "gnu style asm requires a gcc or clang compiler"
#endif

#define unoptimizable _unoptimizable

/// attributes
#define _noreturn __attribute__((noreturn))


namespace xus
{
constexpr int PUTCHAR		= 1;
constexpr int GETCHAR		= 2;
constexpr int EXIT			= 3;
constexpr int READFILE		= 4;
constexpr int WRITEFILE		= 5;
constexpr int MAX 			= 6;

inline intptr_t vsyscall(
	intptr_t number, ...)
{
	
	va_list vargs;
	va_start(vargs, number);
		intptr_t arg0 = va_arg(vargs,	intptr_t);
		intptr_t arg1 = va_arg(vargs,	intptr_t);
		intptr_t arg2 = va_arg(vargs,	intptr_t);
		intptr_t arg3 = va_arg(vargs,	intptr_t);
		intptr_t arg4 = va_arg(vargs,	intptr_t);
		intptr_t arg5 = va_arg(vargs,	intptr_t);
		intptr_t arg6 = va_arg(vargs,	intptr_t);
	va_end(vargs);

	intptr_t res;

#if defined(__x86_64__)

	register intptr_t r10	_asm("r10")		= arg4;
	register intptr_t r9	_asm("r9")		= arg5;
	register intptr_t r8	_asm("r8")		= arg6;

	_asm unoptimizable
	(
		"syscall"
		: "=a"		(res)
		: "a"		(arg0)
		, "D"		(arg1)
		, "S"		(arg2)
		, "d"		(arg3)
		, "r"		(r10)
		, "r"		(r8)
		, "r"		(r9)
		: "rcx"
		, "r11"
		, "memory"
	);
	
#endif

	return res;
}

extern "C" _noreturn 
inline void ret(intptr_t code)
{
	for (;;)
	{
		_asm unoptimizable
		(
			"syscall"
			: 
			: "a"		(60)
			, "D"		(static_cast<intptr_t>(code))
			: "rcx"
			, "r11"
			, "memory"
		);
	}
}

inline int scanbfr(
	const char *	fname,
	char *			buf,
	int				len)
{
	return xus::vsyscall(
		READFILE,
		reinterpret_cast<unsigned long>(fname),
		reinterpret_cast<unsigned long>(buf),
		len);
}

inline int writebfr(
	const char *fname,
	const char *buf,
	int			len)
{
	return xus::vsyscall(
		WRITEFILE,
		reinterpret_cast<unsigned long>(fname),
		reinterpret_cast<unsigned long>(buf),
		len);
}
}

#endif
