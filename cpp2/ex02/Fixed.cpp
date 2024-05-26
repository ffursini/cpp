/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:46:09 by fursini           #+#    #+#             */
/*   Updated: 2024/05/26 22:46:09 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = value << Fixed::fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(value * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->fixedPointValue = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return this->fixedPointValue > rhs.getRawBits();
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return this->fixedPointValue < rhs.getRawBits();
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return this->fixedPointValue >= rhs.getRawBits();
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return this->fixedPointValue <= rhs.getRawBits();
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return this->fixedPointValue == rhs.getRawBits();
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return this->fixedPointValue != rhs.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	this->fixedPointValue++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->fixedPointValue++;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	this->fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->fixedPointValue--;
	return tmp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->fixedPointValue / (1 << Fixed::fractionalBits);
}

int		Fixed::toInt(void) const
{
	return this->fixedPointValue >> Fixed::fractionalBits;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
