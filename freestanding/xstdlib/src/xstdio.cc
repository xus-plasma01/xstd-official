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
			switch(*fmt++)
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
			case 'x':
				{
					unsigned val = va_arg(xargs, unsigned);
					for (int i = 7; i >= 0; i--)
					{
						unsigned nib = (val >> (i*4)) & 0xf;
						xus::outc("0123456789abcdef"[nib]);
					}
				}
			}
		}
		else
			xus::outc(*fmt++);
	}
	end:	va_end(xargs);
}
