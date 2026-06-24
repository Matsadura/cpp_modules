#include "span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::vector<int> numbers;
    for (int i = 0; i < 10000; ++i)
    {
        numbers.push_back(i);
    }
    Span sp2(10000);
    sp2.addNumbers(numbers.begin(), numbers.end());
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    return 0;
}