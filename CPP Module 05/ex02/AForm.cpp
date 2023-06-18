#include "AForm.hpp"

AForm::AForm(void)
    : _name("default"),
      _signed(false),
      _gradeToSign(150),
      _gradeToExecute(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  this->checkGrade(gradeToSign);
  this->checkGrade(gradeToExecute);
}

AForm::~AForm(void) {}

void AForm::checkGrade(int grade) const {
  if (grade < 1)
    throw AForm::GradeTooHighException();
  else if (grade > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src)
    : _name(src._name),
      _signed(src._signed),
      _gradeToSign(src._gradeToSign),
      _gradeToExecute(src._gradeToExecute) {}

AForm& AForm::operator=(AForm const& rhs) {
  if (this != &rhs) {
    this->_signed = rhs.getSigned();
  }
  return (*this);
}

const char* AForm::GradeTooHighException::what(void) const throw() {
  return "Grade must not higher than";
}

const char* AForm::GradeTooLowException::what(void) const throw() {
  return "Grade must not lower than";
}

const char* AForm::NotSignedException::what() const throw() {
  return "Form is not signed yet";
}

std::string const& AForm::getName(void) const { return (this->_name); }

bool AForm::getSigned(void) const { return (this->_signed); }

int AForm::getGradeToSign(void) const { return (this->_gradeToSign); }

int AForm::getGradeToExecute(void) const { return (this->_gradeToExecute); }

void AForm::beSigned(Bureaucrat const& bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign)
    throw AForm::GradeTooLowException();
  this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
  os << AForm.getName() << ", AForm grade to sign " << AForm.getGradeToSign()
     << ", AForm grade to execute " << AForm.getGradeToExecute()
     << ", AForm signed " << AForm.getSigned() << std::endl;
  return (os);
}
