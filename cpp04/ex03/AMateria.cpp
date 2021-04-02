/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:51:09 by hroh              #+#    #+#             */
/*   Updated: 2021/04/03 01:17:00 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type) :
	_type(type), _xp(0)
{
}

AMateria::AMateria(AMateria const &old_obj) :
	_type(old_obj._type), _xp(old_obj._xp)
{
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(AMateria const &old_obj)
{
	this->_xp = old_obj._xp;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (this->_type);
}

unsigned int		AMateria::getXP() const
{
	return (this->_xp);
}

void				AMateria::use(ICharacter& target)
{
	(void)target;
	this->_xp += 10;
}
