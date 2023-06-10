#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "\033[1;32m";
	std::cout << "[ FragTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Default constructor called" << std::endl;
	this->setName("Scav Default");
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[1;32m";
	std::cout << "[ FragTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Default with Param constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[1;32m";
	std::cout << "[ FragTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "\033[1;32m";
	std::cout << "[ FragTrap ]";
	std::cout << "\033[0m ";
	std::cout << "Copy with Param constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "\033[1;32m";
	std::cout << "[ FragTrap ]";
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "\033[1;32m";
	std::cout << "[ FragTrap ]";
	std::cout << "\033[0m ";
	std::cout << this->getName() << " high fives guys" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const FragTrap &src)
{
	out << "\033[1;32m"
	<< "[ FragTrap ]"
	<< "\033[0m "
	<< src.getName() << " has " << src.getHitPoints() << " hit points, " << src.getEnergyPoints() << " energy points and " << src.getAttackDamage() << " attack damage" << std::endl;
	return (out);
}
