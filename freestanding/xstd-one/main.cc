#include "xstdlib/xstdio"
#include "xstdlib/xstdsys"
#include "xstdlib/xstdmem"

extern "C" [[noreturn]] 
void _start()
{
	/// printing chars and fmts
	xus::outc('x');
	xus::outc('\n');
	xus::outf("Hello World!");


	/// memory testing
	xus::mem::arena arena;

	arena.init();

	void *b1 = arena.assign();
	void *b2 = arena.assign();

	xus::outf("allocated b1: %x\n", b1);
	xus::outf("allocated b2: %x\n", b2);

	arena.unassign(b1);
	arena.unassign(b2);
	xus::outf("freed b1 and b2\n");

	xus::ret(0);
}
