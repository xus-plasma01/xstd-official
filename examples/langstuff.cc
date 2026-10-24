#include "../xstdlib/xstdio"
#include "../xstdlib/xstdsys"
#include "../xstdlib/external/sysnums.hh"
#include "../xstdlib/external/asm.hh"
#include "../xstdlib/xstdint"
#include "../xstdlib/xstdarray"
#include "../xstdlib/xstdir"

using namespace xus::kkr;

asmlinkage
void _start(void)
{
	start(dt::I32, "_start()");
	
	auto v0 = store("v0", dt::I32, 10);
	auto v1 = store("v1", dt::I32, 20);
	auto v2 = add("v2", dt::I32, v0, v1);

	ret(dt::I32, "v2", v2);

	end();

	xus::ret(EXIT);
}
