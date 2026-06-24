#include "span.hpp"

Span::Span() : _N(0)
{
}

Span::Span(unsigned int max_elements) : _N(max_elements)
{
}

Span::Span(const Span &other) : _elements(other._elements), _N(other._N)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _elements = other._elements;
        _N        = other._N;
    }
    return *this;
}

void Span::addNumber(int num)
{
    if (this->_elements.size() >= this->_N)
        throw std::out_of_range("Cannot exceed maximum capacity of span.");
    this->_elements.push_back(num);
}

int Span::shortestSpan() const
{
    if (this->_elements.size() < 2)
        throw std::runtime_error("Span calculation requires at least 2 elements.");

    std::vector<int> sorted_elements = this->_elements;
    std::sort(sorted_elements.begin(), sorted_elements.end());

    int min_span = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted_elements.size(); ++i)
    {
        int span = sorted_elements[i] - sorted_elements[i - 1];
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}

int Span::longestSpan() const
{
    if (this->_elements.size() < 2)
        throw std::runtime_error("Span calculation requires at least 2 elements.");
    int max = *std::max_element(this->_elements.begin(), this->_elements.end());
    int min = *std::min_element(this->_elements.begin(), this->_elements.end());
    return (max - min);
}

Span::~Span()
{
}