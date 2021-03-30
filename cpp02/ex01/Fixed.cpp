/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:31:33 by hroh              #+#    #+#             */
/*   Updated: 2021/03/30 10:52:26 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &old_obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = old_obj;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = i << this->frac_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f * (1 << this->frac_bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &old_obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = old_obj.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	return (out << obj.toFloat());
}

int		Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	std::cout << "before : " << (float)this->value << std::endl;
	return ((float)this->value / (float)(1 << this->frac_bits));
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->frac_bits);
}
