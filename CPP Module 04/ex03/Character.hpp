#ifndef Character_HPP
# define Character_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];
public:
	Character(void);
	Character(std::string const &name);
	Character(const Character& src);
	virtual ~Character(void);
	Character& operator=(Character const& rhs);
public:
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif
 