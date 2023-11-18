#include "RPN.hpp"

RPN::RPN(){};
RPN::RPN(const RPN &other) { *this = other; };
RPN::~RPN(){};
RPN &RPN::operator=(const RPN &other) {
  (void)other;
  return *this;
};

bool RPN::isOperator(const std::string &str) {
  return (str == "+" || str == "-" || str == "*" || str == "/");
}

bool RPN::isNumber(const std::string &str) {
  return (str >= "0" && str <= "9");
}

std::string RPN::operandOperation(const std::string &str, int a, int b) {
  if (str == "+") {
    return intToString(a + b);
  } else if (str == "-") {
    return intToString(a - b);
  } else if (str == "*") {
    return intToString(a * b);
  } else if (str == "/") {
    if (b == 0) throw std::runtime_error("Error: Division by zero");
    return intToString(a / b);
  } else
    throw std::runtime_error("Error: Invalid operator");
}

void RPN::calculation(const std::string &str) {
  std::string token;
  size_t index = 0;

  while (index < str.size()) {
    token = str[index++];
    if (token == " ") continue;
    if (isNumber(token))
      _stack.push(token.c_str());
    else if (isOperator(token)) {
      if (_stack.size() < 2)
        throw std::runtime_error("Error: Insufficient operands");
      int operand2 = stringToInt(_stack.top());
      _stack.pop();
      int operand1 = stringToInt(_stack.top());
      _stack.pop();

      std::string result = operandOperation(token, operand1, operand2);
      _stack.push(result);
    } else
      throw std::runtime_error("Error: Invalid token");
  }
  if (_stack.size() != 1) throw std::runtime_error("Error: Invalid expression");
  printResult();
}

void RPN::printResult() { std::cout << _stack.top() << std::endl; }

int stringToInt(const std::string &str) {
  int result = 0;
  int sign = 1;
  size_t i = 0;

  if (str[0] == '+' || str[0] == '-') {
    if (str[0] == '-') sign = -1;
    i++;
  }
  for (; i < str.length(); ++i) {
    if (str[i] >= '0' && str[i] <= '9') {
      result = result * 10 + (str[i] - '0');
    } else
      throw std::runtime_error("Error: Invalid token");
  }
  return result * sign;
}

std::string intToString(int number) {
  std::ostringstream oss;
  oss << number;
  return oss.str();
}