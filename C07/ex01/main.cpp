#include "iter.hpp"
#include <string>

template <typename T>
void print(const T& x)
{
    std::cout << x << '\n';
}

template <typename T>
void addOne(T& x)
{
    ++x;
}

void printInt(int x)
{
    std::cout << x << '\n';
}

int main()
{
    int a[] = {1, 2, 3};
    const int b[] = {4, 5, 6};

    iter(a, 3, printInt);
    iter(a, 3, print<int>);
    iter(a, 3, addOne<int>);
    iter(a, 3, print<int>);

    iter(b, 3, print<int>);

    // iter(b, 3, addOne<int>); // should not compile
}