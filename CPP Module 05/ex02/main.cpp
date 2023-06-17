#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#ifdef LEAKS
void leaks(void) { system("leaks Bureaucrat"); }
#endif

int main() {
#ifdef LEAKS
  atexit(leaks);
#endif
  try {
    ShrubberyCreationForm f1("f1");
    std::cout << f1;
    ShrubberyCreationForm i1("i1");
    std::cout << i1;
    RobotomyRequestForm f2("f2");
    std::cout << f2;
    PresidentialPardonForm f3("f3");
    std::cout << f3;
    std::cout << std::endl;

    std::cout << ">> 145 grade SIGN, excute FORMS" << std::endl;
    Bureaucrat b145("b145", 145);
    std::cout << b145;
    b145.signForm(f1);
    b145.executeForm(f1);
    std::cout << f1 << std::endl;
    b145.signForm(f2);
    b145.executeForm(f2);
    std::cout << f2 << std::endl;
    b145.signForm(f3);
    b145.executeForm(f3);
    std::cout << f3 << std::endl;

    std::cout << ">> 45 grade SIGN" << std::endl;
    Bureaucrat b45("b45", 45);
    b45.signForm(i1);
    std::cout << i1 << std::endl;
    b45.signForm(f2);
    std::cout << f2 << std::endl;
    b45.signForm(f3);
    std::cout << f3 << std::endl;

    std::cout << "--- EXECUTE Shrubbery FORMS --- " << std::endl;
    b145.executeForm(f1);
    b45.executeForm(f1);
    b45.executeForm(i1);
    std::cout << std::endl;

    std::cout << "--- EXECUTE Robotomy FORMS --- " << std::endl;
    for (int i = 0; i < 4; i++) b45.executeForm(f2);
    std::cout << std::endl;

    std::cout << "--- EXECUTE Presidential Pardon FORMS --- " << std::endl;
    Bureaucrat b4("b4", 4);
    Bureaucrat b6("b6", 6);
    b4.executeForm(f3);
    b4.signForm(f3);
    std::cout << f3;
    b6.executeForm(f3);
    b4.executeForm(f3);
    std::cout << std::endl;

  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}