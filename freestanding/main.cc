#include "xstdlib/xstdio"
#include "xstdlib/xstdsys"

extern "C" [[noreturn]]
void _start(void)
{
	xus::outc('c');
	xus::outc('\n');
	xus::outf("Hello World!\n");

	xus::ret(231, 0);
}
