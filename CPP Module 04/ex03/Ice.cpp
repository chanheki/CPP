#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice& src) : AMateria(src) {}

Ice::~Ice(void) {}

Ice& Ice::operator=(Ice const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

AMateria* Ice::clone() const
{
	Ice *tmp = new Ice(*this);
	return (tmp);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}