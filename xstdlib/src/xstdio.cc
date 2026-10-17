/// includes
#include "../include/xstdio.hh"
#include "../include/xstdsys.hh"

/// externals
#include "../external/sysnums.hh"
#include "../external/args.hh"

void xus::outc(char c)
{
	xus::vsyscall(
		4, 
		xus::xstdout, 
		1, 
		reinterpret_cast<long>(&c), 
		1);
}

int xus::getc(void)
{
	return xus::vsyscall(
		4,
		xus::xstdin,
		0,
		0,
		0);
}

void xus::outf(const char *fmt, ...)
{
	va_list xargs;
	va_start(xargs, fmt);

	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			switch(*fmt)
			{
			case '\0':
				xus::outc('%');
				goto end;
			case '%':
				xus::outc('%');
				break;
			case 's':
				{
					const char *s = va_arg(xargs, const char *);
					while (*s)
					{
						xus::outc(*s);
						++s;
					}

					break;
				}
			case 'd':
				{
					int value = va_arg(xargs, int);
					unsigned mag = value;
					if (value < 0)
					{
						xus::outc('-');
						mag = -value;
					}

					unsigned divisor = 1;
					while (mag / divisor > 9)
					{
						divisor *= 10;
					}

					while (divisor > 0)
					{
						xus::outc('0' + mag / divisor);
						mag %= divisor;
						divisor /= 10;
					}

					break;
				}
			case 'u':
				{
					switch(fmt[1])
					{
					case 'x':
						{
							unsigned val = va_arg(xargs, unsigned);

							unsigned prefix = val;
							if (prefix)
								{
									xus::outc('0');
									xus::outc('x');
								}
					
							for (int i = 7; i >= 0; i--)
								{
									unsigned nib = (val >> (i*4)) & 0xf;
									xus::outc("0123456789abcdef"[nib]);
								}
						}
					}

					break;
				}
			}
			++fmt;
		}
		else
			xus::outc(*fmt++);
	}
	end:	va_end(xargs);
}

void xus::outw(const char *str, ...)
{
	va_list vargs;
	va_start(vargs, str);
	xus::outf(str, vargs);
	va_end(vargs);
}

