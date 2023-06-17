#include "Bureaucrat.hpp"

#ifdef LEAKS
void leaks(void) { system("leaks Bureaucrat"); }
#endif

int main() {
#ifdef LEAKS
  atexit(leaks);
#endif
  // Bureaucrat oA150("oA", 151);
  // Bureaucrat oB1("oB", 1);
  try {
    Bureaucrat b150("b150", 150);
    std::cout << b150;
    b150.incrementGrade();
    std::cout << b150;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << " --- " << std::endl;
  try {
    Bureaucrat a1("a1", 1);
    std::cout << a1;
    a1.incrementGrade();
    std::cout << a1;
    a1.decrementGrade();
    std::cout << a1;
    a1.incrementGrade();
    std::cout << a1;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return (0);
}