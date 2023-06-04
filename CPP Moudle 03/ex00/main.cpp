/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:37:06 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/04 22:23:32 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
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
	return 0;
}
