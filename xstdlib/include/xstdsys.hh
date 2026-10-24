#ifndef _xstdsys_hh
#define _xstdsys_hh

/// externals
#include "../external/asm.hh"

#include "xstdint.hh"

#if defined(__GNUC__) || defined(__clang__)
#	define maybe_unused __attribute__((unused))
#else
#	define maybe_unused [[maybe_unused]]
#endif

enum _exit_t : long
{
	UNREACHABLE,
	TRAP,
	LOOP,
	EXIT
};

namespace xus
{

_noreturn inline void trap() 		noexcept	{ __builtin_trap();			}
_noreturn inline void unreachable() noexcept	{ __builtin_unreachable();	}

asmlinkage long vsyscall(int _args, long number, ...) 	noexcept;
asmlinkage _noreturn void ret(long number) 				noexcept;

}

#endif
