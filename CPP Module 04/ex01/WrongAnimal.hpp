#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& src);
	virtual ~WrongAnimal(void);
	WrongAnimal &operator=(WrongAnimal const &rhs);
public:
	std::string getType(void) const;
	void setType(std::string type);
	void makeSound(void) const;
};

#endif