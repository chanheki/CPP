#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string	_type;
public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal &src);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal();
public:
	std::string getType(void) const;
	void setType(std::string type);
	virtual void makeSound(void) const;
};

std::ostream &operator<<(std::ostream &out, const Animal &src);

#endif