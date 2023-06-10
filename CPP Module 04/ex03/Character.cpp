#include "Character.hpp"
#include "Floor.hpp"

Character::Character(void) : _name("default")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& src)
{
	*this = src;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

Character& Character::operator=(Character const& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = materia;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->_inventory[idx])
		{
			Floor::dropFloor(this->_inventory[idx]);
			this->_inventory[idx] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
