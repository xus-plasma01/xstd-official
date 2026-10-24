#include "syscalls.hh"

asmlinkage
{

long xus::arch::I386::i386_syscall0(long number) noexcept
{
	long ret;
	_asm unoptimize(
		"int $0x80"
		: "=a"	(ret)
		: "a"	(number)
		: "memory"
	);

	return ret;
}

long xus::arch::I386::i386_syscall1(
	long number, long arg1) noexcept
{
	long ret;
	_asm unoptimize(
		"int $0x80"
		: "=a"		(ret)
		: "a"		(number)
		, "b"		(arg1)
		: "memory"
	);

	return ret;
}

long xus::arch::I386::i386_syscall2(
	long number, long arg1, long arg2) noexcept
{
	long ret;
	_asm unoptimize(
		"int $0x80"
		: "=a"		(ret)
		: "a"		(number)
		, "b"		(arg1)
		, "c"		(arg2)
		: "memory"
	);

	return ret;
}

long xus::arch::I386::i386_syscall3(
	long number, long arg1, long arg2, long arg3) noexcept
{
	long ret;
	_asm unoptimize(
		"int $0x80"
		: "=a"		(ret)
		: "a"		(number)
		, "b"		(arg1)
		, "c"		(arg2)
		, "d"		(arg3)
		: "memory"
	);

	return ret;
}

long xus::arch::I386::i386_syscall4(
	long number,
	long arg1,
	long arg2,
	long arg3,
	long arg4) noexcept
{
	long ret;
	
	_asm unoptimize(
		"int $0x80"
		: "=a"		(ret)
		: "a"		(number)
		, "b"		(arg1)
		, "c"		(arg2)
		, "d"		(arg3)
		, "S"		(arg4)
		: "memory"
	);

	return ret;
}

long xus::arch::I386::i386_syscall5(
	long number,
	long arg1,
	long arg2,
	long arg3,
	long arg4,
	long arg5) noexcept
{
	long ret;

	_asm unoptimize(
		"int $0x80"
		: "=a"			(ret)
		: "a"			(number)
		, "b"			(arg1)
		, "c"			(arg2)
		, "d"			(arg3)
		, "S"			(arg4)
		, "D"			(arg5)
		: "memory"
	);

	return ret;
}

long xus::arch::I386::i386_syscall6(
	long number,
	long arg1,
	long arg2,
	long arg3,
	long arg4,
	long arg5,
	long arg6) noexcept
{
	long ret;

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
	);

	return ret;
}

}
	

