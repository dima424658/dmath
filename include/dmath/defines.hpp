#pragma once

#ifdef MATH_NOINLINE
#   define MATH_INLINE
#else
#   define MATH_INLINE inline
#endif

#ifdef MATH_NOCONSTEXPR
#   define MATH_CONSTEXPR
#else
#   define MATH_CONSTEXPR constexpr
#endif
