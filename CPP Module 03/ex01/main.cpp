/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:37:06 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/07 22:43:13 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
{
	ClapTrap a;
	ClapTrap b("b");
	ClapTrap c(b);
	ClapTrap d;
	d = c;

	std::cout << "--- variable declaration end ---" << std::endl;

	a.setName("claptrap");
	std::cout << a << std::endl;

	a.attack("target");
	
	std::cout << "--- repair ---" << std::endl;
	a.beRepaired(10);
	std::cout << a << std::endl;

	std::cout << "--- take damage ---" << std::endl;
	a.takeDamage(10);
	std::cout << a << std::endl;

	a.takeDamage(10);
	std::cout << a << std::endl;
	
	std::cout << "--- repair ---" << std::endl;
	a.beRepaired(10);
	std::cout << a << std::endl;

	for (int i = 1 ; i < 9 ; i++)
	{
		std::cout << i << " - repair";
		a.beRepaired(10);
	}
	std::cout << a << std::endl;

	std::cout << "--- not enough energy ---" << std::endl;
	a.attack("another target");
	std::cout << a << std::endl;

	std::cout << "\033[1;31m";
	std::cout << "[ Scav Trap ]";
	std::cout << "\033[0m" << std::endl;
}
{
	ScavTrap e;
	ScavTrap f("f");
	ScavTrap g(f);
	ScavTrap h;
	h = g;
	h.setName("h");
	std::cout << h << std::endl;
	h.beRepaired(100);
	std::cout << g << std::endl;

	std::cout << "--- variable declaration end ---" << std::endl;

	e.setName("scavtrap");
	std::cout << e << std::endl;

	e.attack("target");

	std::cout << "--- repair ---" << std::endl;
	e.beRepaired(10);
	std::cout << e << std::endl;

	std::cout << "--- take damage ---" << std::endl;
	e.takeDamage(10);
	std::cout << e << std::endl;

	e.takeDamage(10);
	std::cout << e << std::endl;

	std::cout << "--- repair ---" << std::endl;

	e.beRepaired(10);
	std::cout << e << std::endl;

	for (int i = 1 ; i < 50 ; i++)
	{
		std::cout << i << " - attack\n";
		e.attack("another target");
		std::cout << e << std::endl;
	}

	e.takeDamage(200);
	std::cout << e << std::endl;

	e.beRepaired(100);
	std::cout << e << std::endl;

	std::cout << "--- not enough energy ---" << std::endl;
	e.attack("another target");
	std::cout << e << std::endl;
}
	return 0;
}
