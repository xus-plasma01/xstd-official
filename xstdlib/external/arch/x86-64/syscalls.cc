#include "../../args.hh"

#include "syscalls.hh"

namespace xus
{

asmlinkage 
{

long x86_64_syscall0(long number) noexcept
{
	long ret;
	_asm unoptimize(
		"syscall"
		: "=a"		(ret)
		: "a"		(number)
		: "rcx"
		, "r11"
		, "memory"
	);

	return ret;
		
}

long x86_64_syscall1(long number, long res1) noexcept
{
	long ret;
	_asm unoptimize(
		"syscall"
		: "=a"		(ret)
		: "a"		(number)
		, "D"		(res1)
		: "rcx"
		, "r11"
		, "memory"
	);

	return ret;
}

long x86_64_syscall2(
	long number, long res1, long res2) noexcept
{
	long ret;
	_asm unoptimize(
		"syscall"
		: "=a"			(ret)
		: "a"			(number)
		, "D"			(res1)
		, "S"			(res2)
		: "rcx"
		, "r11"
		, "memory"
	);

	return ret;
}

long x86_64_syscall3(
	long number, 
	long res1, 
	long res2, 
	long res3) noexcept
{
	long ret;
	_asm unoptimize(
		"syscall"
		: "=a"			(ret)
		: "a"			(number)
		, "D"			(res1)
		, "S"			(res2)
		, "d"			(res3)
		: "rcx"
		, "r11"
		, "memory"
	);

	return ret;
}

long x86_64_syscall4(
	long number,
	long res1,
	long res2,
	long res3,
	long res4) noexcept
{
	long ret;

	register long r10 _asm("r10")	= res4;
	
	_asm unoptimize(
		"syscall"
		: "=a"			(ret)
		: "a"			(number)
		, "D"			(res1)
		, "S"			(res2)
		, "d"			(res3)
		, "r"			(r10)
		: "rcx"
		, "r11"
		, "memory"
	);

	return ret;
}

long x86_64_syscall5(
	long number,
	long res1,
	long res2,
	long res3,
	long res4,
	long res5) noexcept
{
	long ret;

	register long r10 	_asm("r10")		= res4;
	register long r8 	_asm("r8")		= res5;
	
	_asm unoptimize(
		"syscall"
		: "=a"			(ret)
		: "a"			(number)
		, "D"			(res1)
		, "S"			(res2)
		, "d"			(res3)
		, "r"			(r10)
		, "r"			(r8)
		: "rcx"
		, "r11"
		, "memory"
	);

	return ret;
}

long x86_64_syscall6(
	long number,
	long res1,
	long res2,
	long res3,
	long res4,
	long res5,
	long res6) noexcept
{
	long ret;

	register long r10 	_asm("r10")		= res4;
	register long r8 	_asm("r8")		= res5;
	register long r9 	_asm("r9")		= res6;

	_asm unoptimize(
		"syscall"
		: "=a"		(ret)
		: "a"		(number)
		, "D"		(res1)
		, "S"		(res2)
		, "d"		(res3)
		, "r"		(r10)
		, "r"		(r8)
		, "r"		(r9)
		: "rcx"
		, "r11"
		, "memory"
	);

	return ret;
}

long x86_64_vsyscall(
	int args, long number, ...) noexcept
{
	va_list vargs;

	long arg1; 
	long arg2; 
	long arg3;
	long arg4;
	long arg5;
	long arg6;
	
	va_start(vargs, number);
		arg1 = va_arg(vargs, long);
		arg2 = va_arg(vargs, long);
		arg3 = va_arg(vargs, long);
		arg4 = va_arg(vargs, long);
		arg5 = va_arg(vargs, long);
		arg6 = va_arg(vargs, long);
	va_end(vargs);

	switch(args)
	{
	case 0:		return x86_64_syscall0(number);
	case 1:		return x86_64_syscall1(number, arg1);
	case 2:		return x86_64_syscall2(number, arg1, arg2);
	case 3:		return x86_64_syscall3(number, arg1, arg2, arg3);
	case 4:		return x86_64_syscall4(number, arg1, arg2, arg3, arg4);
	case 5:		return x86_64_syscall5(number, arg1, arg2, arg3, arg4, arg5);
	case 6:		return x86_64_syscall6(number, arg1, arg2, arg3, arg4, arg5, arg6);
	default:	return x86_64_syscall6(number, arg1, arg2, arg3, arg4, arg5, arg6);
	}
}

}

}
