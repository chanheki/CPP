/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:42:41 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/01 17:50:44 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{

public:
	enum Level { DEBUG = 0,
				 INFO = 1,
				 WARNING  = 2, 
				 ERROR  = 3,
				 WRONG = 4 };

public:
	Harl(std::string level);
	~Harl(void);
	void harlFilter( void );
	
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void wrong( void );
	Level _level;
};

#endif