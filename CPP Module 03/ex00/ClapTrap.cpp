#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default with Param constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : _name(src.getName()), _hitPoints(src.getHitPoints()), _energyPoints(src.getEnergyPoints()), _attackDamage(src.getAttackDamage())
{
	std::cout << "ClapTrap Copy with Param Init constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " attack " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->getName() << " take " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is out of energy!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->getName() << " be repaired " << amount << " points of damage!" << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

int ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &rhs)
{
	o << rhs.getName() << " has " << rhs.getHitPoints() << " hit points, " << rhs.getEnergyPoints() << " energy points and " << rhs.getAttackDamage() << " attack damage";
	return (o);
}
