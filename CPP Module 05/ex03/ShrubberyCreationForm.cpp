#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const& rhs) {
  AForm::operator=(rhs);
  if (this != &rhs) {
    this->setTarget(rhs.getTarget());
  }
  return (*this);
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
  return "file open failed, request grade is";
}

void ShrubberyCreationForm::openFile(std::ofstream& ofs) const {
  ofs.open((this->_target + "_shrubbery").c_str());
  if (ofs.fail()) throw ShrubberyCreationForm::FileOpenException();
}

void ShrubberyCreationForm::closeFile(std::ofstream& ofs) const {
  ofs.close();
  if (ofs.is_open()) throw std::runtime_error("Error: could not close file");
}

void ShrubberyCreationForm::setTarget(std::string target) {
  this->_target = target;
}

std::string ShrubberyCreationForm::getTarget(void) const {
  return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  try {
    if (!this->getSigned()) throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
      throw AForm::GradeTooLowException();
    std::cout << executor.getName() << " executed " << this->getName()
              << std::endl;
    std::ofstream ofs;
    this->openFile(ofs);
    this->drawTree(ofs);
    this->closeFile(ofs);
  } catch (std::exception& e) {
    std::cout << e.what() << " " << this->getGradeToExecute() << std::endl;
  }
}

void ShrubberyCreationForm::drawTree(std::ofstream& ofs) const {
  ofs << "                     _______________[___1___]_________________"
      << std::endl
      << "                    /                                         \\"
      << std::endl
      << "          ______[___2___]______                     "
         "______[___3___]______"
      << std::endl
      << "         /                     \\                   /                "
         "       \\"
      << std::endl
      << "    [___4___]             [___5___]           [___6___]              "
         " [___7___]"
      << std::endl
      << "   /         \\           /         \\         /         \\          "
         "   /         \\"
      << std::endl
      << "[___8___] [___9___] [___10__] [___11__] [___12__] [___13__]     "
         "[___14__] [___15__]"
      << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& rhs) {
  os << rhs.getName() << " is ";
  if (!rhs.getSigned()) os << "not ";
  os << "signed and requires grade " << rhs.getGradeToSign()
     << " to sign and grade " << rhs.getGradeToExecute() << " to execute."
     << "(target: " << rhs.getTarget() << ")" << std::endl;
  return (os);
}