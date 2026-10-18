#ifndef _xstdio_hh
#define _xstdio_hh

#include "xstdstring.hh"

namespace xus
{

void 	outc(char c) 					noexcept;
int 	getc(void)						noexcept;
void	outw(const char *fmt, ...)		noexcept;

class xstream
{
public:	
	xus::xstream& operator<<(const xus::string& str) noexcept
	{
		outw(str.raw());
		return *this;
	}

	xus::xstream& operator<<(const char *str) noexcept
	{
		outw(str);
		return *this;
	}

	xus::xstream& operator<<(char c) noexcept
	{
		outc(c);
		return *this;
	}
};

extern xstream& xout;
extern xstream& out;
extern char		endw;

}

#endif
