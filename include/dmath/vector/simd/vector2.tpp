#pragma once

#include "../vector_any.tpp"

#ifdef __SSE2__
#include <x86intrin.h>

// -------------------------------------------------------------------------------------
// double
// -------------------------------------------------------------------------------------

template <>
struct VectorStorage<double, 2>
{
    alignas(__m128d) double data[2];
};

template <>
MATH_INLINE Vector<double, 2> operator+(const Vector<double, 2> &lhs, const Vector<double, 2> &rhs)
{
    Vector<double, 2> result;
    __m128d left = *reinterpret_cast<const __m128d *>(lhs.data());
    __m128d right = *reinterpret_cast<const __m128d *>(rhs.data());
    _mm_store_pd(result.data(), _mm_add_pd(left, right));

    return result;
}

template <>
MATH_INLINE Vector<double, 2> operator-(const Vector<double, 2> &lhs, const Vector<double, 2> &rhs)
{
    Vector<double, 2> result;
    __m128d left = *reinterpret_cast<const __m128d *>(lhs.data());
    __m128d right = *reinterpret_cast<const __m128d *>(rhs.data());
    _mm_store_pd(result.data(), _mm_sub_pd(left, right));

    return result;
}

template <>
MATH_INLINE Vector<double, 2> operator*(const Vector<double, 2> &lhs, const Vector<double, 2> &rhs)
{
    Vector<double, 2> result;
    __m128d left = *reinterpret_cast<const __m128d *>(lhs.data());
    __m128d right = *reinterpret_cast<const __m128d *>(rhs.data());
    _mm_store_pd(result.data(), _mm_mul_pd(left, right));

    return result;
}

template <>
MATH_INLINE Vector<double, 2> operator/(const Vector<double, 2> &lhs, const Vector<double, 2> &rhs)
{
    Vector<double, 2> result;
    __m128d left = *reinterpret_cast<const __m128d *>(lhs.data());
    __m128d right = *reinterpret_cast<const __m128d *>(rhs.data());
    _mm_store_pd(result.data(), _mm_div_pd(left, right));

    return result;
}

template <>
MATH_INLINE Vector<double, 2> &operator+=(Vector<double, 2> &lhs, const Vector<double, 2> &rhs)
{
    __m128d left = *reinterpret_cast<const __m128d *>(lhs.data());
    __m128d right = *reinterpret_cast<const __m128d *>(rhs.data());
    _mm_store_pd(lhs.data(), _mm_add_pd(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<double, 2> &operator-=(Vector<double, 2> &lhs, const Vector<double, 2> &rhs)
{
    __m128d left = *reinterpret_cast<const __m128d *>(lhs.data());
    __m128d right = *reinterpret_cast<const __m128d *>(rhs.data());
    _mm_store_pd(lhs.data(), _mm_sub_pd(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<double, 2> &operator*=(Vector<double, 2> &lhs, const Vector<double, 2> &rhs)
{
    __m128d left = *reinterpret_cast<const __m128d *>(lhs.data());
    __m128d right = *reinterpret_cast<const __m128d *>(rhs.data());
    _mm_store_pd(lhs.data(), _mm_mul_pd(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<double, 2> &operator/=(Vector<double, 2> &lhs, const Vector<double, 2> &rhs)
{
    __m128d left = *reinterpret_cast<const __m128d *>(lhs.data());
    __m128d right = *reinterpret_cast<const __m128d *>(rhs.data());
    _mm_store_pd(lhs.data(), _mm_div_pd(left, right));

    return lhs;
}

template <>
MATH_INLINE auto dot(const Vector<double, 2> &lhs, const Vector<double, 2> &rhs)
{
    __m128d left = *reinterpret_cast<const __m128d *>(lhs.data());
    __m128d right = *reinterpret_cast<const __m128d *>(rhs.data());
    left = _mm_mul_pd(left, right);
    double *result = reinterpret_cast<double *>(&left);

    return result[0] + result[1];
}

// -------------------------------------------------------------------------------------
// 64-bit signed integer
// -------------------------------------------------------------------------------------

template <>
struct VectorStorage<int64_t, 2>
{
    alignas(__m128i) int64_t data[2];
};

template <>
MATH_INLINE Vector<int64_t, 2> operator+(const Vector<int64_t, 2> &lhs, const Vector<int64_t, 2> &rhs)
{
    Vector<int64_t, 2> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_add_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<int64_t, 2> operator-(const Vector<int64_t, 2> &lhs, const Vector<int64_t, 2> &rhs)
{
    Vector<int64_t, 2> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_sub_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<int64_t, 2> operator*(const Vector<int64_t, 2> &lhs, const Vector<int64_t, 2> &rhs)
{
    Vector<int64_t, 2> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_mullo_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<int64_t, 2> &operator+=(Vector<int64_t, 2> &lhs, const Vector<int64_t, 2> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_add_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<int64_t, 2> &operator-=(Vector<int64_t, 2> &lhs, const Vector<int64_t, 2> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_sub_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<int64_t, 2> &operator*=(Vector<int64_t, 2> &lhs, const Vector<int64_t, 2> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_mullo_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE auto dot(const Vector<int64_t, 2> &lhs, const Vector<int64_t, 2> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    left = _mm_mullo_epi64(left, right);
    int64_t *result = reinterpret_cast<int64_t *>(&left);

    return result[0] + result[1];
}

// -------------------------------------------------------------------------------------
// 64-bit unsigned integer
// -------------------------------------------------------------------------------------

template <>
struct VectorStorage<uint64_t, 2>
{
    alignas(__m128i) uint64_t data[2];
};

template <>
MATH_INLINE Vector<uint64_t, 2> operator+(const Vector<uint64_t, 2> &lhs, const Vector<uint64_t, 2> &rhs)
{
    Vector<uint64_t, 2> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_add_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<uint64_t, 2> operator-(const Vector<uint64_t, 2> &lhs, const Vector<uint64_t, 2> &rhs)
{
    Vector<uint64_t, 2> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_sub_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<uint64_t, 2> operator*(const Vector<uint64_t, 2> &lhs, const Vector<uint64_t, 2> &rhs)
{
    Vector<uint64_t, 2> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_mullo_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<uint64_t, 2> &operator+=(Vector<uint64_t, 2> &lhs, const Vector<uint64_t, 2> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_add_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<uint64_t, 2> &operator-=(Vector<uint64_t, 2> &lhs, const Vector<uint64_t, 2> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_sub_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<uint64_t, 2> &operator*=(Vector<uint64_t, 2> &lhs, const Vector<uint64_t, 2> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_mullo_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE auto dot(const Vector<uint64_t, 2> &lhs, const Vector<uint64_t, 2> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    left = _mm_mullo_epi64(left, right);
    uint64_t *result = reinterpret_cast<uint64_t *>(&left);

    return result[0] + result[1];
}

#endif