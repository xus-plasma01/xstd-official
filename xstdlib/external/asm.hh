#ifndef _asm_h
#define _asm_h

#ifdef __cplusplus
#ifndef _asm
#	define _asm				asm
#endif
#
#ifndef _unoptimize
#	define _unoptimize		volatile
#endif
#
#ifndef _asmlinkage
#	define _asmlinkage		extern "C"
#endif
#
#ifndef _noreturn
#	define _noreturn		[[noreturn]]
#endif
#elif defined(__GNUC__) || defined(__clang__)
#ifndef _asm
#	define _asm				__asm__
#endif
#
#ifndef _asm
#	define _unoptimize		__volatile__
#endif
#	
#ifndef _asmlinkage
#	define _asmlinkage
#endif
#
#ifndef _noreturn
#	define _noreturn __attribute__((noreturn))
#endif
#endif

#ifndef unoptimize
#	define unoptimize 	_unoptimize
#endif

#ifndef asmlinkage
#	define asmlinkage	_asmlinkage
#endif

#endif
