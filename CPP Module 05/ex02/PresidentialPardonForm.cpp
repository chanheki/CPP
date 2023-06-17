#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& src)
    : AForm("PresidentialPardonForm", 25, 5), _target(src.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    PresidentialPardonForm const& rhs) {
  if (this != &rhs) {
    this->setTarget(rhs.getTarget());
  }
  return (*this);
}

void PresidentialPardonForm::setTarget(std::string target) {
  this->_target = target;
}

std::string PresidentialPardonForm::getTarget(void) const {
  return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (!this->getSigned()) throw AForm::NotSignedException();
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::GradeTooLowException();
  std::cout << executor.getName() << " executed " << this->getName()
            << std::endl;
  std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox."
            << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& rhs) {
  os << rhs.getName() << " is ";
  if (!rhs.getSigned()) os << "not ";
  os << "signed and requires grade " << rhs.getGradeToSign()
     << " to sign and grade " << rhs.getGradeToExecute() << " to execute."
     << "(target: " << rhs.getTarget() << ")" << std::endl;
  return (os);
}