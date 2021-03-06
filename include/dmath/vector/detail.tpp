#pragma once

#include <type_traits>
#include <utility>

template <typename T, std::size_t N>
struct Vector;

namespace detail
{
    template <typename Fn, typename T, typename U, std::size_t N, std::size_t... ints>
    constexpr auto __proccess_array_scalar(const Fn &func, const Vector<T, N> &left, const U &right, std::integer_sequence<std::size_t, ints...>)
    {
        using return_t = Vector<decltype(func(left[0], static_cast<const T &>(right))), N>;
        return return_t(func(left[ints], static_cast<const T &>(right))...);
    }

    template <typename Fn, typename T, std::size_t N, std::size_t... ints>
    constexpr auto __proccess_array_scalar(const Fn &func, const Vector<T, N> &left, const T &right, std::integer_sequence<std::size_t, ints...>)
    {
        using return_t = Vector<T, N>;
        return return_t(func(left[ints], static_cast<const T &>(right))...);
    }

    template <typename Fn, typename T, typename U, std::size_t N>
    constexpr auto __proccess_array_scalar(const Fn &func, const Vector<T, N> &left, const U &right)
    {
        return __proccess_array_scalar(func, left, right, std::make_integer_sequence<std::size_t, N>{});
    }

    template <typename Fn, typename T, typename U, std::size_t N, std::size_t... ints>
    constexpr auto __proccess_two_arrays(const Fn &func, const Vector<T, N> &left, const Vector<U, N> &right, std::integer_sequence<std::size_t, ints...>)
    {
        using return_t = Vector<decltype(func(left[0], static_cast<const T &>(right[0]))), N>;
        return return_t(func(left[ints], static_cast<const T &>(right[ints]))...);
    }

    template <typename Fn, typename T, std::size_t N, std::size_t... ints>
    constexpr auto __proccess_two_arrays(const Fn &func, const Vector<T, N> &left, const Vector<T, N> &right, std::integer_sequence<std::size_t, ints...>)
    {
        using return_t = Vector<T, N>;
        return return_t(func(left[ints], right[ints])...);
    }

    template <typename Fn, typename T, typename U, std::size_t N>
    constexpr auto __proccess_two_arrays(const Fn &func, const Vector<T, N> &left, const Vector<U, N> &right)
    {
        return __proccess_two_arrays(func, left, right, std::make_integer_sequence<std::size_t, N>{});
    }

    template <typename Fn, typename T, std::size_t N, std::size_t... ints>
    constexpr auto __proccess_array(const Fn &func, const Vector<T, N> &obj, std::integer_sequence<std::size_t, ints...>)
    {
        return Vector<decltype(func(obj[0])), N>(func(obj[ints])...);
    }

    template <typename Fn, typename T, std::size_t N>
    constexpr auto __proccess_array(const Fn &func, const Vector<T, N> &obj)
    {
        return __proccess_array(func, obj, std::make_integer_sequence<std::size_t, N>{});
    }
} // namespace detail