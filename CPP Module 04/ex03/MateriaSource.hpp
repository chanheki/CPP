#ifndef MateriaSource_HPP
# define MateriaSource_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private: 
	AMateria *_materia[4];
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& src);
	virtual ~MateriaSource(void);
	MateriaSource& operator=(MateriaSource const& rhs);
public:
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif