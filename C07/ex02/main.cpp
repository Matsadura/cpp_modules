#include "Array.h"
#include <iostream>

int main()
{
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = static_cast<int>(i) * 2;

    std::cout << "a: ";
    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << a[i] << ' ';
    std::cout << '\n';

    Array<int> b(a); // copy ctor
    b[0] = 42;
    std::cout << "after b[0]=42 -> a[0]=" << a[0] << " b[0]=" << b[0] << '\n';

    Array<int> c;
    c    = a; // copy assignment
    c[1] = 99;
    std::cout << "after c=a; c[1]=99 -> a[1]=" << a[1] << " c[1]=" << c[1] << '\n';

    const Array<int> d = a;
    std::cout << "const d: ";
    for (unsigned int i = 0; i < d.size(); ++i)
        std::cout << d[i] << ' ';
    std::cout << '\n';

    try
    {
        std::cout << "attempting out-of-range access...\n";
        a[5] = 10; // should throw
    }
    catch (const std::exception &e)
    {
        std::cout << "caught exception: " << e.what() << '\n';
    }

    return 0;
}