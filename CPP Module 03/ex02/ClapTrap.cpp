#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\033[1;34m";
	std::cout << "[ ClapTrap ]";
	std::cout << "\033[0m "; 
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "\033[1;34m";
	std::cout << "[ ClapTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\033[1;34m";
	std::cout << "[ ClapTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Default with Param constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : _name(src.getName()), _hitPoints(src.getHitPoints()), _energyPoints(src.getEnergyPoints()), _attackDamage(src.getAttackDamage())
{
	std::cout << "\033[1;34m";
	std::cout << "[ ClapTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Copy with Param Init constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "\033[1;34m";
	std::cout << "[ ClapTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Assignation operator called" << std::endl;
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
		std::cout << "\033[1;34m";
		std::cout << "[ ClapTrap ]";
		std::cout << "\033[0m ";
		std::cout << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "\033[1;34m";
	std::cout << "[ ClapTrap ]";
	std::cout << "\033[0m ";
	std::cout << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << "\033[1;34m";
	std::cout << "[ ClapTrap ]";
	std::cout << "\033[0m ";
	std::cout << this->_name << " take " << amount << " damage " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "\033[1;34m";
		std::cout << "[ ClapTrap ]";
		std::cout << "\033[0m ";
		std::cout << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << "\033[1;34m";
	std::cout << "[ ClapTrap ]";
	std::cout << "\033[0m ";
	std::cout << this->_name << " be repaired " << amount << " points of damage!" << std::endl;
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

std::ostream &operator<<(std::ostream &out, ClapTrap const &rhs)
{
	out << "\033[1;34m"
	<< "[ ClapTrap ]"
	<< "\033[0m "
	<< rhs.getName() << " has " << rhs.getHitPoints() << " hit points, " << rhs.getEnergyPoints() << " energy points and " << rhs.getAttackDamage() << " attack damage";
	return (out);
}
