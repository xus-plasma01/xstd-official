#ifndef _xstdmem_hh
#define _xstdmem_hh

#include "xstdint.hh"

constexpr int arena_size{ 1024 };

namespace xus
{

typedef struct 
_segment_t
{
	_segment_t *next;
}
segment_t;

typedef _segment_t _segment;
typedef  segment_t 	segment;

typedef class
_arena_t
{
private:
	_segment_t *list;
	uint8		arena[arena_size];

public:
	void init();
	void *assign();
	void unassign(void *ptr);
}
arena_t;

typedef _arena_t 	_arena;
typedef	 arena_t 	 arena;
	
}

#endif
