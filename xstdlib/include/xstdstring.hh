#ifndef _xstdstring_hh
#define _xstdstring_hh

#include "../external/asm.hh"

#include "xstdint.hh"

namespace xus
{

asmlinkage 
{

void *		memset(void *dst, int val, Usize_t len) noexcept;
void *		memcpy(void *dst, const void *src, Usize_t len) noexcept;
void *		memmove(void *dst, const void *src, Usize_t len) noexcept;

Usize_t 	strlen(const char *str) noexcept;
char * 		strcpy(char *dst, const char *src) noexcept;
int			strcmp(const char *s1, const char *s2) noexcept;

}

class string
{
private:
	const char *_raw_str;
	Usize_t 	_length;

public:
	constexpr string(const char *data)
	: _raw_str{data}
	, _length{strlen(data)}
	{}
	
	inline const char *raw() 	const noexcept 	{ return _raw_str;		}
	inline Usize_t size()		const noexcept	{ return _length;		}
	inline Usize_t empty()		const noexcept 	{ return _length == 0;	}
};
	
}

#endif
