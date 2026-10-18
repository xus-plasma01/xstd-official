#ifndef _xstdsys_hh
#define _xstdsys_hh

/// externals
#include "../external/asm.hh"

namespace xus
{

_noreturn inline void trap() 		noexcept	{ __builtin_trap();			}
_noreturn inline void unreachable() noexcept	{ __builtin_unreachable();	}

asmlinkage long vsyscall(int _args, long number, ...) noexcept;
asmlinkage _noreturn void ret(long number, long code) noexcept;

}

#endif
