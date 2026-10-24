#ifndef _xstdassert_hh
#define _xstdassert_hh

#define assertion(condition, message, exitenum)		\
	do												\
	{												\
		if (!(condition))							\
		{											\
			xus::outw(message);						\
	 		xus::ret(exitenum);						\
		}											\
	} while (0)


#endif
