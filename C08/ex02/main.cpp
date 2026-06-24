#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main()
{
    std::list<int>   ref;
    MutantStack<int> mstack;

    ref.push_back(5);
    mstack.push(5);
    ref.push_back(17);
    mstack.push(17);

    std::cout << ref.back() << std::endl;
    std::cout << mstack.top() << std::endl;

    ref.pop_back();
    mstack.pop();

    std::cout << ref.size() << std::endl;
    std::cout << mstack.size() << std::endl;

    ref.push_back(3);
    mstack.push(3);
    ref.push_back(5);
    mstack.push(5);
    ref.push_back(737);
    mstack.push(737);
    ref.push_back(0);
    mstack.push(0);

    std::list<int>::iterator   lit = ref.begin();
    MutantStack<int>::iterator mit = mstack.begin();

    while (lit != ref.end() && mit != mstack.end())
    {
        std::cout << *lit << " | " << *mit << std::endl;
        ++lit;
        ++mit;
    }

    return 0;
}