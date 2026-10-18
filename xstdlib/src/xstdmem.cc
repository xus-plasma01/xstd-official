#include "../include/xstdmem.hh"

#include "../include/xstdint.hh"
#include "../include/xstdio.hh"


void xus::_arena_t::init() noexcept
{
	list				= reinterpret_cast<_segment_t *>(arena);
	_segment_t *crnt{ list };

	xus::usize_t store{ arena_size / sizeof(_segment_t) };

	for (int i = 0; i < store - 1; i++)
	{
		crnt->next = reinterpret_cast<_segment_t *>(
			reinterpret_cast<unsigned char *>(crnt) + sizeof(_segment_t));

		crnt = crnt->next;
	}

	crnt->next = nullptr;
}

Usize_t xus::afm(
	usize_t size) noexcept
{
	size = arena_size + size;
	if (size > max_allowed_size)
		{
			xus::outw("[arena error] too much memory is being requested\n");
			return 0;
		}

	return size;
}

Usize_t xus::afmm(
	usize_t size) noexcept
{
	return xus::afm(size);
}

void *xus::_arena_t::assign() noexcept
{
	if (list == nullptr)
		{
			xus::outw("[arena error] memory arena exhausted\n");
			return nullptr;
		}

	_segment *seg	= list;
	list			= seg->next;

	return reinterpret_cast<void *>(seg);
}

void xus::_arena_t::unassign(void *ptr) noexcept
{
	_segment *seg	= reinterpret_cast<_segment_t *>(ptr);
	seg->next		= list;
	list			= seg;
}
