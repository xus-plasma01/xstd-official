/// include
#include "../include/xstdsys.hh"
#include "../include/xstdio.hh"
#include "../include/xstdassert.hh"

/// external
#include "../external/asm.hh"
#include "../external/args.hh"
#include "../external/wsyscall.hh"
#include "../external/sysnums.hh"

asmlinkage long xus::vsyscall(
	int _args, long number, ...) noexcept
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

	switch(_args)
	{
	case 0:		return xus::xsyscall0(number);
	case 1:		return xus::xsyscall1(number, arg1);
	case 2:		return xus::xsyscall2(number, arg1, arg2);
	case 3:		return xus::xsyscall3(number, arg1, arg2, arg3);
	case 4:		return xus::xsyscall4(number, arg1, arg2, arg3, arg4);
	case 5:		return xus::xsyscall5(number, arg1, arg2, arg3, arg4, arg5);
	case 6:		return xus::xsyscall6(number, arg1, arg2, arg3, arg4, arg5, arg6);
	default:
		assertion(false, "syscall args only allowed up to 6", TRAP);
	}
}

maybe_unused static void _x86_64_exit()
{
	_asm unoptimize(
		"mov $60,	%%rax\n"
		"xor %%rdi,	%%rdi\n"
		"syscall"
		::
		: "rax"
		, "rdi"
	);
}

maybe_unused static void _i386_exit()
{
	_asm unoptimize(
		"mov $1,	%%eax\n"
		"xor %%ebx,	%%ebx\n"
		"int $0x80"
		::
		: "eax"
		, "ebx"
	);
}

asmlinkage _noreturn 
void xus::ret(
	long number) noexcept
{
	switch(static_cast<_exit_t>(number))
	{
	case UNREACHABLE:			xus::unreachable();
	case TRAP:					xus::trap();
	case LOOP:					for (;;);
	case EXIT:
#ifdef __x86_64__
	_x86_64_exit();
#elif defined(__i386__)
	_i386_exit();
#endif
		xus::unreachable();
	default:					xus::xsyscall0(static_cast<long>(number));
	}
}

