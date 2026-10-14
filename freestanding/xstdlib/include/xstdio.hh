#ifndef _xstdio_hh
#define _xstdio_hh

namespace xus
{

/// xus::outc(char)
void 	outc(char c);

/// xus::getc(void);
int 	getc(void);

/// xus::outf(cosnt char *, ...);
void	outf(const char *fmt, ...);

/// xus::outw(const char *, ...);
void	outw(const char *str, ...);

}

#endif
