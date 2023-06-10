#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "\033[1;33m";
	std::cout << "[ ScavTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Default constructor called" << std::endl;
	this->setName("Scav Default");
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[1;33m";
	std::cout << "[ ScavTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Default with Param constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[1;33m";
	std::cout << "[ ScavTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "\033[1;33m";
	std::cout << "[ ScavTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Copy with Param constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "\033[1;33m";
	std::cout << "[ ScavTrap ]";
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

void ScavTrap::attack(std::string const &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "\033[1;33m";
		std::cout << "[ ScavTrap ]";
		std::cout << "\033[0m ";
		std::cout << this->getName() << " is destroyed" << std::endl;
		return ;
	}
	else if (this->getEnergyPoints() == 0)
	{
		std::cout << "\033[1;33m";
		std::cout << "[ ScavTrap ]";
		std::cout << "\033[0m ";
		std::cout << this->getName() << " not enough energy" << std::endl;
		return ;
	}
	guardGate();
	this->_energyPoints -= 1;
	std::cout << "\033[1;33m";
	std::cout << "[ ScavTrap ]";
	std::cout << "\033[0m ";
	std::cout << this->getName() << " attack " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "\033[1;33m";
	std::cout << "[ ScavTrap ]";
	std::cout << "\033[0m ";
	std::cout << this->getName() << "is now in Gate keeper mode." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ScavTrap &src)
{
	out << "\033[1;33m"
	<< "[ ScavTrap ]"
	<< "\033[0m "
	<< src.getName() << " has " << src.getHitPoints() << " hit points, " << src.getEnergyPoints() << " energy points and " << src.getAttackDamage() << " attack damage" << std::endl;
	return (out);
}
