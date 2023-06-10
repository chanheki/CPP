#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "\033[1;31m";
	std::cout << "[ Brain ]";
	std::cout << "\033[0m ";
	std::cout << " default constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "\033[1;31m";
	std::cout << "[ Brain ]";
	std::cout << "\033[0m ";
	std::cout << " copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "\033[1;31m";
	std::cout << "[ Brain ]";
	std::cout << "\033[0m ";
	std::cout << " destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
		{
			_ideas[i] = rhs._ideas[i];
		}
	}
	return (*this);
}
