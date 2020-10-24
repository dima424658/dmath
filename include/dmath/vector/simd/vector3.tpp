#pragma once

#include "../vector_any.tpp"

#ifdef __SSE2__
#include <x86intrin.h>

// -------------------------------------------------------------------------------------
// float
// -------------------------------------------------------------------------------------

template <>
struct VectorStorage<float, 3>
{
    alignas(__m128) float data[4];
};

template <>
MATH_INLINE Vector<float, 3> operator+(const Vector<float, 3> &lhs, const Vector<float, 3> &rhs)
{
    Vector<float, 3> result;
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(result.data(), _mm_add_ps(left, right));

    return result;
}

template <>
MATH_INLINE Vector<float, 3> operator-(const Vector<float, 3> &lhs, const Vector<float, 3> &rhs)
{
    Vector<float, 3> result;
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(result.data(), _mm_sub_ps(left, right));

    return result;
}

template <>
MATH_INLINE Vector<float, 3> operator*(const Vector<float, 3> &lhs, const Vector<float, 3> &rhs)
{
    Vector<float, 3> result;
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(result.data(), _mm_mul_ps(left, right));

    return result;
}

template <>
MATH_INLINE Vector<float, 3> operator/(const Vector<float, 3> &lhs, const Vector<float, 3> &rhs)
{
    Vector<float, 3> result;
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(result.data(), _mm_div_ps(left, right));

    return result;
}

template <>
MATH_INLINE Vector<float, 3> &operator+=(Vector<float, 3> &lhs, const Vector<float, 3> &rhs)
{
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(lhs.data(), _mm_add_ps(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<float, 3> &operator-=(Vector<float, 3> &lhs, const Vector<float, 3> &rhs)
{
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(lhs.data(), _mm_sub_ps(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<float, 3> &operator*=(Vector<float, 3> &lhs, const Vector<float, 3> &rhs)
{
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(lhs.data(), _mm_mul_ps(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<float, 3> &operator/=(Vector<float, 3> &lhs, const Vector<float, 3> &rhs)
{
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(lhs.data(), _mm_div_ps(left, right));

    return lhs;
}

template <>
auto dot(const Vector<float, 3> &lhs, const Vector<float, 3> &rhs)
{
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    left = _mm_mul_ps(left, right);
    float *result = reinterpret_cast<float *>(&left);

    return result[0] + result[1] + result[2] + result[3];
}

// -------------------------------------------------------------------------------------
// 32-bit signed integer
// -------------------------------------------------------------------------------------

template <>
struct VectorStorage<int32_t, 3>
{
    alignas(__m128i) int32_t data[4];
};

template <>
MATH_INLINE Vector<int32_t, 3> operator+(const Vector<int32_t, 3> &lhs, const Vector<int32_t, 3> &rhs)
{
    Vector<int32_t, 3> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_add_epi32(left, right));

    return result;
}

template <>
MATH_INLINE Vector<int32_t, 3> operator-(const Vector<int32_t, 3> &lhs, const Vector<int32_t, 3> &rhs)
{
    Vector<int32_t, 3> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_sub_epi32(left, right));

    return result;
}

template <>
MATH_INLINE Vector<int32_t, 3> operator*(const Vector<int32_t, 3> &lhs, const Vector<int32_t, 3> &rhs)
{
    Vector<int32_t, 3> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_mullo_epi32(left, right));

    return result;
}

template <>
MATH_INLINE Vector<int32_t, 3> &operator+=(Vector<int32_t, 3> &lhs, const Vector<int32_t, 3> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_add_epi32(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<int32_t, 3> &operator-=(Vector<int32_t, 3> &lhs, const Vector<int32_t, 3> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_sub_epi32(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<int32_t, 3> &operator*=(Vector<int32_t, 3> &lhs, const Vector<int32_t, 3> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_mullo_epi32(left, right));

    return lhs;
}

template <>
MATH_INLINE auto dot(const Vector<int32_t, 2> &lhs, const Vector<int32_t, 2> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    left = _mm_mullo_epi32(left, right);
    int32_t *result = reinterpret_cast<int32_t *>(&left);

    return result[0] + result[1];
}

// -------------------------------------------------------------------------------------
// 32-bit unsigned integer
// -------------------------------------------------------------------------------------

template <>
struct VectorStorage<uint32_t, 3>
{
    alignas(__m128i) uint32_t data[4];
};

template <>
MATH_INLINE Vector<uint32_t, 3> operator+(const Vector<uint32_t, 3> &lhs, const Vector<uint32_t, 3> &rhs)
{
    Vector<uint32_t, 3> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_add_epi32(left, right));

    return result;
}

template <>
MATH_INLINE Vector<uint32_t, 3> operator-(const Vector<uint32_t, 3> &lhs, const Vector<uint32_t, 3> &rhs)
{
    Vector<uint32_t, 3> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_sub_epi32(left, right));

    return result;
}

template <>
MATH_INLINE Vector<uint32_t, 3> operator*(const Vector<uint32_t, 3> &lhs, const Vector<uint32_t, 3> &rhs)
{
    Vector<uint32_t, 3> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(result.data()), _mm_mullo_epi32(left, right));

    return result;
}

template <>
MATH_INLINE Vector<uint32_t, 3> &operator+=(Vector<uint32_t, 3> &lhs, const Vector<uint32_t, 3> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_add_epi32(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<uint32_t, 3> &operator-=(Vector<uint32_t, 3> &lhs, const Vector<uint32_t, 3> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_sub_epi32(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<uint32_t, 3> &operator*=(Vector<uint32_t, 3> &lhs, const Vector<uint32_t, 3> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i *>(lhs.data()), _mm_mullo_epi32(left, right));

    return lhs;
}

template <>
MATH_INLINE auto dot(const Vector<uint32_t, 2> &lhs, const Vector<uint32_t, 2> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    left = _mm_mullo_epi32(left, right);
    uint32_t *result = reinterpret_cast<uint32_t *>(&left);

    return result[0] + result[1];
}

#endif

#ifdef __AVX__

// -------------------------------------------------------------------------------------
// double
// -------------------------------------------------------------------------------------

template <>
struct VectorStorage<double, 3>
{
    alignas(__m256d) double data[4];
};

template <>
MATH_INLINE Vector<double, 3> operator+(const Vector<double, 3> &lhs, const Vector<double, 3> &rhs)
{
    Vector<double, 3> result;
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(result.data(), _mm256_add_pd(left, right));

    return result;
}

template <>
MATH_INLINE Vector<double, 3> operator-(const Vector<double, 3> &lhs, const Vector<double, 3> &rhs)
{
    Vector<double, 3> result;
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(result.data(), _mm256_sub_pd(left, right));

    return result;
}

template <>
MATH_INLINE Vector<double, 3> operator*(const Vector<double, 3> &lhs, const Vector<double, 3> &rhs)
{
    Vector<double, 3> result;
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(result.data(), _mm256_mul_pd(left, right));

    return result;
}

template <>
MATH_INLINE Vector<double, 3> operator/(const Vector<double, 3> &lhs, const Vector<double, 3> &rhs)
{
    Vector<double, 3> result;
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(result.data(), _mm256_div_pd(left, right));

    return result;
}

template <>
MATH_INLINE Vector<double, 3> &operator+=(Vector<double, 3> &lhs, const Vector<double, 3> &rhs)
{
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(lhs.data(), _mm256_add_pd(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<double, 3> &operator-=(Vector<double, 3> &lhs, const Vector<double, 3> &rhs)
{
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(lhs.data(), _mm256_sub_pd(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<double, 3> &operator*=(Vector<double, 3> &lhs, const Vector<double, 3> &rhs)
{
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(lhs.data(), _mm256_mul_pd(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<double, 3> &operator/=(Vector<double, 3> &lhs, const Vector<double, 3> &rhs)
{
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(lhs.data(), _mm256_div_pd(left, right));

    return lhs;
}

template <>
MATH_INLINE auto dot(const Vector<double, 3> &lhs, const Vector<double, 3> &rhs)
{
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    left = _mm256_mul_pd(left, right);
    double *result = reinterpret_cast<double *>(&left);

    return result[0] + result[1] + result[2];
}

// -------------------------------------------------------------------------------------
// 64-bit signed integer
// -------------------------------------------------------------------------------------

template <>
struct VectorStorage<int64_t, 3>
{
    alignas(__m256i) int64_t data[4];
};

template <>
MATH_INLINE Vector<int64_t, 3> operator+(const Vector<int64_t, 3> &lhs, const Vector<int64_t, 3> &rhs)
{
    Vector<int64_t, 3> result;
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(result.data()), _mm256_add_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<int64_t, 3> operator-(const Vector<int64_t, 3> &lhs, const Vector<int64_t, 3> &rhs)
{
    Vector<int64_t, 3> result;
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(result.data()), _mm256_sub_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<int64_t, 3> operator*(const Vector<int64_t, 3> &lhs, const Vector<int64_t, 3> &rhs)
{
    Vector<int64_t, 3> result;
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(result.data()), _mm256_mullo_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<int64_t, 3> &operator+=(Vector<int64_t, 3> &lhs, const Vector<int64_t, 3> &rhs)
{
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(lhs.data()), _mm256_add_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<int64_t, 3> &operator-=(Vector<int64_t, 3> &lhs, const Vector<int64_t, 3> &rhs)
{
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(lhs.data()), _mm256_sub_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<int64_t, 3> &operator*=(Vector<int64_t, 3> &lhs, const Vector<int64_t, 3> &rhs)
{
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(lhs.data()), _mm256_mullo_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE auto dot(const Vector<int64_t, 3> &lhs, const Vector<int64_t, 3> &rhs)
{
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    left = _mm256_mullo_epi64(left, right);
    int64_t *result = reinterpret_cast<int64_t *>(&left);

    return result[0] + result[1] + result[2];
}

// -------------------------------------------------------------------------------------
// 64-bit unsigned integer
// -------------------------------------------------------------------------------------

template <>
struct VectorStorage<uint64_t, 3>
{
    alignas(__m256i) uint64_t data[4];
};

template <>
MATH_INLINE Vector<uint64_t, 3> operator+(const Vector<uint64_t, 3> &lhs, const Vector<uint64_t, 3> &rhs)
{
    Vector<uint64_t, 3> result;
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(result.data()), _mm256_add_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<uint64_t, 3> operator-(const Vector<uint64_t, 3> &lhs, const Vector<uint64_t, 3> &rhs)
{
    Vector<uint64_t, 3> result;
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(result.data()), _mm256_sub_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<uint64_t, 3> operator*(const Vector<uint64_t, 3> &lhs, const Vector<uint64_t, 3> &rhs)
{
    Vector<uint64_t, 3> result;
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(result.data()), _mm256_mullo_epi64(left, right));

    return result;
}

template <>
MATH_INLINE Vector<uint64_t, 3> &operator+=(Vector<uint64_t, 3> &lhs, const Vector<uint64_t, 3> &rhs)
{
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(lhs.data()), _mm256_add_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<uint64_t, 3> &operator-=(Vector<uint64_t, 3> &lhs, const Vector<uint64_t, 3> &rhs)
{
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(lhs.data()), _mm256_sub_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE Vector<uint64_t, 3> &operator*=(Vector<uint64_t, 3> &lhs, const Vector<uint64_t, 3> &rhs)
{
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    _mm256_store_si256(reinterpret_cast<__m256i *>(lhs.data()), _mm256_mullo_epi64(left, right));

    return lhs;
}

template <>
MATH_INLINE auto dot(const Vector<uint64_t, 3> &lhs, const Vector<uint64_t, 3> &rhs)
{
    __m256i left = *reinterpret_cast<const __m256i *>(lhs.data());
    __m256i right = *reinterpret_cast<const __m256i *>(rhs.data());
    left = _mm256_mullo_epi64(left, right);
    uint64_t *result = reinterpret_cast<uint64_t *>(&left);

    return result[0] + result[1] + result[2];
}

#endif