/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:37:06 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/08 13:42:05 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void ) {
{
	std::cout << "\033[1;31m";
	std::cout << "[ Frag Trap ]";
	std::cout << "\033[0m" << std::endl;

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

	k.highFivesGuys();
}
	return 0;
}
