#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

bool RPN::isOperator(char c) const
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::applyOperator(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error: Not enough operands for the operator.");

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    switch (op)
    {
        case '+':
            _stack.push(a + b);
            break;
        case '-':
            _stack.push(a - b);
            break;
        case '*':
            _stack.push(a * b);
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: Division by zero.");
            _stack.push(a / b);
            break;
        default:
            throw std::runtime_error("Error: Unknown operator.");
    }
}

void RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string        token;

    while (iss >> token)
    {
        if (token.length() == 1 && isOperator(token[0]))
        {
            applyOperator(token[0]);
        }
        else
        {
            try
            {
                int value = std::strtol(token.c_str(), NULL, 10);
                _stack.push(value);
            }
            catch (const std::invalid_argument &)
            {
                throw std::runtime_error("Error: Invalid token in expression.");
            }
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error: Invalid RPN expression.");
}

int RPN::getTop() const
{
    if (_stack.empty())
        throw std::runtime_error("Error: Stack is empty.");
    return _stack.top();
}