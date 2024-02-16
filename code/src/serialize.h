#include <type_traits>
#include <string>
#include "is_valid.h"

// Check if a type has a serialize method.
auto hasSerialize = is_valid([](auto&& x) -> decltype(x.serialize()) { });

// Notice how I simply swapped the return type on the right?
template <class T> auto serialize(T& obj) 
-> typename std::enable_if<decltype(hasSerialize(obj))::value, std::string>::type
{
    return obj.serialize();
}

template <class T> auto serialize(T& obj) 
-> typename std::enable_if<!decltype(hasSerialize(obj))::value, std::string>::type
{
    return to_string(obj);
}