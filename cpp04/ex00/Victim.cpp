/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:03:07 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 17:00:45 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim()
{
}

Victim::Victim(std::string const &name)
{
	this->name = name;
	std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const &old_obj)
{
	this->name = old_obj.name;
	std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name << " just died for no apparent reason!" << std::endl;
}

Victim &Victim::operator=(Victim const &old_obj)
{
	this->name = old_obj.name;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Victim &victim)
{
	out << "I'm " << victim.get_name() << " and I like otters!" << std::endl;
	return (out);
}

std::string	const &Victim::get_name()
{
	return (this->name);
}

void				Victim::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a cute little sheep!" << std::endl;
}
