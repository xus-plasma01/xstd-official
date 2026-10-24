#include "../include/xstdmem.hh"

#include "../include/xstdint.hh"
#include "../include/xstdio.hh"

Usize_t xus::mem::afm(
	usize_t size)
{
	size = arenasize + size;
	if (size > max_allowed_size)
		{
			xus::outw("[arena error] too much memory is being requested\n");
			return 0;
		}

	return size;
}

Usize_t xus::mem::afmm(
	usize_t size)
{
	return xus::mem::afm(size);
}

