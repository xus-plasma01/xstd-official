#ifndef _xstdio
#define _xstdio

#include "xstdarg"
#include "xstdsys"

namespace xus
{

	
inline void putchar(char c)
{
	xus::vsyscall(
		7,
		PUTCHAR,
		static_cast<intptr_t>(1),
		reinterpret_cast<intptr_t>(&c),
		static_cast<intptr_t>(1),
		static_cast<intptr_t>(0),
		static_cast<intptr_t>(0),
		static_cast<intptr_t>(0)
	);
}

inline void outchar(char c)
{
	putchar(c);
}

inline void outc(char c)
{
	outchar(c);
}

inline int getchar(void)
{
	return xus::vsyscall(GETCHAR, 0, 0, 0);
}


/// xus::outf(fmt, ...)
inline void outf(const char *fmt, ...)
{
	va_list xargs;
	va_start(xargs, fmt);

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			switch(*fmt)
			{
			case '\0':
				{
					xus::outc('%');
					goto end;
				}
			case '%':
				{
					xus::outc('%');
					break;
				}
			case 's':
				{
					const char *s = va_arg(xargs, const char *);
					while (*s)
					{
						xus::outc(*s);
						s++;
					}
					break;
				}
			case 'd':
				{
					int value = va_arg(xargs, int);
					unsigned magnitude = value;
					if (value < 0)
					{
						xus::outc('-');
						magnitude = -value;
					}

					unsigned div = 1;
					while (magnitude / div > 9)
						div *= 10;

					while (div > 0)
					{
						xus::outc('0' + magnitude / div);
						magnitude %= div;
						div /= 10;
					}
					break;
				}
			case 'x':
				{
					unsigned value = va_arg(xargs, unsigned);
					for (int i = 7; i >= 0; i--)
					{
						unsigned n = (value >> (i * 4)) & 0xf;
						xus::putchar("0123456789abcdef"[n]);
					}

					break;
				}
			}
		}
		else
		{
			xus::outc(*fmt);
		}
		fmt++;
	}
	end:	va_end(xargs);
}

}

#endif
