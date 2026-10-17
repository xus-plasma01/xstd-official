#include "../include/xstdstring.hh"
#include "../include/xstdint.hh"

#ifdef __i386__
	typedef unsigned long long int __attribute__((__may_alias__)) 	op_t;
#else
	typedef unsigned long int __attribute__((__may_alias__)) 		op_t;
#endif

asmlinkage
{

Usize_t xus::strlen(const char *str) noexcept
{
	const char *ptr = str;
	while (*ptr)
		++ptr;

	return static_cast<Usize_t>(ptr - str);
}

void *xus::memset(
	void *dst, int val, Usize_t len) noexcept
{
#if defined(__GNUC__) || defined(__clang__)
	return __builtin_memset(dst, val, len);
#else
	#warning "[warning UC] not using gcc or clang, will revert to manual impl"
	unsigned char *ptr = dst;
	while (len-- > 0)
		*ptr++ = val;

	return dst;
#endif
}

void *xus::memcpy(
	void *dst, const void *src, Usize_t len) noexcept
{
#if defined(__GNUC__) || defined(__clang__)
	return __builtin_memcpy(dst, src, len);
#else
	#warning "[warning UC] not using gcc or clang, will revert to manual impl"
	char *d 		= dst;
	const char *s 	= src;
	while (len--)
		*d++ = *s++;

	return dest;
#endif
}

void *xus::memmove(
	void *dst, const void *src, Usize_t len) noexcept
{
#if defined(__GNUC__) || defined(__clang__)
	return __builtin_memmove(dst, src, len);
#else
	#warning "[warning UC] not using gcc or clang, will revert to manual impl"
	char *d 		= dst;
	const char *s 	= src;
	if (d < s)
		while (len--) *d++ = *s++;
#endif
}

char *xus::strcpy(
	char *dst, const char *src) noexcept
{
#if defined(__GNUC__) || defined(__clang__)
	return __builtin_strcpy(dst, src);
#else
	#warning "[warning UC] not using gcc or clang, will revert to manual impl"
	const Usize_t len = xus::strlen(src);
	xus::memcpy(dst, src, len + 1);
	return dst;
#endif
}

int xus::strcmp(
	const char *s1, const char *s2) noexcept
{
#if defined(__GNUC__) || defined(__clang__)
	return __builtin_strcmp(s1, s2);
#else
	#warning "[warning UC] not using gcc or clang, will revert to manual impl"
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break;

		s1++;
		s2++;
	}

	return 
		*static_cast<unsigned char *>(s1)
	  - *static_cast<unsigned char *>(s2);
#endif
}

};
