#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 private:
  std::string const _name;
  bool _signed;
  int _gradeToSign;
  int _gradeToExecute;

  AForm(void);
  void checkGrade(int grade) const;

  void setGradeToSign(int gradeToSign);
  void setGradeToExecute(int gradeToExecute);

 public:
  AForm(std::string name, int gradeToSign, int gradeToExecute);
  AForm(const AForm& src);
  virtual ~AForm(void);
  AForm& operator=(AForm const& rhs);

 public:
  std::string const& getName(void) const;
  bool getSigned(void) const;
  int getGradeToSign(void) const;
  int getGradeToExecute(void) const;
  void beSigned(Bureaucrat const& bureaucrat);

  virtual void execute(Bureaucrat const& executor) const = 0;

 public:
  class GradeTooHighException : public std::exception {
    virtual const char* what(void) const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char* what(void) const throw();
  };
  class NotSignedException : public std::exception {
    virtual const char* what(void) const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif