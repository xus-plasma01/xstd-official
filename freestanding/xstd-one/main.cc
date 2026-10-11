#include "xstdlib/xstdio"
#include "xstdlib/xstdsys"

extern "C" [[noreturn]] 
void _start()
{
	xus::outc('x');
	xus::outc('\n');

	xus::outf("Hello World!");

	xus::ret(0);
}
