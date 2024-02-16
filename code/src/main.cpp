#include <iostream>
#include "serialize.h"
#include "field_count.h"

// Type A with only a to_string overload.
struct A {
    int a;
    int b;
};

std::string to_string(const A&)
{
    return "I am a A!";
}

// Type B with a serialize method.
struct B
{
    std::string serialize() const
    {
        return "I am a B!";
    }
};

// Type C with a "wrong" serialize member (not a method) and a to_string overload.
struct C
{
    std::string serialize;
};

std::string to_string(const C&)
{
    return "I am a C!";
};

int main()
{
    A a{1};
    B b;
    C c;
    std::cout << serialize(a) << std::endl;
    std::cout << serialize(b) << std::endl;
    std::cout << serialize(c) << std::endl;
    std::cout << field_num<A> << std::endl;
    return 0;
}