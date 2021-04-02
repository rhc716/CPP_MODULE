/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:19:48 by hroh              #+#    #+#             */
/*   Updated: 2021/04/02 23:01:09 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() :
	AMateria("cure")
{
}

Cure::Cure(Cure const &old_obj) :
	AMateria(old_obj)
{
}

Cure::~Cure()
{
}

Cure 	&Cure::operator=(Cure const &old_obj)
{
	AMateria::operator=(old_obj);
	return (*this);
}

Cure	*Cure::clone() const
{
	Cure *clone = new Cure(*this);
	return (clone);
}

void	Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
