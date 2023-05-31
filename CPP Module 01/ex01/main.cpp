/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:26:46 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/01 00:28:47 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void leaks()
{
	system("leaks MoarBrainz");
}

int main(void) {
	Zombie* zombies = zombieHorde(10, "Heap Zombies");
	for (int i = 0; i < 10; i++) {
		zombies[i].announce();
	}
	delete [] zombies;
	system("leaks MoarBrainz");
	atexit(leaks);
	return 0;
}
