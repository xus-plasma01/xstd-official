#include "../include/xstdstring.hh"

Usize_t xus::strlen(const char *str)
{
	const char *ptr = str;
	while (*ptr)
		++ptr;

	return static_cast<Usize_t>(ptr - str);
}
