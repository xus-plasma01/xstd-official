#ifndef _xstdstring_hh
#define _xstdstring_hh

#include "xstdint.hh"

namespace xus
{

Usize_t strlen(const char *str);

class string
{
private:
	const char *_raw_str;
	xus::Usize_t _length;

public:
	string(const char *data)
	: _raw_str{data}
	, _length{strlen(data)}
	{}
	
	const char *raw() 		{ return _raw_str;		}
	Usize_t size()			{ return _length; 		}
};
	
}

#endif
