/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:02:26 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 17:02:15 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string const &name) :
	Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &old_obj)
{
	this->name = old_obj.name;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon &Peon::operator=(Peon const &old_obj)
{
	this->name = old_obj.name;
	return (*this);
}

void	Peon::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a pink pony!" << std::endl;
}
