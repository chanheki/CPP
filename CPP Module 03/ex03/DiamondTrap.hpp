#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(void);
	~DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &src);
	DiamondTrap &operator=(const DiamondTrap &rhs);
public:
	void whoAmI(void);
};

#endif