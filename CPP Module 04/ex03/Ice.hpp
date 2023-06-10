#ifndef Ice_HPP
# define Ice_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice& src);
	virtual ~Ice(void);
	Ice& operator=(Ice const& rhs);
public:
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif