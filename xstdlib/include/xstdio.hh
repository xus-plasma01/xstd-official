#ifndef _xstdio_hh
#define _xstdio_hh

#include "xstdstring.hh"

namespace xus
{

void 	outc(char c);
int 	getc(void);
void	outw(const char *fmt, ...);

class xstream
{
public:	
	xus::xstream& operator<<(const xus::string& str)
	{
		outw(str.raw());
		return *this;
	}

	xus::xstream& operator<<(const char *str)
	{
		outw(str);
		return *this;
	}

	xus::xstream& operator<<(char c)
	{
		outc(c);
		return *this;
	}
};

extern xstream& xout;

}

#endif
