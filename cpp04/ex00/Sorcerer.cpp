/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:02:43 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 17:04:01 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &old_obj)
{
	this->name = old_obj.name;
	this->title = old_obj.title;
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title
			<< ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &old_obj)
{
	this->name = old_obj.name;
	this->title = old_obj.title;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Sorcerer &sorcerer)
{
	out << "I am " << sorcerer.get_name() << ", " << sorcerer.get_title() 
		<< ", and I like ponies!" << std::endl;
	return (out);
}

std::string const	&Sorcerer::get_name()
{
	return (this->name);
}

std::string const	&Sorcerer::get_title()
{
	return (this->title);
}

void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}
