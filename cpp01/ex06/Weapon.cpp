/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:51:40 by hroh              #+#    #+#             */
/*   Updated: 2021/03/26 23:56:20 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->weapon_type = type;
};

Weapon::~Weapon(void)
{
}

void				Weapon::setType(std::string type)
{
	this->weapon_type = type;
};

const std::string	&Weapon::getType(void)
{
	return (this->weapon_type);
};