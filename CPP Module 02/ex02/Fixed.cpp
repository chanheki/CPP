/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:36:59 by chanheki          #+#    #+#             */
/*   Updated: 2023/06/02 04:17:41 by chanheki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _fixedPointValue(0){}

Fixed::~Fixed(){}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int value)
{
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

bool Fixed::operator>(const Fixed& other)
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other)
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other)
{
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other)
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other)
{
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other)
{
	return this->getRawBits() != other.getRawBits();
}

Fixed& Fixed::operator=(Fixed const &fixed)
{
	if (this != &fixed)
		this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed& Fixed::operator+(Fixed const &fixed)
{
	this->setRawBits(this->getRawBits() + fixed.getRawBits());
	return (*this);
}

Fixed& Fixed::operator-(Fixed const &fixed)
{
	this->setRawBits(this->getRawBits() - fixed.getRawBits());
	return (*this);
}

Fixed& Fixed::operator*(Fixed const &fixed)
{
	this->setRawBits((this->getRawBits() * fixed.getRawBits()) >> this->_fractionalBits);
	return (*this);
}

Fixed& Fixed::operator/(Fixed const &fixed)
{
	this->setRawBits((this->getRawBits() << this->_fractionalBits) / fixed.getRawBits());
	return (*this);
}

Fixed& Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}