#ifndef _i386_syscalls_hh
#define _i386_syscalls_hh

#include "../../asm.hh"

namespace xus
{

asmlinkage
{

long i386_syscall0(long number) noexcept;
long i386_syscall1(long number, long arg1) noexcept;
long i386_syscall2(long number, long arg1, long arg2) noexcept;
long i386_syscall3(long number, long arg1, long arg2, long arg3) noexcept;
long i386_syscall4(long number, long arg1, long arg2, long arg3, long arg4) noexcept;
long i386_syscall5(long number, long arg1, long arg2, long arg3, long arg4, long arg5) noexcept;
long i386_syscall6(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6) noexcept;
	
}

}

#endif
