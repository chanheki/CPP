#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "\033[1;33m";
	std::cout << "[ Cat ]";
	std::cout << "\033[0m ";
	std::cout << "Default constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "\033[1;33m";
	std::cout << "[ Cat ]";
	std::cout << "\033[0m ";
	std::cout << "Default with Param constructor called" << std::endl;
	_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "\033[1;33m";
	std::cout << "[ Cat ]";
	std::cout << "\033[0m ";
	std::cout << "Destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "\033[1;33m";
	std::cout << "[ Cat ]";
	std::cout << "\033[0m ";
	std::cout << "Copy with Param constructor called" << std::endl;
	_brain = new Brain();
	*this = src;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "\033[1;33m";
	std::cout << "[ Cat ]";
	std::cout << "\033[0m ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs.getType(); 
		*_brain = *rhs._brain;
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Cat &rhs)
{
	o << rhs.getType();
	return (o);
}
