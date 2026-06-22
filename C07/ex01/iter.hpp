#include <iostream>

template <typename T, typename F>
void iter(T *addr, std::size_t length, F func)
{
    for (std::size_t i = 0; i < length; i++)
        func(addr[i]);
}

template <typename T, typename F>
void iter(const T *addr, std::size_t length, F func)
{
    for (std::size_t i = 0; i < length; i++)
        func(addr[i]);
}