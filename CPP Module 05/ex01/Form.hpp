#ifndef Form_HPP
#define Form_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
  std::string const _name;
  bool _signed;
  const int _gradeToSign;
  const int _gradeToExecute;

  Form(void);
  void checkGrade(int grade) const;
  class GradeTooHighException : public std::exception {
    virtual const char* what(void) const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char* what(void) const throw();
  };

 public:
  Form(std::string name, int gradeToSign, int gradeToExecute);
  Form(const Form& src);
  virtual ~Form(void);
  Form& operator=(Form const& rhs);

 public:
  std::string const& getName(void) const;
  bool getSigned(void) const;
  int getGradeToSign(void) const;
  int getGradeToExecute(void) const;
  void beSigned(Bureaucrat const& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif