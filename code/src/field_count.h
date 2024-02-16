
#include <type_traits>
#include <cstddef>

struct to_any
{
    template <typename T>
    operator T();
};

template <typename T, typename = void, typename...TS>
struct field_count
{
    constexpr static size_t num = sizeof...(TS)-1;
};

template <typename T, typename... TS>
struct field_count<T, std::void_t<decltype( T{TS{}...} )>, TS...>
{
    constexpr static size_t num = field_count<T, void, TS..., to_any>::num;
};

template <typename T>
constexpr size_t field_num = field_count<T>::num;