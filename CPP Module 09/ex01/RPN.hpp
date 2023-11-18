#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

int stringToInt(const std::string &str);
std::string intToString(int number);

class RPN {
 private:
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);

  std::stack<std::string> _stack;

 public:
  RPN();
  ~RPN();

  bool isOperator(const std::string &str);
  bool isNumber(const std::string &str);
  void calculation(const std::string &str);

  std::string operandOperation(const std::string &str, int a, int b);
  void printResult();
};

#endif
