#ifndef _syscall_wrapper_hh
#define _syscall_wrapper_hh

#include "asm.hh"

namespace xus
{

asmlinkage long xsyscall0(long number) noexcept;
asmlinkage long xsyscall1(long number, long arg1) noexcept;
asmlinkage long xsyscall2(long number, long arg1, long arg2) noexcept;
asmlinkage long xsyscall3(long number, long arg1, long arg2, long arg3) noexcept;
asmlinkage long xsyscall4(long number, long arg1, long arg2, long arg3, long arg4) noexcept;
asmlinkage long xsyscall5(long number, long arg1, long arg2, long arg3, long arg4, long arg5) noexcept;
asmlinkage long xsyscall6(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6) noexcept;

}

#endif
