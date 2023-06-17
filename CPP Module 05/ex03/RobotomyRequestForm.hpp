#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  std::string _target;
  void setTarget(std::string target);
  RobotomyRequestForm(void);

 public:
  RobotomyRequestForm(const RobotomyRequestForm& src);
  virtual ~RobotomyRequestForm(void);
  RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

  RobotomyRequestForm(std::string target);

  std::string getTarget(void) const;
  void execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& os,
                         const RobotomyRequestForm& RobotomyRequestForm);

#endif