#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

class Span
{
  private:
    std::vector<int> _elements;
    unsigned int     _N;

  public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(const int num);
    int  shortestSpan() const;
    int  longestSpan() const;

    template <typename T>
    void addNumbers(T begin, T end)
    {
        for (T it = begin; it != end; ++it)
        {
            if (this->_elements.size() >= this->_N)
                throw std::out_of_range("Cannot exceed maximum capacity of span.");
            this->_elements.push_back(*it);
        }
    }
};

#endif