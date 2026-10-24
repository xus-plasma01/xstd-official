/// includes
#include "../include/xstdio.hh"
#include "../include/xstdsys.hh"

/// externals
#include "../external/sysnums.hh"
#include "../external/args.hh"

static xus::xstream streamrock;

xus::xstream& 	xus::xout 	= streamrock;
xus::xstream& 	xus::out	= streamrock;
char			xus::endw	= '\n';	

void xus::outc(char c) noexcept
{
	xus::vsyscall(
		4,
		WWRITE, 
		1, 
		reinterpret_cast<long>(&c), 
		1);
}

int xus::getc(void) noexcept
{
	return xus::vsyscall(
		4,
		WREAD,
		0,
		0,
		0);
}

static void outhex(unsigned value) noexcept
{
	unsigned pre = value;
	if (pre)
	{
		xus::outc('0');
		xus::outc('x');
	}

	for (int i = 7; i >= 0; i--)
	{
		unsigned nib = (value >> (i*4)) & 0xf;
		xus::outc("0123456789abcdef"[nib]);
	}
}

static void outstr(const char *s) noexcept
{ 
	while (*s)
	{
		xus::outc(*s);
		s++;
	}
}


static void outint(int value) noexcept
{
	unsigned mag = value;
	if (value < 0)
	{
		xus::outc('-');
		mag = -value;
	}

	unsigned div = 1;
	while (mag / div > 9)
		div *= 10;

	while (div > 0)
	{
		xus::outc('0' + mag / div);
		mag %= div;
		div /= 10;
	}
}


void xus::outw(
	const char *fmt, ...) noexcept
{
	va_list vargs;
	va_start(vargs, fmt);

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
					const char *s = va_arg(vargs, const char *);
					outstr(s);
					break;
				}
			case 'd':
				{
					int value = va_arg(vargs, int);
					outint(value);
					break;
				}
			case 'x':
				{
					unsigned value = va_arg(vargs, unsigned);
					outhex(value);
					break;
				}
			}
			++fmt;
		}
		else
			xus::outc(*fmt++);
	}
	end: va_end(vargs);
}
