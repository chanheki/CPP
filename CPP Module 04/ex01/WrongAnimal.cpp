#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "\033[1;32m";
	std::cout << "[ WrongAnimal ]";
	std::cout << "\033[0m ";
	std::cout << "Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "\033[1;32m";
	std::cout << "[ WrongAnimal ]";
	std::cout << "\033[0m ";
	std::cout << "Default with Param constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[1;32m";
	std::cout << "[ WrongAnimal ]";
	std::cout << "\033[0m ";
	std::cout << "Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src.getType())
{
	std::cout << "\033[1;32m";
	std::cout << "[ WrongAnimal ]";
	std::cout << "\033[0m ";
	std::cout << "Copy with Param constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "\033[1;32m";
	std::cout << "[ WrongAnimal ]";
	std::cout << "\033[0m ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs.getType();
	}
	return (*this);
}

std::string WrongAnimal::getType(void) const
{
	return (_type);
}

void WrongAnimal::setType(std::string type)
{
	_type = type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const WrongAnimal &rhs)
{
	o << rhs.getType();
	return (o);
}
