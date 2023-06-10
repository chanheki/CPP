#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "\033[1;34m";
	std::cout << "[ Dog ]";
	std::cout << "\033[0m ";
	std::cout << "Default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "\033[1;34m";
	std::cout << "[ Dog ]";
	std::cout << "\033[0m ";
	std::cout << "Default with Param constructor called" << std::endl;
	_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "\033[1;34m";
	std::cout << "[ Dog ]";
	std::cout << "\033[0m ";
	std::cout << "Destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "\033[1;34m";
	std::cout << "[ Dog ]";
	std::cout << "\033[0m ";
	std::cout << "Copy with Param constructor called" << std::endl;
	_brain = new Brain();
	*this = src;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "\033[1;34m";
	std::cout << "[ Dog ]";
	std::cout << "\033[0m ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs.getType();
		*_brain = *rhs._brain;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Bow Wow" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Dog &rhs)
{
	o << rhs.getType();
	return (o);
}
