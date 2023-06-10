#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "\033[1;35m";
	std::cout << "[ WrongCat ]";
	std::cout << "\033[0m ";
	std::cout << "Default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "\033[1;35m";
	std::cout << "[ WrongCat ]";
	std::cout << "\033[0m ";
	std::cout << "Default with Param constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "\033[1;35m";
	std::cout << "[ WrongCat ]";
	std::cout << "\033[0m ";
	std::cout << "Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src.getType())
{
	std::cout << "\033[1;35m";
	std::cout << "[ WrongCat ]";
	std::cout << "\033[0m ";
	std::cout << "Copy with Param constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "\033[1;35m";
	std::cout << "[ WrongCat ]";
	std::cout << "\033[0m ";
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		setType(rhs.getType());
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat sound" << std::endl;
}
