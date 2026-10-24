#include "wsyscall.hh"

#include "arch/x86-64/syscalls.hh"
#include "arch/i386/syscalls.hh"

#include "asm.hh"

asmlinkage long xus::xsyscall0(
	long number) noexcept
{
#ifdef __x86_64__
	return xus::arch::x86_64::x86_64_syscall0(number);
#elif defined(__i386__)
	return xus::arch::I386::i386_syscall0(number);
#endif
}

asmlinkage long xus::xsyscall1(
	long number, long arg1) noexcept
{
#ifdef __x86_64__
	return xus::arch::x86_64::x86_64_syscall1(number, arg1);
#elif defined(__i386__)
	return xus::arch::I386::i386_syscall1(number, arg1);
#endif
}

asmlinkage long xus::xsyscall2(
	long number, long arg1, long arg2) noexcept
{
#ifdef __x86_64__
	return xus::arch::x86_64::x86_64_syscall2(number, arg1, arg2);
#elif defined(__i386__)
	return xus::arch::I386::i386_syscall2(number, arg1, arg2);
#endif
}

asmlinkage long xus::xsyscall3(
	long number, long arg1, long arg2, long arg3) noexcept
{
#ifdef __x86_64__
	return xus::arch::x86_64::x86_64_syscall3(number, arg1, arg2, arg3);
#elif defined(__i386__)
	return xus::arch::I386::i386_syscall3(number, arg1, arg2, arg3);
#endif
}

asmlinkage long xus::xsyscall4(
	long number, 
	long arg1, 
	long arg2, 
	long arg3, 
	long arg4) noexcept
{
#ifdef __x86_64__
	return xus::arch::x86_64::x86_64_syscall4(number, arg1, arg2, arg3, arg4);
#elif defined(__i386__)
	return xus::arch::I386::i386_syscall4(number, arg1, arg2, arg3, arg4);
#endif
}

asmlinkage long xus::xsyscall5(
	long number, 
	long arg1, 
	long arg2, 
	long arg3, 
	long arg4, 
	long arg5) noexcept
{
#ifdef __x86_64__
	return xus::arch::x86_64::x86_64_syscall5(number, arg1, arg2, arg3, arg4, arg5);
#elif defined(__i386__)
	return xus::arch::I386::i386_syscall5(number, arg1, arg2, arg3, arg4, arg5);
#endif
}

asmlinkage long xus::xsyscall6(
	long number, 
	long arg1, 
	long arg2, 
	long arg3, 
	long arg4, 
	long arg5, 
	long arg6) noexcept
{
#ifdef __x86_64__
	return xus::arch::x86_64::x86_64_syscall6(number, arg1, arg2, arg3, arg4, arg5, arg6);
#elif defined(__i386__)
	return xus::arch::I386::i386_syscall6(number, arg1, arg2, arg3, arg4, arg5, arg6);
#endif
}

