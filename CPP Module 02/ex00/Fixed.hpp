/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:36:51 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/02 04:35:29 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_fixedPointValue;
	static const int	_fractionalBits;
public:
	Fixed(void);
	Fixed(const Fixed &src);
	~Fixed();
	Fixed&	operator=(Fixed const &fixed);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif