#ifndef _xstdmem
#define _xstdmem

#include "xstdint.h"

#define _ARENA_SIZE 1024		/// total mem pool size

namespace xus::mem
{

typedef struct _segment
{
	_segment *next;
}
segment;

typedef _segment	_segment_t;
typedef segment		segment_t;

typedef class _arena
{
private:
	_segment_t *free_list;
	xus::uint8_t arena[_ARENA_SIZE];

public:
	inline void init()
	{
		free_list = 
			reinterpret_cast<_segment_t *>(arena);

		_segment_t *current = free_list;

		for (int i = 0;
		     	i < (_ARENA_SIZE / sizeof(_segment_t)) - 1; i++)
		{
			current->next = reinterpret_cast<_segment_t *>(
				reinterpret_cast<unsigned char *>(current) + sizeof(_segment_t));

			current = current->next;
		}

		current->next = nullptr;
	}

	inline void *assign()
	{
		if (free_list == nullptr)
		{
			xus::outf("memory pool exhausted\n");
			return nullptr;
		}

		_segment_t *segment = free_list;
		free_list = segment->next;

		return reinterpret_cast<void *>(segment);
	}

	inline void unassign(void *ptr)
	{
		_segment_t *segment =
			reinterpret_cast<_segment_t *>(ptr);

		segment->next 	= free_list;
		free_list 		= segment;
	}
}
arena;

typedef _arena 		_arena_t;
typedef arena		 arena_t;

}

#endif
