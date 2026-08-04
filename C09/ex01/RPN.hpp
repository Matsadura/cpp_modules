#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN
{
  private:
    std::stack<int> _stack;
    bool            isOperator(char c) const;
    void            applyOperator(char op);

    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

  public:
    RPN();
    ~RPN();
    int  getTop() const;
    void evaluate(const std::string &expression);
};

#endif