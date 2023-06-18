#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <fstream>
#include <iostream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string _target;

  ShrubberyCreationForm(void);

  void drawTree(std::ofstream& ofs) const;
  void openFile(std::ofstream& ofs) const;
  void closeFile(std::ofstream& ofs) const;
  void setTarget(std::string target);

 public:
  class FileOpenException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  ShrubberyCreationForm(const ShrubberyCreationForm& src);
  virtual ~ShrubberyCreationForm(void);
  ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

  ShrubberyCreationForm(std::string target);

  std::string getTarget(void) const;
  void execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& os,
                         const ShrubberyCreationForm& ShrubberyCreationForm);

#endif