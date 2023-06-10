#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "\033[1;35m";
	std::cout << "[ DiamondTrap ]";
	std::cout << "\033[0m "; 
	std::cout << "Default constructor called" << std::endl;
	this->setName(ClapTrap::_name);
	ClapTrap::_name = this->getName() + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "\033[1;35m";
	std::cout << "[ DiamondTrap ]";
	std::cout << "\033[0m "; 
	std::cout << "Default with Param constructor called" << std::endl;
	this->setName(name);
	ClapTrap::_name = this->getName() + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[1;35m";
	std::cout << "[ DiamondTrap ]";
	std::cout << "\033[0m "; 
	std::cout << "Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "\033[1;35m";
	std::cout << "[ DiamondTrap ]";
	std::cout << "\033[0m "; 
	std::cout << "Copy with Param constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "\033[1;35m";
	std::cout << "[ DiamondTrap ]";
	std::cout << "\033[0m "; 
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs.getName();
		_hitPoints = rhs.getHitPoints();
		_energyPoints = rhs.getEnergyPoints();
		_attackDamage = rhs.getAttackDamage();
	}
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "\033[1;35m";
	std::cout << "[ DiamondTrap ]";
	std::cout << "\033[0m "; 
	std::cout << "My name is " << this->getName() << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}