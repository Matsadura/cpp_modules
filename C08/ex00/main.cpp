#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <typename T>
void testContainer(T &container, int value)
{
    try
    {
        typename T::iterator it = easyfind(container, value);
        std::cout << "Found " << value << " at: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Value " << value << " not found" << std::endl;
    }
}

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    std::deque<int> d;
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);

    testContainer(v, 20);
    testContainer(v, 40);

    testContainer(l, 2);
    testContainer(l, 5);

    testContainer(d, 300);
    testContainer(d, 999);

    return 0;
}