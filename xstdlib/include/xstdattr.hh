#ifndef _xstdattr_hh
#define _xstdattr_hh

#if defined(__GNUC__) || defined(__clang__)
#	define __noreturn 		__attribute__((noreturn))
#	define __nodiscard		__attribute__((warn_unused_result))
#else
#	define __noreturn 				[[noreturn]]
#	define __nodiscard 				[[nodiscard]]
#endif

#define _nodiscard		__nodiscard
#define _noreturn		__noreturn

#endif
