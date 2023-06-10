#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria& src) : _type(src.getType()) {}

AMateria::~AMateria(void) {}

AMateria& AMateria::operator=(AMateria const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

void AMateria::setType(std::string const &type) { this->_type = type; }

std::string const& AMateria::getType(void) const { return this->_type; }

void AMateria::use(ICharacter &target)
{
	std::cout << "* uses " << this->_type << " on " << target.getName() << " *" << std::endl;
}
