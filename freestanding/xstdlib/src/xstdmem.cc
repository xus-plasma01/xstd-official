#include "../include/xstdmem.hh"

#include "../include/xstdint.hh"
#include "../include/xstdio.hh"

void xus::_arena_t::init()
{
	list				= reinterpret_cast<_segment_t *>(arena);
	_segment_t *crnt	= list;

	for (int i = 0; 
			i < (arena_size / sizeof(_segment_t)) - 1; i++)
	{
		crnt->next = reinterpret_cast<_segment_t *>(
			reinterpret_cast<unsigned char *>(crnt) + sizeof(_segment_t));

		crnt = crnt->next;
	}

	crnt->next = nullptr;
}

void *xus::_arena_t::assign()
{
	if (list == nullptr)
	{
		xus::outw("memory arena exhausted\n");
		return nullptr;
	}

	_segment *seg	= list;
	list			= seg->next;

	return reinterpret_cast<void *>(seg);
}

void xus::_arena_t::unassign(void *ptr)
{
	_segment *seg	= reinterpret_cast<_segment_t *>(ptr);
	seg->next		= list;
	list			= seg;
}
