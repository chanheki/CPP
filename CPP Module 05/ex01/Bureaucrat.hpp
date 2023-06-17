#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat {
 private:
  std::string const _name;
  int _grade;
  Bureaucrat(void);
  void setGrade(int grade);
  void checkGrade(int grade) const;

  class GradeTooHighException : public std::exception {
    virtual const char* what(void) const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char* what(void) const throw();
  };

 public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat& src);
  Bureaucrat& operator=(Bureaucrat const& rhs);
  virtual ~Bureaucrat(void);

 public:
  std::string const& getName(void) const;
  int getGrade(void) const;
  void incrementGrade(void);
  void decrementGrade(void);
  void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif