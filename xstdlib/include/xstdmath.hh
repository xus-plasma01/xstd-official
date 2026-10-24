#ifndef _xstdmath_hh
#define _xstdmath_hh

#ifdef __cplusplus
#	pragma once
#endif

namespace xus
{

struct vec2 { double x, y; };
struct vec3 { double x, y, z; };
struct vec4 { double w, x, y, z; };

template<typename T, typename... args_t>
inline constexpr T add(
	args_t... args) noexcept
{
	return (static_cast<T>(args) + ...);
}

template<typename T, typename... args_t>
inline constexpr T sub(
	args_t... args) noexcept
{
	return (... - static_cast<T>(args));
}

template<typename T, typename... args_t>
inline constexpr T mul(
	args_t... args) noexcept
{
	return (static_cast<T>(args) * ...);
}

template<typename T, typename... args_t>
inline constexpr T div(
	args_t... args) noexcept
{
	return (... / static_cast<T>(args));
}

}


#endif
