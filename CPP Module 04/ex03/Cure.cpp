#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& src) : AMateria(src) {}

Cure::~Cure(void) {}

Cure& Cure::operator=(Cure const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

AMateria* Cure::clone() const
{
	Cure *tmp = new Cure(*this);
	return (tmp);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

