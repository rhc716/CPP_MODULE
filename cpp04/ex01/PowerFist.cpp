/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:24:54 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 22:02:23 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() :
	AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const &old_obj) :
	AWeapon(old_obj)
{
}

PowerFist::~PowerFist()
{
}

PowerFist &PowerFist::operator=(PowerFist const &old_obj)
{
	AWeapon::operator=(old_obj);
	return (*this);
}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
