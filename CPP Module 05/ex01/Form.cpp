#include "Form.hpp"

Form::Form(void)
    : _name("default"),
      _signed(false),
      _gradeToSign(150),
      _gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  this->checkGrade(gradeToSign);
  this->checkGrade(gradeToExecute);
}

Form::~Form(void) {}

void Form::checkGrade(int grade) const {
  if (grade < 1)
    throw Form::GradeTooHighException();
  else if (grade > 150)
    throw Form::GradeTooLowException();
}

Form::Form(const Form& src)
    : _name(src._name),
      _signed(src._signed),
      _gradeToSign(src._gradeToSign),
      _gradeToExecute(src._gradeToExecute) {}

Form& Form::operator=(Form const& rhs) {
  if (this != &rhs) {
    this->_signed = rhs.getSigned();
  }
  return (*this);
}

const char* Form::GradeTooHighException::what(void) const throw() {
  return "Grade too high";
}

const char* Form::GradeTooLowException::what(void) const throw() {
  return "Grade too low";
}

std::string const& Form::getName(void) const { return (this->_name); }

bool Form::getSigned(void) const { return (this->_signed); }

int Form::getGradeToSign(void) const { return (this->_gradeToSign); }

int Form::getGradeToExecute(void) const { return (this->_gradeToExecute); }

void Form::beSigned(Bureaucrat const& bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign)
    throw Form::GradeTooLowException();
  this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  os << form.getName() << ", form grade to sign " << form.getGradeToSign()
     << ", form grade to execute " << form.getGradeToExecute()
     << ", form signed " << form.getSigned() << std::endl;
  return (os);
}
