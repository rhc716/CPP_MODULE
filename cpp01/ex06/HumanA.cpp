/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:49:33 by hroh              #+#    #+#             */
/*   Updated: 2021/03/27 00:28:52 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name)
{
	this->name = name;
};

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->name = name;
	this->weapon = &weapon;
};

HumanA::~HumanA(void)
{
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
};

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
};
