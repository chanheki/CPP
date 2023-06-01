/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:48:01 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/01 17:59:19 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(std::string level) {
	std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == names[i])
		{
			this->_level = static_cast<Level>(i);
			break;
		}
		this->_level = WRONG;
	}
}

Harl::~Harl(void){}

void Harl::harlFilter(void) {
    switch (this->_level) {
        case DEBUG: debug();
        case INFO: info();
        case WARNING: warning();
        case ERROR: error(); break;
		case WRONG: wrong(); break;
    }
}

void Harl::debug( void )
{
	std::cout << "\033[1;34m";
	std::cout << "[ DEBUG ]";
	std::cout << "\033[0m" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "\033[1;32m";
	std::cout << "[ INFO ]";
	std::cout << "\033[0m" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "\033[1;33m";
	std::cout << "[ WARNING ]";
	std::cout << "\033[0m" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "\033[1;31m";
	std::cout << "[ ERROR ]";
	std::cout << "\033[0m" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::wrong( void )
{
	std::cout << "\033[1;34m";
	std::cout << "[ Probably complaining about insignificant problems ]";
	std::cout << "\033[0m" << std::endl;
}

