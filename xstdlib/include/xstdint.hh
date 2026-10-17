#ifndef _xstdint_hh
#define _xstdint_hh

namespace xus 
{

#if defined(__GNUC__) || defined(__clang__)

typedef __SIZE_TYPE__		usize_t;
typedef signed long			ssize_t;

typedef __INT8_TYPE__		int8_t;
typedef __INT16_TYPE__		int16_t;
typedef __INT32_TYPE__		int32_t;
typedef __INT64_TYPE__		int64_t;

typedef __UINT8_TYPE__		uint8_t;
typedef __UINT16_TYPE__		uint16_t;
typedef __UINT32_TYPE__		uint32_t;
typedef __UINT64_TYPE__		uint64_t;

typedef int8_t		int8;
typedef int16_t		int16;
typedef int32_t		int32;
typedef int64_t		int64;

typedef int8	i8;
typedef int16	i16;
typedef int32	i32;
typedef int64	i64;

typedef __INT_LEAST8_TYPE__		int_least8_t;
typedef __INT_LEAST16_TYPE__	int_least16_t;
typedef __INT_LEAST32_TYPE__	int_least32_t;
typedef __INT_LEAST64_TYPE__	int_least64_t;

typedef int_least8_t			int_least8;
typedef int_least16_t			int_least16;
typedef int_least32_t			int_least32;
typedef int_least64_t			int_least64;

typedef int_least8				il8;
typedef int_least16				il16;
typedef int_least32				il32;
typedef int_least64				il64;

typedef __INT_FAST8_TYPE__		int_fast8_t;
typedef __INT_FAST16_TYPE__		int_fast16_t;
typedef __INT_FAST32_TYPE__		int_fast32_t;
typedef __INT_FAST64_TYPE__		int_fast64_t;

typedef int_fast8_t				int_fast8;
typedef int_fast16_t			int_fast16;
typedef int_fast32_t			int_fast32;
typedef int_fast64_t			int_fast64;

typedef int_fast8				if8;
typedef int_fast16				if16;
typedef int_fast32				if32;
typedef int_fast64				if64;


typedef uint8_t		uint8;
typedef uint16_t	uint16;
typedef uint32_t	uint32;
typedef uint64_t	uint64;

typedef uint8		u8;
typedef uint16		u16;
typedef uint32		u32;
typedef uint64		u64;

typedef __UINT_LEAST8_TYPE__	uint_least8_t;
typedef __UINT_LEAST16_TYPE__	uint_least16_t;
typedef __UINT_LEAST32_TYPE__	uint_least32_t;
typedef __UINT_LEAST64_TYPE__	uint_least64_t;

typedef uint_least8_t			uint_least8;
typedef uint_least16_t			uint_least16;
typedef uint_least32_t			uint_least32;
typedef uint_least64_t			uint_least64;

typedef uint_least8				ul8;
typedef uint_least16			ul16;
typedef uint_least32			ul32;
typedef uint_least64			ul64;

typedef __UINT_FAST8_TYPE__		uint_fast8_t;
typedef __UINT_FAST16_TYPE__	uint_fast16_t;
typedef __UINT_FAST32_TYPE__	uint_fast32_t;
typedef __UINT_FAST64_TYPE__	uint_fast64_t;

typedef uint_fast8_t			uint_fast8;
typedef uint_fast16_t			uint_fast16;
typedef uint_fast32_t			uint_fast32;
typedef uint_fast64_t			uint_fast64;

typedef uint_fast8				uf8;
typedef uint_fast16				uf16;
typedef uint_fast32				uf32;
typedef uint_fast64				uf64;

typedef __INTPTR_TYPE__			intptr_t;
typedef __UINTPTR_TYPE__		uintptr_t;

typedef intptr_t				intptr;
typedef uintptr_t				uintptr;

#else

/// UC = Unsupported Compiler
#warning "[warning UC] not using GCC or CLANG, revering to non-extension types"

typedef unsigned char		uint8_t;
typedef unsigned short		uint16_t;
typedef unsigned int		uint32_t;
typedef unsigned long		uint64_t;

typedef signed char			int8_t;
typedef signed short		int16_t;
typedef signed int			int32_t;
typedef signed long			int64_t;

typedef uint8_t				uint8;
typedef uint16_t			uint16;
typedef uint32_t			uint32;
typedef uint64_t			uint64;

typedef int8_t				int8;
typedef int16_t				int16;
typedef int32_t				int32;
typedef int64_t				int64;

typedef uint8 				u8;
typedef uint16 				u16;
typedef uint32				u32;
typedef uint64				u64;

typedef int8				i8;
typedef int16				i16;
typedef int32				i32;
typedef int64				i64;

typedef u32					usize_t;
typedef usize_t				usize;

typedef i32					ssize_t;
typedef ssize_t				ssize;

#endif

typedef usize_t Usize_t;
typedef ssize_t Ssize_t;
typedef Ssize_t	Isize_t;

typedef Usize_t	Usize;
typedef Ssize_t Ssize;
typedef Isize_t Isize;

typedef int8_t 	Int8_t;
typedef int16_t Int16_t;
typedef int32_t Int32_t;
typedef int64_t Int64_t;

typedef int8 	Int8;
typedef int16 	Int16;
typedef int32 	Int32;
typedef int64 	Int64;

typedef Int8	I8;
typedef Int16	I16;
typedef Int32	I32;
typedef Int64	I64;


typedef uint8_t		Uint8_t;
typedef uint16_t	Uint16_t;
typedef uint32_t	Uint32_t;
typedef uint64_t	Uint64_t;

typedef uint8		Uint8;
typedef uint16		Uint16;
typedef uint32		Uint32;
typedef uint64		Uint64;

typedef Uint8		U8;
typedef Uint16		U16;
typedef Uint32		U32;
typedef Uint64		U64;

static_assert(sizeof(uint8_t) 	== 1, "uint8_t must be 8 bits");
static_assert(sizeof(uint16_t) 	== 2, "uint16_t must be 16 bits");
static_assert(sizeof(uint32_t) 	== 4, "uint32_t must be 32 bits");
static_assert(sizeof(uint64_t) 	== 8, "uint64_t must be 64 bits");

static_assert(sizeof(Usize_t) == sizeof(Ssize_t), 
	"unsigned size type and signed size type must have equal size");

}

/// just incase i dont wna use the namespace
using int8_t		= xus::int8_t;
using int16_t		= xus::int16_t;
using int32_t		= xus::int32_t;
using int64_t		= xus::int64_t;

using uint8_t		= xus::uint8_t;
using uint16_t		= xus::uint16_t;
using uint32_t		= xus::uint32_t;
using uint64_t		= xus::uint64_t;


using Int8_t		= int8_t;
using Int16_t		= int16_t;
using Int32_t		= int32_t;
using Int64_t		= int64_t;

using Uint8_t		= uint8_t;
using Uint16_t		= uint16_t;
using Uint32_t		= uint32_t;
using Uint64_t		= uint64_t;


using Int8			= Int8_t;
using Int16			= Int16_t;
using Int32			= Int32_t;
using Int64			= Int64_t;
	
using Uint8			= Uint8_t;
using Uint16		= Uint16_t;
using Uint32		= Uint32_t;
using Uint64		= Uint64_t;

using I8			= xus::i8;
using I16			= xus::i16;
using I32			= xus::i32;
using I64 			= xus::i64;

using U8			= xus::u8;
using U16			= xus::u16;
using U32			= xus::u32;
using U64			= xus::u64;

using Usize_t		= xus::usize_t;
using Ssize_t		= xus::ssize_t;
using Isize_t		= Ssize_t;

using Usize			= Usize_t;
using Ssize			= Ssize_t;
using Isize			= Isize_t;

using Uintptr_t = xus::uintptr_t;
using Intptr_t	= xus::intptr_t;

using Iptr_t	= Intptr_t;
using Uptr_t	= Uintptr_t;

using Intptr	= Iptr_t;
using Uintptr	= Uptr_t;

using Iptr		= Iptr_t;
using Uptr		= Uptr_t;

#endif
