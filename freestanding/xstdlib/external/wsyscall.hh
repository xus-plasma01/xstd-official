#ifndef _syscall_wrapper_hh
#define _syscall_wrapper_hh

#define asmlinkage extern "C"

namespace xus
{

asmlinkage long xsyscall0(long number);
asmlinkage long xsyscall1(long number, long arg1);
asmlinkage long xsyscall2(long number, long arg1, long arg2);
asmlinkage long xsyscall3(long number, long arg1, long arg2, long arg3);
asmlinkage long xsyscall4(long number, long arg1, long arg2, long arg3, long arg4);
asmlinkage long xsyscall5(long number, long arg1, long arg2, long arg3, long arg4, long arg5);
asmlinkage long xsyscall6(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

}

#endif
