#pragma once

#include "../vector.tpp"

template <>
Vector<float, 4> operator+(const Vector<float, 4> &left, const Vector<float, 4> &right)
{
    Vector<float, 4> result;

    __m128 a_simd = *reinterpret_cast<__m128*>(const_cast<float*>(left.data()));
    __m128 b_simd = *reinterpret_cast<__m128*>(const_cast<float*>(right.data()));
    _mm_store_ps(result.data(), _mm_add_ps(a_simd, b_simd));

    return result;
}

template <std::size_t N>
auto operator+(const Vector<float, N> &left, const Vector<float, N> &right) -> typename std::enable_if_t<N % 4 == 0 && (N > 4), Vector<float, N>>
{
    Vector<float, N> result;
    __m128 a_simd;
    __m128 b_simd;

    for(size_t i = 0; i < N; i += 4)
    {
	    a_simd = *reinterpret_cast<__m128*>(const_cast<float*>(left.data() + i));
	    b_simd = *reinterpret_cast<__m128*>(const_cast<float*>(right.data() + i));

        _mm_store_ps(result.data() + i, _mm_add_ps(a_simd, b_simd));
    }
    return result;
}
