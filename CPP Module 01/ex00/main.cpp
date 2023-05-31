/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 02:44:15 by chanheki          #+#    #+#             */
/*   Updated: 2023/05/31 22:03:19 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void leaks() {
    system("leaks BraiiiiiiinnnzzzZ");
}

int main() {
    Zombie Foo = Zombie("Foo");
    Zombie Bar("Bar");
    Zombie	*heap_zombie = newZombie("Heap Zombie");
    Bar.announce();
    heap_zombie->announce();
    randomChump("Stack Zombie");
    system("leaks BraiiiiiiinnnzzzZ");
    delete heap_zombie;
    atexit(leaks);
    return (0);
}