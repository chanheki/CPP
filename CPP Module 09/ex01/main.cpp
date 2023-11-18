#include "RPN.hpp"

int main(int ac, char** av) {
  RPN rpn;

  try {
    if (ac != 2) {
      throw std::runtime_error("Error: Invalid number of arguments.");
    }
    rpn.calculation(av[1]);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}