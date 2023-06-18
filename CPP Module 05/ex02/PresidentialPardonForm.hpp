#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string _target;
  PresidentialPardonForm(void);
  void setTarget(std::string target);

 public:
  PresidentialPardonForm(const PresidentialPardonForm& src);
  virtual ~PresidentialPardonForm(void);
  PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

  PresidentialPardonForm(std::string target);

  std::string getTarget(void) const;
  void execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& os,
                         const PresidentialPardonForm& PresidentialPardonForm);

#endif