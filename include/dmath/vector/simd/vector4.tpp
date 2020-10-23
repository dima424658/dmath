#pragma once

#ifdef __SSE2__

#include "../vector_any.tpp"
#include <x86intrin.h>

template <>
struct VectorStorage<float, 4>
{
    alignas(__m128) float data[4];
};

template <>
Vector<float, 4> operator+(const Vector<float, 4> &lhs, const Vector<float, 4> &rhs)
{
    Vector<float, 4> result;
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(result.data(), _mm_add_ps(left, right));

    return result;
}

template <>
Vector<float, 4> operator-(const Vector<float, 4> &lhs, const Vector<float, 4> &rhs)
{
    Vector<float, 4> result;
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(result.data(), _mm_sub_ps(left, right));

    return result;
}

template <>
Vector<float, 4> operator*(const Vector<float, 4> &lhs, const Vector<float, 4> &rhs)
{
    Vector<float, 4> result;
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(result.data(), _mm_mul_ps(left, right));

    return result;
}

template <>
Vector<float, 4> operator/(const Vector<float, 4> &lhs, const Vector<float, 4> &rhs)
{
    Vector<float, 4> result;
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(result.data(), _mm_div_ps(left, right));

    return result;
}

template <>
Vector<float, 4>& operator+=(Vector<float, 4> &lhs, const Vector<float, 4> &rhs)
{
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(lhs.data(), _mm_add_ps(left, right));

    return lhs;
}

template <>
Vector<float, 4>& operator-=(Vector<float, 4> &lhs, const Vector<float, 4> &rhs)
{
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(lhs.data(), _mm_sub_ps(left, right));

    return lhs;
}

template <>
Vector<float, 4>& operator*=(Vector<float, 4> &lhs, const Vector<float, 4> &rhs)
{
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(lhs.data(), _mm_mul_ps(left, right));

    return lhs;
}

template <>
Vector<float, 4>& operator/=(Vector<float, 4> &lhs, const Vector<float, 4> &rhs)
{
    __m128 left = *reinterpret_cast<const __m128 *>(lhs.data());
    __m128 right = *reinterpret_cast<const __m128 *>(rhs.data());
    _mm_store_ps(lhs.data(), _mm_div_ps(left, right));

    return lhs;
}

template <>
struct VectorStorage<int, 4>
{
    alignas(__m128i) int data[4];
};

template <>
Vector<int, 4> operator+(const Vector<int, 4> &lhs, const Vector<int, 4> &rhs)
{
    Vector<int, 4> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i*>(result.data()), _mm_add_epi32(left, right));

    return result;
}

template <>
Vector<int, 4> operator-(const Vector<int, 4> &lhs, const Vector<int, 4> &rhs)
{
    Vector<int, 4> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i*>(result.data()), _mm_sub_epi32(left, right));

    return result;
}

template <>
Vector<int, 4> operator*(const Vector<int, 4> &lhs, const Vector<int, 4> &rhs)
{
    Vector<int, 4> result;
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i*>(result.data()), _mm_mullo_epi32(left, right));

    return result;
}

template <>
Vector<int, 4>& operator+=(Vector<int, 4> &lhs, const Vector<int, 4> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i*>(lhs.data()), _mm_add_epi32(left, right));

    return lhs;
}

template <>
Vector<int, 4>& operator-=(Vector<int, 4> &lhs, const Vector<int, 4> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i*>(lhs.data()), _mm_sub_epi32(left, right));

    return lhs;
}

template <>
Vector<int, 4>& operator*=(Vector<int, 4> &lhs, const Vector<int, 4> &rhs)
{
    __m128i left = *reinterpret_cast<const __m128i *>(lhs.data());
    __m128i right = *reinterpret_cast<const __m128i *>(rhs.data());
    _mm_store_si128(reinterpret_cast<__m128i*>(lhs.data()), _mm_mullo_epi32(left, right));

    return lhs;
}

#endif

#ifdef __AVX__

template <>
struct VectorStorage<double, 4>
{
    alignas(__m256d) double data[4];
};

template <>
Vector<double, 4> operator+(const Vector<double, 4> &lhs, const Vector<double, 4> &rhs)
{
    Vector<double, 4> result;
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(result.data(), _mm256_add_pd(left, right));

    return result;
}

template <>
Vector<double, 4> operator-(const Vector<double, 4> &lhs, const Vector<double, 4> &rhs)
{
    Vector<double, 4> result;
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(result.data(), _mm256_sub_pd(left, right));

    return result;
}

template <>
Vector<double, 4> operator*(const Vector<double, 4> &lhs, const Vector<double, 4> &rhs)
{
    Vector<double, 4> result;
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(result.data(), _mm256_mul_pd(left, right));

    return result;
}

template <>
Vector<double, 4> operator/(const Vector<double, 4> &lhs, const Vector<double, 4> &rhs)
{
    Vector<double, 4> result;
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(result.data(), _mm256_div_pd(left, right));

    return result;
}

template <>
Vector<double, 4>& operator+=(Vector<double, 4> &lhs, const Vector<double, 4> &rhs)
{
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(lhs.data(), _mm256_add_pd(left, right));

    return lhs;
}

template <>
Vector<double, 4>& operator-=(Vector<double, 4> &lhs, const Vector<double, 4> &rhs)
{
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(lhs.data(), _mm256_sub_pd(left, right));

    return lhs;
}

template <>
Vector<double, 4>& operator*=(Vector<double, 4> &lhs, const Vector<double, 4> &rhs)
{
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(lhs.data(), _mm256_mul_pd(left, right));

    return lhs;
}

template <>
Vector<double, 4>& operator/=(Vector<double, 4> &lhs, const Vector<double, 4> &rhs)
{
    __m256d left = *reinterpret_cast<const __m256d *>(lhs.data());
    __m256d right = *reinterpret_cast<const __m256d *>(rhs.data());
    _mm256_store_pd(lhs.data(), _mm256_div_pd(left, right));

    return lhs;
}

#endif