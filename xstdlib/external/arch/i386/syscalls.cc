#include "syscalls.hh"

asmlinkage
{

long xus::i386_syscall0(long number)
{
	long ret;
	_asm unoptimize(
		"int $0x80"
		: "=a"	(ret)
		: "a"	(number)
		: "ecx"
		, "r11d"
		, "memory"
	);

	return ret;
}

long xus::i386_syscall1(long number, long arg1)
{
	long ret;
	_asm unoptimize(
		"int $0x80"
		: "=a"		(ret)
		: "a"		(number)
		, "D"		(arg1)
		: "ecx"	
		, "r11d"
		, "memory"
	);

	return ret;
}

long xus::i386_syscall2(
	long number, long arg1, long arg2)
{
	long ret;
	_asm unoptimize(
		"int $0x80"
		: "=a"		(ret)
		: "a"		(number)
		, "D"		(arg1)
		, "S"		(arg2)
		: "ecx"
		, "r11d"
		, "memory"
	);

	return ret;
}

long xus::i386_syscall3(
	long number, long arg1, long arg2, long arg3)
{
	long ret;
	_asm unoptimize(
		"int $0x80"
		: "=a"		(ret)
		: "a"		(number)
		, "D"		(arg1)
		, "S"		(arg2)
		, "d"		(arg3)
		: "ecx"
		, "r11d"
		, "memory"
	);

	return ret;
}

long xus::i386_syscall4(
	long number,
	long arg1,
	long arg2,
	long arg3,
	long arg4)
{
	long ret;

	register long r10d _asm("r10d") = arg4;
	
	_asm unoptimize(
		"int $0x80"
		: "=a"		(ret)
		: "a"		(number)
		, "D"		(arg1)
		, "S"		(arg2)
		, "d"		(arg3)
		, "r"		(r10d)
		: "ecx"	
		, "r11d"
		, "memory"
	);

	return ret;
}

long xus::i386_syscall5(
	long number,
	long arg1,
	long arg2,
	long arg3,
	long arg4,
	long arg5)
{
	long ret;

	register long r10d _asm("r10d") 	= arg4;
	register long r9d  _asm("r9d")		= arg5;

	_asm unoptimize(
		"int $0x80"
		: "=a"			(ret)
		: "a"			(number)
		, "D"			(arg1)
		, "S"			(arg2)
		, "d"			(arg3)
		, "r"			(r10d)
		, "r"			(r9d)
		: "ecx"
		, "r11d"
		, "memory"
	);

	return ret;
}

long xus::i386_syscall6(
	long number,
	long arg1,
	long arg2,
	long arg3,
	long arg4,
	long arg5,
	long arg6)
{
	long ret;

	register long r10d	_asm("r10d")	= arg4;
	register long r9d	_asm("r9d")		= arg5;
	register long r8d	_asm("r8d")		= arg6;

	_asm unoptimizable(
		"int $0x80"
		: "=a"		(ret)
		: "a"		(number)
		, "D"		(arg1)
		, "S"		(arg2)
		, "d"		(arg3)
		, "r"		(r10d)
		, "r"		(r9d)
		, "r"		(r8d)
		: "ecx"
		, "r11d"
		, "memory"
	);

	return ret;
}
	
}
