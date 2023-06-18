#include "Bureaucrat.hpp"
#include "Form.hpp"

#ifdef LEAKS
void leaks(void) { system("leaks Bureaucrat"); }
#endif

int main() {
#ifdef LEAKS
  atexit(leaks);
#endif
  try {
    Form f1 = Form("f1", 150, 150);
    std::cout << f1;
    Form f2("f2", 75, 75);
    std::cout << f2;
    Form f3("f3", 1, 1);
    std::cout << f3;
    std::cout << std::endl;

    Bureaucrat b150("b150", 150);
    std::cout << b150;
    b150.signForm(f1);
    std::cout << f1;
    b150.signForm(f2);
    std::cout << f2;
    b150.signForm(f3);
    std::cout << f3;
    std::cout << std::endl;

    Bureaucrat b1("b1", 1);
    std::cout << b1;
    b1.signForm(f1);
    std::cout << f1;
    b1.signForm(f2);
    std::cout << f2;
    b1.signForm(f3);
    std::cout << f3;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}