#ifndef _xstdarray_hh
#define _xstdarray_hh

#include "xstdint.hh"

#if defined(__GNUC__) || defined(__clang__)
#	define _nodiscard __attribute__((warn_unused_result))
#else
#	define _nodiscard [[nodiscard]]
#endif

using _Usize_t = Usize_t;

namespace xus
{

template<typename T, _Usize_t _size>
class array
{
private:
	T Vdata[_size];

public:
	_nodiscard T& operator[](_Usize_t idx) noexcept;				///< unchecked elem acc
	_nodiscard const T& operator[](_Usize_t idx) const noexcept;	///< const o.l of operator[]

	_nodiscard T& at(_Usize_t idx) noexcept;					///< bounds check elem acc
	_nodiscard const T& at(_Usize_t idx) const noexcept;		///< const at()
	_nodiscard T *data() noexcept;								///< ptr to first elem
	_nodiscard const T *data() const noexcept;					///< const data()
	_nodiscard T& front() noexcept;								///< returns first elem
	_nodiscard T& back() noexcept;								///< returns last elem
	_nodiscard const T& front() const noexcept;					///< const front()
	_nodiscard const T& back() const noexcept;					///< const back()

	_nodiscard constexpr _Usize_t size() const noexcept;		///< return comptime num of elems
	_nodiscard constexpr bool empty() const noexcept;			///< return true when arr contain 0 elem

	_nodiscard T *begin() noexcept;		///< iter to first elem
	_nodiscard T *end() noexcept;		///< iter one pos past last elem

	_nodiscard const T *begin() const noexcept;	///< const begin()
	_nodiscard const T *end() const noexcept;		///< const end();

	_nodiscard const T *xbegin() const noexcept;	///< always ret const iter
	_nodiscard const T *xend() const noexcept;		///< always ret const iter one pos past end

	void fill(const T& value) noexcept;			///< assign same val to every elem
	void swap(array& other) noexcept;			///< exchange elem with another array

	_nodiscard bool operator==(const array& other) const noexcept;	///< cmp two array elem by elem
	_nodiscard bool operator!=(const array& other) const noexcept;	///< ret true when arrays differ
};

template<typename _t1, typename... _t2>
array(_t1, _t2...) -> array<_t1, 1 + sizeof...(_t2)>; 

}

#endif
