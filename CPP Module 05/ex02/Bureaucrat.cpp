#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name) {
  setGrade(src._grade);
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
  if (this != &rhs) this->setGrade(rhs._grade);
  return (*this);
}

std::string const& Bureaucrat::getName(void) const { return (this->_name); }

int Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::setGrade(int grade) {
  this->checkGrade(grade);
  this->_grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
  return "Grade must not higher than 1";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
  return "Grade must not lower than 150";
}

void Bureaucrat::checkGrade(int grade) const {
  if (grade > 150) throw Bureaucrat::GradeTooLowException();
  if (grade < 1) throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::incrementGrade(void) {
  checkGrade(this->_grade - 1);
  this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
  checkGrade(this->_grade + 1);
  this->_grade++;
}

void Bureaucrat::signForm(AForm& form) {
  try {
    form.beSigned(*this);
    std::cout << this->getName() << " signs " << form.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << this->getName() << " couldn’t sign " << form.getName()
              << " because " << e.what() << " " << form.getGradeToSign()
              << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const& form) {
  try {
    form.execute(*this);
  } catch (std::exception& e) {
    std::cout << this->getName() << " couldn’t executes " << form.getName()
              << " because " << e.what() << " " << form.getGradeToExecute()
              << std::endl;
  }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << std::endl;
  return (os);
}
