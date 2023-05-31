/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:59:20 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/01 01:15:23 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) {
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA(void){};

void	HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
