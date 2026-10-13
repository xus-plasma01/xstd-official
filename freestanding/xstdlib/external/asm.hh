#ifndef _asm_h
#define _asm_h

#ifdef __cplusplus
#	define _asm				asm
#	define _unoptimize		volatile
#	define _asmlinkage		extern "C"
#elif defined(__STDC__)
#	define _asm				__asm__
#	define _unoptimize		__volatile__
#	define _asmlinkage
#endif

#define unoptimize 	_unoptimize
#define asmlinkage	_asmlinkage

#endif
