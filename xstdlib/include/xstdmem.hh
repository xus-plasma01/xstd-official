#ifndef _xstdmem_hh
#define _xstdmem_hh

#include "xstdint.hh"

inline Usize_t arenasize;
inline Usize_t max_allowed_size;

namespace xus::mem
{

typedef struct 
_segment_t
{
	_segment_t *next;
}
segment_t;

typedef _segment_t _segment;
typedef  segment_t 	segment;

template<typename T, Usize_t arena_size = arenasize>
class arena
{
	segment_t *list;
	unsigned char _arena[arena_size];

public:
	void init()
	{
		list = reinterpret_cast<segment *>(_arena);
		segment_t *crnt{ list };

		Usize_t store{ arena_size / sizeof(segment) };

		for (Usize_t i = 0; i < store - 1; i++)
		{
			crnt->next = reinterpret_cast<segment *>(
				reinterpret_cast<unsigned char *>(crnt) + sizeof(segment));

			crnt = crnt->next;
		}

		crnt->next = nullptr;
	}
	
	T *assign()
	{
		if (list == nullptr)
			return nullptr;

		segment *sgmt 	= list;
		list	 		= sgmt->next;

		return reinterpret_cast<T *>(sgmt);
	}
	
	void unassign(T *ptr)
	{
		segment *sgmt		= reinterpret_cast<segment *>(ptr);
		sgmt->next			= list;
		list				= sgmt;
	}

	T *operator()()
	{
		return assign();
	}

	void operator()(T *ptr)
	{
		unassign(ptr);
	}

	explicit arena() noexcept
	{
		init();
	}
};

Usize_t afm(xus::Usize_t size);
Usize_t afmm(xus::Usize_t size);
	
}

namespace xus { using namespace mem; }

#endif
