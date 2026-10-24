/// externals
#include "../xstdlib/external/asm.hh"
#include "../xstdlib/external/sysnums.hh"

/// stdlib features
#include "../xstdlib/xstdio"
#include "../xstdlib/xstdsys"
#include "../xstdlib/xstdmem"
#include "../xstdlib/xstdstring"
#include "../xstdlib/xstdarray"
#include "../xstdlib/xstdmath"

asmlinkage
void _start(void) 
{
/// [TEST 1] printing characters and string fmts
	xus::outw("\n[TEST 1] printing characters and string fmts\n\n");

	xus::outw("[FILES]\n");
	xus::outw("[INC] 	xstdlib/include/xstdio.hh\n");
	xus::outw("[SRC] 	xstdlib/src/xstdio.cc\n\n");
	
	xus::outw("[outputting a character] 	xus::outc(char)   		");
	xus::outc('c');
	xus::outc('\n');

	xus::outw("[outputting a string] 		xus::outw(const char *, ...)  	");
	xus::outw("Hello World!\n\n");

	xus::xout << "xus::xout << PASSED" << xus::endw;

	xus::outw("[END OF TEST 1]\n\n\n");

/// [TEST 2] memory arena allocation
	xus::outw("\n[TEST 2] memory arena allocation\n\n");

	xus::outw("[FILES]\n");
	xus::outw("[INC] 	xstdlib/include/xstdmem.hh\n");
	xus::outw("[SRC] 	xstdlib/src/xstdmem.cc\n");

	xus::arena<int, 1024> myarena;
	
	int *v0	= myarena();
	int *v1	= myarena();

	xus::outw("\nxus::arena_t arena;\n");
	xus::outw("allocated v0:	%x		using arena.assign()\n", v0);
	xus::outw("allocated v1:	%x		using arena.assign()\n", v1);

	myarena(v0);
	myarena(v1);

	xus::outc('\n');
	xus::outw("freed v0 and v1				using arena.unassign(void *)\n\n");
	xus::outw("[END OF TEST 2]\n\n\n");

	xus::outw("[TEST 3] testing xus::afmm (ask for more memory)\n\n");

	xus::outw("[FILES]\n");
	xus::outw("[INC]	xstdlib/include/xstdmem.hh\n");
	xus::outw("[SRC]	xstdlib/src/xstdmem.cc\n\n");

	xus::outw("[WARNING] xus::afmm(size) is NOT sbrk().\n");
	xus::outw("[WARNING] xus::afmm(size) is a temporary 'ask for more memory' function.\n");
	xus::outw("[WARNING] that'll eventually be replaced.\n");
	xus::outw("[WARNING] it doesn't use any virtual memory thing.\n");
	xus::outw("[WARNING] and the memory isn't unlimited. it has a tight roof\n");
	xus::outw("[WARNING] of how much memory is allowed.\n\n");

	xus::outw("[WARNING] Use it wisely!\n\n");

	xus::outw("[TEST 3] starting xus::afmm(size) ...\n");

	if (!xus::afmm(64))
		xus::outw("xus::afmm(size) fail\n\n");
	else
		xus::outw("xus::afmm(size) success\n\n");
		

	xus::outw("[END OF TEST 3]\n\n\n");


/// xus::string testing
	xus::outw("[TEST 4] testing xus::string\n\n");

	xus::string str = "Hello World!\n";
	xus::outw(str.raw());
	xus::outw("xus::string:		passed!\n\n");

	xus::xout << str;
	xus::xout << "xus::string (xout): 	passed!";
	xus::outw("\n");

	xus::wstring<char *, 32> name = "Hello World!";
	xus::outw("%s\n\n", name.raw());

	xus::outw("[END OF TEST 4]\n\n\n");

/// xstdarray
	xus::outw("[TEST 6] testing xstdarray\n\n");


	xus::array<int, 5> arr;
	
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	for (int i = 0; 
			i <= static_cast<int>(arr.size()) - 1; ++i)
		xus::outw("%d\n", arr[i]);


	xus::outw("xus::array: passed\n");

	xus::out << "[END OF TEST 6]\n\n" << xus::endw;


	xus::outw("[TEST 7] xstdmath\n\n");

   	int a = xus::add<int>(1, 5);
   	xus::outw("1 + 5 = %d\n", a);
	
	xus::outw("[END OF TEST 7]\n\n\n");

	xus::ret(EXIT);
}
