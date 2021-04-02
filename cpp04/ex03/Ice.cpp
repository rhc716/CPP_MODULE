/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:20:03 by hroh              #+#    #+#             */
/*   Updated: 2021/04/02 23:01:16 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() :
	AMateria("ice")
{
}

Ice::Ice(Ice const &old_obj) :
	AMateria(old_obj)
{
}

Ice::~Ice()
{
}

Ice 	&Ice::operator=(Ice const &old_obj)
{
	AMateria::operator=(old_obj);
	return (*this);
}

Ice	*Ice::clone() const
{
	Ice *clone = new Ice(*this);
	return (clone);
}

void	Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
