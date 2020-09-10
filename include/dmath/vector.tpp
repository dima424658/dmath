#pragma once

#include <cmath>
#include <array>
#include <initializer_list>
#include <algorithm>

#include "detail.tpp"

template <typename T, std::size_t I>
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
    constexpr Vector(T);
    constexpr Vector(const Vector<T, I> &);
    constexpr Vector(Vector<T, I> &&);

    template <typename U>
    constexpr Vector(const Vector<U, I> &);

    constexpr Vector(const std::array<T, I> &);
    constexpr Vector(std::array<T, I> &&);

    template <typename U>
    constexpr Vector(const std::array<U, I> &);

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
    constexpr Vector<T, I> &operator=(const Vector<T, I> &);

    template <typename U>
    constexpr Vector<T, I> &operator=(const Vector<U, I> &);

    template <typename U>
    constexpr Vector<T, I> &operator+=(U);

    template <typename U>
    constexpr Vector<T, I> &operator+=(const Vector<U, I> &);

    template <typename U>
    constexpr Vector<T, I> &operator-=(U);

    template <typename U>
    constexpr Vector<T, I> &operator-=(const Vector<U, I> &);

    template <typename U>
    constexpr Vector<T, I> &operator*=(U);

    template <typename U>
    constexpr Vector<T, I> &operator*=(const Vector<U, I> &);

    template <typename U>
    constexpr Vector<T, I> &operator/=(U);

    template <typename U>
    constexpr Vector<T, I> &operator/=(const Vector<U, I> &);

    template <typename U>
    constexpr Vector<T, I> &operator%=(U);

    template <typename U>
    constexpr Vector<T, I> &operator%=(const Vector<U, I> &);

    template <typename U>
    constexpr Vector<T, I> &operator&=(U);

    template <typename U>
    constexpr Vector<T, I> &operator&=(const Vector<U, I> &);

    template <typename U>
    constexpr Vector<T, I> &operator|=(U);

    template <typename U>
    constexpr Vector<T, I> &operator|=(const Vector<U, I> &);

    template <typename U>
    constexpr Vector<T, I> &operator^=(U);

    template <typename U>
    constexpr Vector<T, I> &operator^=(const Vector<U, I> &);

    template <typename U>
    constexpr Vector<T, I> &operator<<=(U);

    template <typename U>
    constexpr Vector<T, I> &operator<<=(const Vector<U, I> &);

    template <typename U>
    constexpr Vector<T, I> &operator>>=(U);

    template <typename U>
    constexpr Vector<T, I> &operator>>=(const Vector<U, I> &);

    // Increment and decrement
    constexpr Vector<T, I> &operator++();
    constexpr Vector<T, I> operator++(int);

    constexpr Vector<T, I> &operator--();
    constexpr Vector<T, I> operator--(int);

private:
    std::array<T, I> m_data;
};

// -------------------------------------------------------------------------------------
// Constructors begin
// -------------------------------------------------------------------------------------

template <typename T, std::size_t I>
constexpr Vector<T, I>::Vector(T arg)
{
    m_data.fill(arg);
}

template <typename T, std::size_t I>
constexpr Vector<T, I>::Vector(const Vector<T, I> &vec) : m_data(vec.m_data) {}

template <typename T, std::size_t I>
constexpr Vector<T, I>::Vector(Vector<T, I> &&vec) : m_data(std::move(vec.m_data)) {}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I>::Vector(const Vector<U, I> &arg)
{
    std::copy(arg.begin(), arg.end(), m_data.begin());
}

template <typename T, std::size_t I>
constexpr Vector<T, I>::Vector(const std::array<T, I> &arg) : m_data(arg) {}

template <typename T, std::size_t I>
constexpr Vector<T, I>::Vector(std::array<T, I> &&arg) : m_data(arg) {}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I>::Vector(const std::array<U, I> &arg)
{
    std::copy(arg.begin(), arg.end(), m_data.begin());
}

template <typename T, std::size_t I>
constexpr Vector<T, I>::Vector(std::initializer_list<T> list)
{
      //if(I != list.size()) // TODO
      //     static_assert(0, "asd");

    std::copy(list.begin(), list.end(), m_data.begin());
}

template <typename T, std::size_t I>
template <typename... Args>
constexpr Vector<T, I>::Vector(Args... args) : m_data({static_cast<T>(args)...}) {}

// -------------------------------------------------------------------------------------
// Constructors end
// -------------------------------------------------------------------------------------

template <typename T, std::size_t I>
constexpr size_t Vector<T, I>::size() const noexcept
{
    return I;
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::pointer Vector<T, I>::data() noexcept
{
    return m_data.data();
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::const_pointer Vector<T, I>::data() const noexcept
{
    return m_data.data();
}

// -------------------------------------------------------------------------------------
// Iterators begin
// -------------------------------------------------------------------------------------

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::iterator Vector<T, I>::begin() noexcept
{
    return iterator(data());
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::const_iterator Vector<T, I>::begin() const noexcept
{
    return const_iterator(data());
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::iterator Vector<T, I>::end() noexcept
{
    return iterator(data() + I);
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::const_iterator Vector<T, I>::end() const noexcept
{
    return const_iterator(data() + I);
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::reverse_iterator Vector<T, I>::rbegin() noexcept
{
    return reverse_iterator(end());
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::const_reverse_iterator Vector<T, I>::rbegin() const noexcept
{
    return const_reverse_iterator(end());
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::reverse_iterator Vector<T, I>::rend() noexcept
{
    return reverse_iterator(begin());
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::const_reverse_iterator Vector<T, I>::rend() const noexcept
{
    return const_reverse_iterator(begin());
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::const_iterator Vector<T, I>::cbegin() const noexcept
{
    return const_iterator(data());
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::const_iterator Vector<T, I>::cend() const noexcept
{
    return const_iterator(data() + I);
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::const_reverse_iterator Vector<T, I>::crbegin() const noexcept
{
    return const_reverse_iterator(end());
}

template <typename T, std::size_t I>
constexpr typename Vector<T, I>::const_reverse_iterator Vector<T, I>::crend() const noexcept
{
    return const_reverse_iterator(begin());
}

// -------------------------------------------------------------------------------------
// Iterators end
// -------------------------------------------------------------------------------------

template <typename T, std::size_t I>
constexpr T &Vector<T, I>::operator[](size_t index)
{
    return m_data.at(index);
}

template <typename T, std::size_t I>
constexpr const T &Vector<T, I>::operator[](size_t index) const
{
    return m_data.at(index);
}

// -------------------------------------------------------------------------------------
// Assignment operators begin
// -------------------------------------------------------------------------------------

template <typename T, std::size_t I>
constexpr Vector<T, I> &Vector<T, I>::operator=(const Vector<T, I> &arg)
{
    this->m_data = arg.m_data;
    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator=(const Vector<U, I> &arg)
{
    this->m_data = arg.m_data;
    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator+=(U arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] += static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator+=(const Vector<U, I> &arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] += static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator-=(U arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] -= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator-=(const Vector<U, I> &arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] -= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator*=(U arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] *= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator*=(const Vector<U, I> &arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] *= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator/=(U arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] /= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator/=(const Vector<U, I> &arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] /= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator%=(U arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] %= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator%=(const Vector<U, I> &arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] %= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator&=(U arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] &= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator&=(const Vector<U, I> &arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] &= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator|=(U arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] |= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator|=(const Vector<U, I> &arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] |= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator^=(U arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] ^= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator^=(const Vector<U, I> &arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] ^= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator<<=(U arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] <<= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator<<=(const Vector<U, I> &arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] <<= static_cast<T>(arg[i]);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator>>=(U arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] >>= static_cast<T>(arg);
    });

    return *this;
}

template <typename T, std::size_t I>
template <typename U>
constexpr Vector<T, I> &Vector<T, I>::operator>>=(const Vector<U, I> &arg)
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i] >>= static_cast<T>(arg[i]);
    });

    return *this;
}

// -------------------------------------------------------------------------------------
// Assignment operators end
// -------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------
// Increment and decrement begin
// -------------------------------------------------------------------------------------

template <typename T, std::size_t I>
constexpr Vector<T, I> &Vector<T, I>::operator++()
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i]++;
    });

    return *this;
}

template <typename T, std::size_t I>
constexpr Vector<T, I> Vector<T, I>::operator++(int)
{
    auto result(*this);
    operator++();
    return result;
}

template <typename T, std::size_t I>
constexpr Vector<T, I> &Vector<T, I>::operator--()
{
    detail::static_for<0, I>([&](auto i) {
        this->m_data[i]--;
    });

    return *this;
}

template <typename T, std::size_t I>
constexpr Vector<T, I> Vector<T, I>::operator--(int)
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

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator+(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l + r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator+(const Vector<T, I> &left, const U &right)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l + r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator-(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l - r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator-(const Vector<T, I> &left, const U &right)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l - r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator*(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l * r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator*(const Vector<T, I> &left, const U &right)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l * r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator/(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l / r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator/(const Vector<T, I> &left, const U &right)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l / r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator%(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l % r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator%(const Vector<T, I> &left, const U &right)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l % r; }, left, right);
}

// -------------------------------------------------------------------------------------
// Arithmetic operators end
// -------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------
// Bitwise operators begin
// -------------------------------------------------------------------------------------

template <typename T, std::size_t I>
constexpr Vector<T, I> operator~(const Vector<T, I> &vec)
{
    return detail::__proccess_array([](const auto &el) { return ~el; }, vec);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator&(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l & r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator&(const Vector<T, I> &left, const U &right)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l & r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator|(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l | r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator|(const Vector<T, I> &left, const U &right)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l | r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator^(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l ^ r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator^(const Vector<T, I> &left, const U &right)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l ^ r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator<<(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l << r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator<<(const Vector<T, I> &left, const U &right)
{
    return detail::__proccess_array_scalar([](const auto &l, const auto &r) { return l << r; }, left, right);
}

template <typename T, typename U, std::size_t I>
constexpr Vector<T, I> operator>>(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::__proccess_two_arrays([](const auto &l, const auto &r) { return l >> r; }, left, right);
}

// -------------------------------------------------------------------------------------
// Bitwise operators end
// -------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------
// Comparison operators begin
// -------------------------------------------------------------------------------------

template <typename T, typename U, std::size_t I>
constexpr bool operator==(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::static_for_if<0, I>([&](auto i) -> bool {
        return left[i] == static_cast<T>(right[i]);
    });
}

template <typename T, typename U, std::size_t I>
constexpr bool operator!=(const Vector<T, I> &left, const Vector<U, I> &right)
{
    return detail::static_for_if<0, I>([&](auto i) -> bool {
        return left[i] != static_cast<T>(right[i]);
    });
}

// -------------------------------------------------------------------------------------
// Comparison operators end
// -------------------------------------------------------------------------------------

/*
template <typename T, std::size_t I>
constexpr T Vector<T, I>::length() const
{
    T result = 0;

    for (auto el : m_data)
        result += el * el;

    return std::sqrt(result);
}

template <typename T, std::size_t I>
constexpr T Vector<T, I>::normal() const
{

}

template <typename T, std::size_t I>
constexpr T Vector<T, I>::length() const
{
    T result = 0;

    for (auto el : m_data)
        result += el * el;

    return std::sqrt(result);
}
*/