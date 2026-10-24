#ifndef _xstdstring_hh
#define _xstdstring_hh

#include "../external/asm.hh"

#include "xstdint.hh"

namespace xus::str
{

asmlinkage 
{

void *		memset(void *dst, int val, Usize_t len) 			noexcept;
void *		memcpy(void *dst, const void *src, Usize_t len)		noexcept;
void *		memmove(void *dst, const void *src, Usize_t len) 	noexcept;

Usize_t 	strlen(const char *str) 					noexcept;
char * 		strcpy(char *dst, const char *src) 			noexcept;
int			strcmp(const char *s1, const char *s2) 		noexcept;

}

template<typename T, Usize_t N>
class wstring
{
	T data[N];

public:
	constexpr wstring() = default;

	constexpr wstring(T _data) noexcept
	{
		Usize_t n = 0;
		while (data[n] != T{} && n + 1 < N)
		{
			_data[n] = *data[n];
			++n;
		}

		data[n] = T{};
	}
	
	constexpr 		T *raw() 		noexcept { return data; }
	constexpr const T *raw() const 	noexcept { return data; }

	constexpr Usize_t size() const noexcept
	{
		Usize_t n = 0;
		while (n < N && data[n] != T{}) ++n;
		return n;
	}
};

class string 
{
	const char *	_raw_str{};
	Usize_t 		_length{};
	Usize_t			_cap{};

public:
	constexpr string(char *src) noexcept
		: _raw_str{ const_cast<char *>(src) }
		, _length{ strlen(src) }
	{}

	constexpr string(const char *src) noexcept
		: _raw_str{ src }
		, _length{ strlen(src) }
	{}

	constexpr const char *raw() 	const noexcept 	{ return _raw_str;		}	
	constexpr Usize_t size()		const noexcept	{ return _length; 		}
	constexpr Usize_t empty()		const noexcept 	{ return _length == 0;	}
	constexpr Usize_t cap()			const noexcept 	{ return _cap;			}

	//string& operator+(const string& str);
};
	
}

namespace xus { using namespace str; }

#endif
