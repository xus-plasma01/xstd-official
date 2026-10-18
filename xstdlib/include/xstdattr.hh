#ifndef _xstdattr_hh
#define _xstdattr_hh

#if defined(__GNUC__) || defined(__clang__)
#       define _forceptr        __attribute__((force_align_arg_pointer))
#       define _noreturn        __attribute__((noreturn))
#       define _nodiscard       __attribute__((warn_unused_result))
#       define _section(...)    __attribute__((section(__VA_ARGS__)))
#else
#       define _noreturn                [[noreturn]]
#       define _nodiscard               [[nodiscard]]
#       define _fallthrough             [[fallthrough]]
#       define _maybe_unused            [[maybe_unused]]
#       define _deprecated(msg)         [[deprecated(msg)]]
#       define _no_unique_address       [[no_unique_address]]
#endif

#if __has_cpp_attribute(likely) >= 201803L
#       define _likely 		[[likely]]
#       define _unlikely    [[unlikely]]
#else
#       define _likely
#       define _unlikely
#endif

#endif
