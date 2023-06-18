#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
    Intern someRandomIntern;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    Intern intern;
    AForm *shrubberyCreationForm =
        intern.makeForm("ShrubberyCreationForm", "target1");
    AForm *robotomyRequestForm =
        intern.makeForm("RobotomyRequestForm", "target2");
    AForm *presidentialPardonForm =
        intern.makeForm("PresidentialPardonForm", "target3");

    std::cout << *shrubberyCreationForm << std::endl;
    std::cout << *robotomyRequestForm << std::endl;
    std::cout << *presidentialPardonForm << std::endl;

    Bureaucrat b150("b150", 150);
    b150.decrementGrade();
    shrubberyCreationForm->beSigned(b150);
    std::cout << b150 << std::endl;
    Bureaucrat b1("b1", 1);
    b1.incrementGrade();
    std::cout << b1 << std::endl;

    std::cout << "---" << std::endl;

    shrubberyCreationForm->beSigned(Bureaucrat("b150", 150));
    shrubberyCreationForm->execute(Bureaucrat("b3", 1));
    shrubberyCreationForm->beSigned(Bureaucrat("b3", 1));
    shrubberyCreationForm->execute(Bureaucrat("b3", 1));
    shrubberyCreationForm->execute(Bureaucrat("b150", 150));
    std::cout << std::endl;
    robotomyRequestForm->beSigned(Bureaucrat("b150", 150));
    robotomyRequestForm->execute(Bureaucrat("b2", 1));
    robotomyRequestForm->beSigned(Bureaucrat("b2", 1));
    robotomyRequestForm->execute(Bureaucrat("b2", 1));
    robotomyRequestForm->execute(Bureaucrat("b150", 150));
    std::cout << std::endl;
    presidentialPardonForm->beSigned(Bureaucrat("b150", 150));
    presidentialPardonForm->execute(Bureaucrat("b10", 10));
    presidentialPardonForm->beSigned(Bureaucrat("b1", 1));
    presidentialPardonForm->execute(Bureaucrat("b1", 1));
    presidentialPardonForm->execute(Bureaucrat("b150", 150));
    std::cout << std::endl;
    delete presidentialPardonForm;
    delete robotomyRequestForm;
    delete shrubberyCreationForm;

    AForm *form = intern.makeForm("NotExistingForm", "target4");
    if (form) {
      std::cout << *form << std::endl;
      delete form;
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}