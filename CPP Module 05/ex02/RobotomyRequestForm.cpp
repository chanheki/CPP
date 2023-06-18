#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    RobotomyRequestForm const& rhs) {
  AForm::operator=(rhs);
  if (this != &rhs) {
    this->setTarget(rhs.getTarget());
  }
  return (*this);
}

void RobotomyRequestForm::setTarget(std::string target) {
  this->_target = target;
}

std::string RobotomyRequestForm::getTarget(void) const {
  return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (!this->getSigned()) throw AForm::NotSignedException();
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::GradeTooLowException();
  std::cout << executor.getName() << " executed " << this->getName()
            << std::endl;
  std::cout << "* drilling noises *" << std::endl;
  std::srand((unsigned long)time(NULL));
  if (std::rand() % 2 == 1)
    std::cout << this->getTarget() << " has been robotomized "
              << "\033[1;34m"
              << "successfully"
              << "\033[0m " << std::endl;
  else
    std::cout << this->getTarget() << " has been "
              << "\033[1;33m"
              << "failed to robotomized "
              << "\033[0m " << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& rhs) {
  os << rhs.getName() << " is ";
  if (!rhs.getSigned()) os << "not ";
  os << "signed and requires grade " << rhs.getGradeToSign()
     << " to sign and grade " << rhs.getGradeToExecute() << " to execute."
     << "(target: " << rhs.getTarget() << ")" << std::endl;
  return (os);
}