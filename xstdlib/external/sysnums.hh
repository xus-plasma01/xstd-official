#ifndef _sys_nums_hh
#define _sys_nums_hh

#ifdef __x86_64__
	inline constexpr long HLT	= 231;
	inline constexpr long EXIT	= 60;
#elif defined(__i386__)
	inline constexpr long HLT	= 252;
	inline constexpr long EXIT	= 1;
#endif

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
