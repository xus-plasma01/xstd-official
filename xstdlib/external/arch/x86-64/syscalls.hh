#ifndef _x86_64_syscalls_h
#define _x86_64_syscalls_h

#include "../../asm.hh"

namespace xus
{

asmlinkage long x86_64_syscall0(long number);
asmlinkage long x86_64_syscall1(long number, long res1);
asmlinkage long x86_64_syscall2(long number, long res1, long res2);
asmlinkage long x86_64_syscall3(long number, long res1, long res2, long res3);
asmlinkage long x86_64_syscall4(long number, long res1, long res2, long res3, long res4);
asmlinkage long x86_64_syscall5(long number, long res1, long res2, long res3, long res4, long res5);
asmlinkage long x86_64_syscall6(long number, long res1, long res2, long res3, long res4, long res5, long res6);

asmlinkage long x86_64_vsyscall(int number_of_args, long number, ...);

}

#endif
