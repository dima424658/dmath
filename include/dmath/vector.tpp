//#define MATH_NOINLINE
//#define MATH_NOCONSTEXPR

#include "vector/vector_any.tpp"

#ifndef MATH_NOSIMD
#   include "vector/simd/vector3.tpp"
#   include "vector/simd/vector4.tpp"
#endif