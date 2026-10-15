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

static_assert(sizeof(uint8_t) 	== 1, "uint8_t must be 8 bits");
static_assert(sizeof(uint16_t) 	== 2, "uint16_t must be 16 bits");
static_assert(sizeof(uint32_t) 	== 4, "uint32_t must be 32 bits");
static_assert(sizeof(uint64_t) 	== 8, "uint64_t must be 64 bits");

static_assert(sizeof(Usize_t) == sizeof(Ssize_t), 
	"unsigned size type and signed size type must have equal size");

}

#endif
