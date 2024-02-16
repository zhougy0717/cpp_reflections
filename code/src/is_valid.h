#include "container.h"

template <typename UnnamedType> constexpr auto is_valid(const UnnamedType& t) 
{
    // We used auto for the return type: it will be deduced here.
    return container<UnnamedType>();
}