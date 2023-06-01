/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:48:01 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/01 17:17:06 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){}

Harl::~Harl(void){}

void	Harl::complain(std::string level) {
	void	(Harl::*funcPtr[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4 && level != names[i]) {
		i++;
	}
	while (i == 4)
		return;
	(this->*funcPtr[i])();
}

void Harl::debug( void )
{
	std::cout << "\033[1;34m";
	std::cout << "DEBUG: ";
	std::cout << "\033[0m";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "\033[1;32m";
	std::cout << "INFO: ";
	std::cout << "\033[0m";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "\033[1;33m";
	std::cout << "WARNING: ";
	std::cout << "\033[0m";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "\033[1;31m";
	std::cout << "ERROR: ";
	std::cout << "\033[0m";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

