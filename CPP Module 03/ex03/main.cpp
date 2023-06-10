/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:37:06 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/07 23:22:36 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void claptrap() {
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

	for (int i = 1; i < 9; i++)
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

void scavtrap() {
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

	for (int i = 1; i < 50; i++)
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

	std::cout << "\033[1;31m";
	std::cout << "[ Frag Trap ]";
	std::cout << "\033[0m" << std::endl;
}

void fragtrap() {
	FragTrap k;
	FragTrap l("l");
	FragTrap m(l);
	FragTrap n;
	n = m;
	n.setName("n");
	std::cout << n << std::endl;
	n.beRepaired(100);
	std::cout << m << std::endl;

	std::cout << "--- variable declaration end ---" << std::endl;

	k.setName("scavtrap");
	std::cout << k << std::endl;

	k.attack("target");

	std::cout << "--- repair ---" << std::endl;
	k.beRepaired(10);
	std::cout << k << std::endl;

	std::cout << "--- take damage ---" << std::endl;
	k.takeDamage(10);
	std::cout << k << std::endl;

	k.takeDamage(10);
	std::cout << k << std::endl;

	std::cout << "--- repair ---" << std::endl;

	k.beRepaired(10);
	std::cout << k << std::endl;

	for (int i = 1; i < 50; i++)
	{
		std::cout << i << " - attack\n";
		k.attack("another target");
		std::cout << k << std::endl;
	}

	k.takeDamage(200);
	std::cout << k << std::endl;

	k.beRepaired(100);
	std::cout << k << std::endl;

	std::cout << "--- not enough energy ---" << std::endl;
	k.attack("another target");
	std::cout << k << std::endl;
}

void diamondtrap() {
	DiamondTrap o;
	DiamondTrap p("p");
	DiamondTrap q(p);
	DiamondTrap r;
	r = q;
	
	std::cout << "--- variable declaration end ---" << std::endl;

	r.setName("r");
	std::cout << r << std::endl;
	std::cout << q << std::endl;
	r.getName();
	r.whoAmI();
	r.beRepaired(100);
	r.attack("target");
	r.highFivesGuys();
	r.takeDamage(100);
}

int main( void ) {
	// claptrap();
	// scavtrap();
	// fragtrap();
	diamondtrap();

	return 0;
}