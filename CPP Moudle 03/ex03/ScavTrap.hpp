#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	void guardGate(void);
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &src);
	ScavTrap &operator=(const ScavTrap &rhs);
public:
	void attack(std::string const &target);
};

#endif
