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
<<<<<<< HEAD
		: "ecx"
		, "r11d"
		, "memory"
=======
		: "memory"
>>>>>>> cfb77316 ([commit 14] added an array feature (xstdarray))
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
<<<<<<< HEAD
		, "D"		(arg1)
		: "ecx"	
		, "r11d"
		, "memory"
=======
		, "b"		(arg1)
		: "memory"
>>>>>>> cfb77316 ([commit 14] added an array feature (xstdarray))
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
<<<<<<< HEAD
		, "D"		(arg1)
		, "S"		(arg2)
		: "ecx"
		, "r11d"
		, "memory"
=======
		, "b"		(arg1)
		, "c"		(arg2)
		: "memory"
>>>>>>> cfb77316 ([commit 14] added an array feature (xstdarray))
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
<<<<<<< HEAD
		, "D"		(arg1)
		, "S"		(arg2)
		, "d"		(arg3)
		: "ecx"
		, "r11d"
		, "memory"
=======
		, "b"		(arg1)
		, "c"		(arg2)
		, "d"		(arg3)
		: "memory"
>>>>>>> cfb77316 ([commit 14] added an array feature (xstdarray))
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
<<<<<<< HEAD

	register long r10d _asm("r10d") = arg4;
=======
>>>>>>> cfb77316 ([commit 14] added an array feature (xstdarray))
	
	_asm unoptimize(
		"int $0x80"
		: "=a"		(ret)
		: "a"		(number)
<<<<<<< HEAD
		, "D"		(arg1)
		, "S"		(arg2)
		, "d"		(arg3)
		, "r"		(r10d)
		: "ecx"	
		, "r11d"
		, "memory"
=======
		, "b"		(arg1)
		, "c"		(arg2)
		, "d"		(arg3)
		, "S"		(arg4)
		: "memory"
>>>>>>> cfb77316 ([commit 14] added an array feature (xstdarray))
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

<<<<<<< HEAD
	register long r10d _asm("r10d") 	= arg4;
	register long r9d  _asm("r9d")		= arg5;

=======
>>>>>>> cfb77316 ([commit 14] added an array feature (xstdarray))
	_asm unoptimize(
		"int $0x80"
		: "=a"			(ret)
		: "a"			(number)
<<<<<<< HEAD
		, "D"			(arg1)
		, "S"			(arg2)
		, "d"			(arg3)
		, "r"			(r10d)
		, "r"			(r9d)
		: "ecx"
		, "r11d"
		, "memory"
=======
		, "b"			(arg1)
		, "c"			(arg2)
		, "d"			(arg3)
		, "S"			(arg4)
		, "D"			(arg5)
		: "memory"
>>>>>>> cfb77316 ([commit 14] added an array feature (xstdarray))
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

<<<<<<< HEAD
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
=======
	_asm unoptimize(
		"push %%ebp\n\t"
		"mov %[res6], %%ebp\n\t"
		"int $0x80\n\t"
		"pop %%ebp"
		: "=a"			(ret)
		: "a"			(number)
		, "b"			(arg1)
		, "c"			(arg2)
		, "d"			(arg3)
		, "S"			(arg4)
		, "D"			(arg5)
		, [res6] "m" 	(arg6)
		: "memory"
>>>>>>> cfb77316 ([commit 14] added an array feature (xstdarray))
	);

	return ret;
}
	
}
