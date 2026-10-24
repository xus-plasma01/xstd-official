#ifndef _asm_h
#define _asm_h

#include "../include/xstdattr.hh"

#ifdef __cplusplus
#	define _asm				asm
#	define _unoptimize		volatile
#	define _asmlinkage		extern "C"
#elif defined(__GNUC__) || defined(__clang__)
#	define _asm				__asm__
#	define _unoptimize		__volatile__
#	define _asmlinkage
#endif

#define unoptimize 	_unoptimize
#define asmlinkage	_asmlinkage

#endif
