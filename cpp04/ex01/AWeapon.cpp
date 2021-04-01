/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:13:24 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 20:20:26 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon()
{
	this->name = "";
	this->apcost = 0;
	this->damage = 0;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
{
	this->name = name;
	this->apcost = apcost;
	this->damage = damage;
}

AWeapon::AWeapon(AWeapon const &old_obj)
{
	this->name = old_obj.name;
	this->apcost = old_obj.apcost;
	this->damage = old_obj.damage;
}

AWeapon::~AWeapon()
{
	
}

AWeapon &AWeapon::operator=(AWeapon const &old_obj)
{
	this->name = old_obj.name;
	this->apcost = old_obj.apcost;
	this->damage = old_obj.damage;
	return (*this);
}

std::string const &AWeapon::getName() const
{
	return (this->name);
}

int				AWeapon::getAPCost() const
{
	return (this->apcost);
}

int				AWeapon::getDamage() const
{
	return (this->damage);
}