#include "xstdlib/xstdio"
#include "xstdlib/xstdsys"
#include "xstdlib/xstdmem"

extern "C" [[noreturn]]
void _start(void)
{
	xus::outc('c');
	xus::outc('\n');
	xus::outw("xus::outw(const char *, ...) string\n");

	xus::arena arena;
	arena.init();

	void *v0	= arena.assign();
	void *v1	= arena.assign();

	xus::outw("allocated v0:	%x\n", v0);
	xus::outw("allocated v1:	%x\n", v1);

	arena.unassign(v0);
	arena.unassign(v1);
	xus::outw("freed v0 and v1\n");
	
	xus::ret(231, 0);
}
