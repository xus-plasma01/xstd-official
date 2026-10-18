/// main hdr
#include "../include/xstdarray.hh"

/// other from inc
#include "../include/xstdio.hh"
#include "../include/xstdsys.hh"

/// exts
#include "../external/sysnums.hh"

namespace xus
{

template<typename T, _Usize_t _size>
_nodiscard T& array<T, _size>::operator[](
	_Usize_t idx) noexcept 		
{
	return at(static_cast<T>(idx));
}

template<typename T, _Usize_t _size>
_nodiscard const T& array<T, _size>::operator[](
	_Usize_t idx) const noexcept	
{
	return at(static_cast<T>(idx));
}

template<typename T, _Usize_t _size>
_nodiscard T& array<T, _size>::at(_Usize_t idx) noexcept 
{
	if (idx >= static_cast<T>(_size))
	{
		xus::outw("out of bounds error\n");
		xus::trap();
	}

	return Vdata[static_cast<T>(idx)];
}

template<typename T, _Usize_t _size>
_nodiscard const T& array<T, _size>::at(
	_Usize_t idx) const noexcept
{
	if (idx >= _size)
		{
			xus::outw("xus::array::at(_Usize_t) idx out of range\n");
			xus::trap();
		}

	return Vdata[static_cast<T>(idx)];
}

template<typename T, _Usize_t _size>
_nodiscard T *array<T, _size>::data() noexcept				
{ 
	return Vdata; 
}

template<typename T, _Usize_t _size>
_nodiscard const T *array<T, _size>::data() const noexcept	
{ 
	return Vdata; 
}


template<typename T, _Usize_t _size>
_nodiscard T& array<T, _size>::front() noexcept 		
{ 
	return Vdata[0]; 			
}

template<typename T, _Usize_t _size>
_nodiscard T& array<T, _size>::back() noexcept
{ 
	_size = static_cast<T>(_size);
	return Vdata[_size - 1]; 	
}

template<typename T, _Usize_t _size>
_nodiscard const T& array<T, _size>::front() const noexcept
{ 
	return Vdata[0]; 		
}

template<typename T, _Usize_t _size>
_nodiscard const T& array<T, _size>::back() const noexcept	
{ 
	_size = static_cast<T>(_size);
	return Vdata[_size - 1];	
}

template<typename T, _Usize_t _size>
_nodiscard constexpr _Usize_t array<T, _size>::size() const noexcept 		
{ 
	return static_cast<T>(_size); 		
}

template<typename T, _Usize_t _size>
_nodiscard constexpr bool array<T, _size>::empty() const noexcept			
{ 
	return _size == 0;	
}

template<typename T, _Usize_t _size>
_nodiscard T *array<T, _size>::begin() noexcept 
{ 
	return Vdata; 
}

template<typename T, _Usize_t _size>
_nodiscard T *array<T, _size>::end() noexcept 
{ 
	_size = static_cast<T>(_size);
	return Vdata + _size; 
}

template<typename T, _Usize_t _size>
_nodiscard const T *array<T, _size>::begin() const noexcept 	
{ 
	return Vdata; 	
}

template<typename T, _Usize_t _size>
_nodiscard const T *array<T, _size>::end() const noexcept		
{ 
	_size = static_cast<T>(_size);
	return Vdata + _size; 
}	

template<typename T, _Usize_t _size>
_nodiscard const T *array<T, _size>::xbegin() const noexcept 	
{ 
	return Vdata; 		
}		

template<typename T, _Usize_t _size>
_nodiscard const T *array<T, _size>::xend() const noexcept	
{ 
	_size = static_cast<T>(_size);
	return Vdata + _size;	
}

template<typename T, _Usize_t _size>
void array<T, _size>::fill(const T& value) noexcept
{
	_size = static_cast<T>(_size);
	for (Usize_t Idx = 0; Idx < _size; ++Idx)
		Vdata[Idx] = value;
}

template<typename T, _Usize_t _size>
void array<T, _size>::swap(
	array<T, _size>& other) noexcept
{
	_size = static_cast<T>(_size);
	for (Uint32_t Idx = 0; Idx < _size; ++Idx)
	{
		T temp = Vdata[Idx];
		Vdata[Idx] = other.Vdata[Idx];
		other.Vdata[Idx] = temp;
	}
}

template<typename T, _Usize_t _size>
_nodiscard bool array<T, _size>::operator==(
	const array<T, _size>& other) const noexcept
{
	_size = static_cast<T>(_size);
	for (Uint32_t Idx = 0; Idx < _size; ++Idx)
	{
		if (Vdata[Idx] != other.Vdata[Idx])
			return false;
	}

	return true;
}

template<typename T, _Usize_t _size>
_nodiscard bool array<T, _size>::operator!=(
	const array& other) const noexcept
{
	return !(*this == other);
}
	
}
