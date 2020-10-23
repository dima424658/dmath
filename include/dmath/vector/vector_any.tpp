#pragma once

#include <cmath>
#include <initializer_list>
#include <algorithm>

#include "detail.tpp"

template <typename T, std::size_t N>
struct VectorStorage
{
    T data[N];
};

template <typename T, std::size_t N>
struct Vector
{
    // Types
    using value_type = T;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using reference = value_type &;
    using const_reference = const value_type &;
    using iterator = value_type *;
    using const_iterator = const value_type *;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    /*
    constexpr Vector(const T* arg)
    {
        std::copy(arg, arg + I, m_data.begin());
    }
*/
    // Constructors
    constexpr Vector() = default;
    constexpr Vector(const T &);
    constexpr Vector(const Vector<T, N> &) = default;
    constexpr Vector(Vector<T, N> &&) = default;

    constexpr Vector(T* data);

    template <typename U>
    constexpr Vector(const Vector<U, N> &);

    constexpr Vector(std::initializer_list<T>);

    template <typename... Args>
    constexpr Vector(Args...);

    constexpr size_t size() const noexcept;

    constexpr pointer data() noexcept;
    constexpr const_pointer data() const noexcept;

    // Iterators
    constexpr iterator begin() noexcept;
    constexpr const_iterator begin() const noexcept;
    constexpr iterator end() noexcept;
    constexpr const_iterator end() const noexcept;
    constexpr reverse_iterator rbegin() noexcept;
    constexpr const_reverse_iterator rbegin() const noexcept;
    constexpr reverse_iterator rend() noexcept;
    constexpr const_reverse_iterator rend() const noexcept;
    constexpr const_iterator cbegin() const noexcept;
    constexpr const_iterator cend() const noexcept;
    constexpr const_reverse_iterator crbegin() const noexcept;
    constexpr const_reverse_iterator crend() const noexcept;

    // Array subscript operators
    constexpr T &operator[](size_t);
    constexpr const T &operator[](size_t) const;

    // Assignment operators
    constexpr Vector<T, N> &operator=(const Vector<T, N> &) = default;

    template <typename U>
    constexpr Vector<T, N> &operator=(const Vector<U, N> &);

    template <typename U>
    constexpr Vector<T, N> &operator+=(const U &);

    template <typename U>
    constexpr Vector<T, N> &operator-=(const U &);

    template <typename U>
    constexpr Vector<T, N> &operator*=(const U &);

    template <typename U>
    constexpr Vector<T, N> &operator/=(const U &);

    template <typename U>
    constexpr Vector<T, N> &operator%=(const U &);

    template <typename U>
    constexpr Vector<T, N> &operator%=(const Vector<U, N> &);

    template <typename U>
    constexpr Vector<T, N> &operator&=(const U &);

    template <typename U>
    constexpr Vector<T, N> &operator&=(const Vector<U, N> &);

    template <typename U>
    constexpr Vector<T, N> &operator|=(const U &);

    template <typename U>
    constexpr Vector<T, N> &operator|=(const Vector<U, N> &);

    template <typename U>
    constexpr Vector<T, N> &operator^=(const U &);

    template <typename U>
    constexpr Vector<T, N> &operator^=(const Vector<U, N> &);

    template <typename U>
    constexpr Vector<T, N> &operator<<=(const U &);

    template <typename U>
    constexpr Vector<T, N> &operator<<=(const Vector<U, N> &);

    template <typename U>
    constexpr Vector<T, N> &operator>>=(const U &);

    template <typename U>
    constexpr Vector<T, N> &operator>>=(const Vector<U, N> &);

    // Increment and decrement
    constexpr Vector<T, N> &operator++();
    constexpr Vector<T, N> operator++(int);

    constexpr Vector<T, N> &operator--();
    constexpr Vector<T, N> operator--(int);

private:
    VectorStorage<T, N> m_data;
};

// -------------------------------------------------------------------------------------
// Constructors begin
// -------------------------------------------------------------------------------------

template <typename T, std::size_t N>
constexpr Vector<T, N>::Vector(const T &arg)
{
    std::fill_n(begin(), size(), arg);
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N>::Vector(const Vector<U, N> &arg)
{
    std::copy(arg.cbegin(), arg.cend(), begin());
}

template <typename T, std::size_t N>
constexpr Vector<T, N>::Vector(T* arg)
{
    std::copy(arg, arg + N, begin());
}

template <typename T, std::size_t N>
constexpr Vector<T, N>::Vector(std::initializer_list<T> list)
{
    //if(N != list.size()) // TODO
    //     static_assert(0, "asd");

    std::copy(list.begin(), list.end(), begin());
}

template <typename T, std::size_t N>
template <typename... Args>
constexpr Vector<T, N>::Vector(Args... args) : m_data{static_cast<typename std::enable_if<N == sizeof...(Args), T>::type>(args)...}
{
    static_assert(N == sizeof...(Args), "Argument size doesn't match with constructor");
}

// -------------------------------------------------------------------------------------
// Constructors end
// -------------------------------------------------------------------------------------

template <typename T, std::size_t N>
constexpr size_t Vector<T, N>::size() const noexcept
{
    return N;
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::pointer Vector<T, N>::data() noexcept
{
    return m_data.data;
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::const_pointer Vector<T, N>::data() const noexcept
{
    return m_data.data;
}

// -------------------------------------------------------------------------------------
// Iterators begin
// -------------------------------------------------------------------------------------

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::iterator Vector<T, N>::begin() noexcept
{
    return iterator(data());
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::const_iterator Vector<T, N>::begin() const noexcept
{
    return const_iterator(data());
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::iterator Vector<T, N>::end() noexcept
{
    return iterator(data() + N);
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::const_iterator Vector<T, N>::end() const noexcept
{
    return const_iterator(data() + N);
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::reverse_iterator Vector<T, N>::rbegin() noexcept
{
    return reverse_iterator(end());
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::const_reverse_iterator Vector<T, N>::rbegin() const noexcept
{
    return const_reverse_iterator(end());
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::reverse_iterator Vector<T, N>::rend() noexcept
{
    return reverse_iterator(begin());
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::const_reverse_iterator Vector<T, N>::rend() const noexcept
{
    return const_reverse_iterator(begin());
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::const_iterator Vector<T, N>::cbegin() const noexcept
{
    return const_iterator(data());
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::const_iterator Vector<T, N>::cend() const noexcept
{
    return const_iterator(data() + N);
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::const_reverse_iterator Vector<T, N>::crbegin() const noexcept
{
    return const_reverse_iterator(end());
}

template <typename T, std::size_t N>
constexpr typename Vector<T, N>::const_reverse_iterator Vector<T, N>::crend() const noexcept
{
    return const_reverse_iterator(begin());
}

// -------------------------------------------------------------------------------------
// Iterators end
// -------------------------------------------------------------------------------------

template <typename T, std::size_t N>
constexpr T &Vector<T, N>::operator[](size_t index)
{
    return m_data.data[index];
}

template <typename T, std::size_t N>
constexpr const T &Vector<T, N>::operator[](size_t index) const
{
    return m_data.data[index];
}

// -------------------------------------------------------------------------------------
// Assignment operators begin
// -------------------------------------------------------------------------------------

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator=(const Vector<U, N> &arg)
{
    std::copy(arg.cbegin(), arg.cend(), begin());

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator+=(const U &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] += static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator-=(const U &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] -= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator*=(const U &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] *= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator/=(const U &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] /= static_cast<T>(arg);
    });

    return *this;
}


template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> &operator+=(Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    detail::static_for<0, N>([&](auto i) {
        lhs[i] += static_cast<T>(rhs[i]);
    });

    return lhs;
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> &operator-=(Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    detail::static_for<0, N>([&](auto i) {
        lhs[i] -= static_cast<T>(rhs[i]);
    });

    return lhs;
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> &operator*=(Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    detail::static_for<0, N>([&](auto i) {
        lhs[i] *= static_cast<T>(rhs[i]);
    });

    return lhs;
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> &operator/=(Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    detail::static_for<0, N>([&](auto i) {
        lhs[i] /= static_cast<T>(rhs[i]);
    });

    return lhs;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator%=(const U &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] %= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator%=(const Vector<U, N> &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] %= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator&=(const U &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] &= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator&=(const Vector<U, N> &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] &= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator|=(const U &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] |= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator|=(const Vector<U, N> &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] |= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator^=(const U &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] ^= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator^=(const Vector<U, N> &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] ^= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator<<=(const U &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] <<= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator<<=(const Vector<U, N> &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] <<= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator>>=(const U &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] >>= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t N>
template <typename U>
constexpr Vector<T, N> &Vector<T, N>::operator>>=(const Vector<U, N> &arg)
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i] >>= static_cast<T>(arg[i]);
    });

    return *this;
}

// -------------------------------------------------------------------------------------
// Assignment operators end
// -------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------
// Increment and decrement begin
// -------------------------------------------------------------------------------------

template <typename T, std::size_t N>
constexpr Vector<T, N> &Vector<T, N>::operator++()
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i]++;
    });

    return *this;
}

template <typename T, std::size_t N>
constexpr Vector<T, N> Vector<T, N>::operator++(int)
{
    auto result(*this);
    operator++();
    return result;
}

template <typename T, std::size_t N>
constexpr Vector<T, N> &Vector<T, N>::operator--()
{
    detail::static_for<0, N>([&](auto i) {
        this->m_data.data[i]--;
    });

    return *this;
}

template <typename T, std::size_t N>
constexpr Vector<T, N> Vector<T, N>::operator--(int)
{
    auto result(*this);
    operator--();
    return result;
}

// -------------------------------------------------------------------------------------
// Increment and decrement end
// -------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------
// Arithmetic operators begin
// -------------------------------------------------------------------------------------

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator+(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l + r; }, lhs, rhs);
}


template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator+(const Vector<T, N> &lhs, const U &rhs)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l + r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator-(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l - r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator-(const Vector<T, N> &lhs, const U &rhs)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l - r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator*(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l * r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator*(const Vector<T, N> &lhs, const U &rhs)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l * r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator/(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l / r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator/(const Vector<T, N> &lhs, const U &rhs)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l / r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator%(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l % r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator%(const Vector<T, N> &lhs, const U &rhs)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l % r; }, lhs, rhs);
}

// -------------------------------------------------------------------------------------
// Arithmetic operators end
// -------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------
// Bitwise operators begin
// -------------------------------------------------------------------------------------

template <typename T, std::size_t N>
constexpr Vector<T, N> operator~(const Vector<T, N> &vec)
{
    return detail::__proccess_array([](const auto &el) { return ~el; }, vec);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator&(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l & r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator&(const Vector<T, N> &lhs, const U &rhs)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l & r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator|(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l | r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator|(const Vector<T, N> &lhs, const U &rhs)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l | r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator^(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l ^ r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator^(const Vector<T, N> &lhs, const U &rhs)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l ^ r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator<<(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l << r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator<<(const Vector<T, N> &lhs, const U &rhs)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l << r; }, lhs, rhs);
}

template <typename T, typename U, std::size_t N>
constexpr Vector<T, N> operator>>(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l >> r; }, lhs, rhs);
}

// -------------------------------------------------------------------------------------
// Bitwise operators end
// -------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------
// Comparison operators begin
// -------------------------------------------------------------------------------------

template <typename T, typename U, std::size_t N>
constexpr bool operator==(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    if(&lhs == &rhs)
        return true;

    return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T, typename U, std::size_t N>
constexpr bool operator!=(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return !std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T, typename U, std::size_t N>
constexpr auto dot(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    using return_t = decltype(lhs[0] * rhs[0]);

    return_t result = 0;

    detail::static_for<0, N>([&](auto i) {
        result += lhs[i] * static_cast<T>(rhs[i]);
    });

    return result;
}

template <typename T, typename U, std::size_t N, typename = std::enable_if_t<N == 3>>
constexpr auto cross(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    using return_t = decltype(lhs[0] * rhs[0]);

    return Vector<return_t, N>(
        lhs[1] * rhs[2] - lhs[2] * rhs[1],
        lhs[0] * rhs[2] - lhs[2] * rhs[0],
        lhs[0] * rhs[1] - lhs[1] * rhs[0]);
}

template <typename T, std::size_t N>
constexpr T length(const Vector<T, N> &vec)
{
    T result = 0;

    for (auto el : vec)
        result += el * el;

    return std::sqrt(result);
}

template <typename T, typename U, std::size_t N>
constexpr U length(const Vector<T, N> &vec)
{
    U result = 0;

    for (auto el : vec)
        result += std::pow(static_cast<U>(el), 2);

    return std::sqrt(result);
}

template <typename T, typename U, std::size_t N, typename = std::enable_if_t<(N > 0)>>
auto angle(const Vector<T, N> &lhs, const Vector<U, N> &rhs)
{
    return std::acos(dot(lhs, rhs) / (length(lhs) * length<T>(rhs)));
}
// -------------------------------------------------------------------------------------
// Comparison operators end
// -------------------------------------------------------------------------------------

/*
template <typename T, std::size_t N>
constexpr T Vector<T, N>::length() const
{
    T result = 0;

    for (auto el : m_data)
        result += el * el;

    return std::sqrt(result);
}

template <typename T, std::size_t N>
constexpr T Vector<T, N>::normal() const
{

}

template <typename T, std::size_t N>
constexpr T Vector<T, N>::length() const
{
    T result = 0;

    for (auto el : m_data)
        result += el * el;

    return std::sqrt(result);
}
*/