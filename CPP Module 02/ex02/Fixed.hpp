/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:37:03 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/04 01:31:06 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_fixedPointValue;
	static const int	_fractionalBits;
public:
	Fixed(void);
	Fixed(const Fixed &src);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed&	operator=(Fixed const &fixed);
public:
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
public:
	bool	operator>(const Fixed& other);
	bool	operator<(const Fixed& other);
	bool	operator>=(const Fixed& other);
	bool	operator<=(const Fixed& other);
	bool	operator==(const Fixed& other);
	bool	operator!=(const Fixed& other);
public:
	Fixed&	operator+(Fixed const &fixed);
	Fixed&	operator-(Fixed const &fixed);
	Fixed&	operator*(Fixed const &fixed);
	Fixed&	operator/(Fixed const &fixed);
public:
	Fixed&	operator++(void);
	Fixed&	operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);
public:
	static const Fixed& max(Fixed const &a, Fixed const &b);
	static const Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static const Fixed& min(Fixed &a, Fixed &b);
};

std::ostream& operator<<(std::ostream &out_stream, Fixed const &fixed);

#endif