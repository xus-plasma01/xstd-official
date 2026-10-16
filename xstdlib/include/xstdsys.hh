#ifndef _xstdsys_hh
#define _xstdsys_hh

/// externals
#include "../external/asm.hh"

/// defines
#define _noreturn __attribute__((noreturn))

namespace xus
{

_noreturn inline
void trap() 
{ 
	__builtin_trap(); 
}

_noreturn inline 
void unreachable() 
{ 
	__builtin_unreachable(); 
}

asmlinkage long vsyscall(int _args, long number, ...);
asmlinkage void ret(long number, long code);

}

#endif
