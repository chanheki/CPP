#ifndef Intern_HPP
#define Intern_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 private:
  static AForm* createPresidentialPardonForm(std::string target);
  static AForm* createRobotomyRequestForm(std::string target);
  static AForm* createShrubberyCreationForm(std::string target);

 public:
  Intern(void);
  Intern(const Intern& src);
  ~Intern(void);
  Intern& operator=(Intern const& rhs);
  AForm* makeForm(std::string formName, std::string target);
  class FormNotExistException : public std::exception {
    virtual const char* what(void) const throw();
  };
};

#endif