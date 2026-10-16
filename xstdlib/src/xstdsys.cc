/// include
#include "../include/xstdsys.hh"
#include "../include/xstdio.hh"

/// external
#include "../external/asm.hh"
#include "../external/args.hh"
#include "../external/wsyscall.hh"
#include "../external/sysnums.hh"

asmlinkage long xus::vsyscall(
	int _args, long number, ...)
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
		if (_args >= 6)
			{
				xus::outw("varidic syscalls (and syscalls in general) can take only up to 6 args!\n");

				xus::ret(xus::hlt, 0);
				return static_cast<long>(-1);
			}
	}
}

asmlinkage void
xus::ret(long number, long code)
{
	xus::vsyscall(2, number, code);
	for (;;);
}
