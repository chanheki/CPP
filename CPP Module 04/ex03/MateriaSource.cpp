#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
		{
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			this->_materia[i] = rhs._materia[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = materia;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (NULL);
}

