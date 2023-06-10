#ifndef AMateria_HPP
# define AMateria_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(const AMateria& src);
	virtual ~AMateria(void);
	AMateria &operator=(const AMateria &rhs);
public:
	void setType(std::string const &type);
public:
	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif