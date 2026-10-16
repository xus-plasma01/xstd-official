#ifndef _sys_nums_hh
#define _sys_nums_hh

namespace xus
{

inline constexpr long xstdin	= 0;
inline constexpr long xstdout	= 1;
inline constexpr long xstderr	= 2;

#ifdef __x86_64__
	inline constexpr long hlt 		= 231;
	inline constexpr long exit		= 60;
#endif

}

#endif
