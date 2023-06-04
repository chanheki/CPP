#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	void guardGate(void);
public:
	FragTrap(void);
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &src);
	FragTrap &operator=(const FragTrap &rhs);
public:
	void highFivesGuys(void);
};

#endif
