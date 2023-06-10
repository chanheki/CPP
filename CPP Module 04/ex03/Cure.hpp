#ifndef Cure_HPP
# define Cure_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure& src);
	virtual ~Cure(void);
	Cure& operator=(Cure const& rhs);
public:
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif