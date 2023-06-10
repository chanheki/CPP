#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "\033[1;32m";
	std::cout << "[ Animal ]";
	std::cout << "\033[0m ";
	std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "\033[1;32m";
	std::cout << "[ Animal ]";
	std::cout << "\033[0m ";
	std::cout << "Default with Param constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "\033[1;32m";
	std::cout << "[ Animal ]";
	std::cout << "\033[0m ";
	std::cout << "Destructor called" << std::endl;
}

Animal::Animal(const Animal &src) : _type(src.getType())
{
	std::cout << "\033[1;32m";
	std::cout << "[ Animal ]";
	std::cout << "\033[0m ";
	std::cout << "Copy with Param constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "\033[1;32m";
	std::cout << "[ Animal ]";
	std::cout << "\033[0m ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs.getType();
	}
	return (*this);
}

void Animal::setType(std::string type)
{
	_type = type;
}

std::string Animal::getType(void) const
{
	return (_type);
}

void Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Animal &rhs)
{
	o << rhs.getType();
	return (o);
}


