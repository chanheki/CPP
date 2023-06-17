#include "Intern.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(const Intern& src) { (void)src; }
Intern& Intern::operator=(const Intern& src) {
  (void)src;
  return *this;
}

AForm* Intern::makeForm(const std::string form_to_create,
                        const std::string target_for_form) {
  AForm* ret = NULL;
  std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm",
                         "ShrubberyCreationForm"};
  AForm* (*creaters[])(const std::string target) = {
      &createPresidentialPardonForm, &createRobotomyRequestForm,
      &createShrubberyCreationForm};
  for (int i = 0; i < 3; i++) {
    if (form_to_create == forms[i]) {
      std::cout << ("Intern creates " + form_to_create) << std::endl;
      return (creaters[i](target_for_form));
    }
  }
  try {
    if (!ret) throw Intern::FormNotExistException();
  } catch (std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return ret;
}

const char* Intern::FormNotExistException::what(void) const throw() {
  return ("Intern can't create form because it doesn't exist");
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
  return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
  return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
  return (new ShrubberyCreationForm(target));
}
