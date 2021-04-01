/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:35:25 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 22:32:43 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name)
{
	this->name = name;
	this->ap = 40;
	this->weapon = NULL;
}

Character::Character(Character const &old_obj)
{
	this->name = old_obj.name;
	this->ap = old_obj.ap;
	this->weapon = old_obj.weapon;
}

Character::~Character()
{
}

Character &Character::operator=(Character const &old_obj)
{
	this->name = old_obj.name;
	this->ap = old_obj.ap;
	this->weapon = old_obj.weapon;
	return (*this);
}

void				Character::recoverAP()
{
	this->ap += 10;
	if (this->ap > 40)
		this->ap = 40;
}

void				Character::equip(AWeapon* weapon)
{
	this->weapon = weapon;
}

void 				Character::attack(Enemy* enemy)
{
	if (this->weapon != NULL && enemy)
	{
		if (this->ap < this->weapon->getAPCost())
			return ;
		this->ap -= this->weapon->getAPCost();
		std::cout << this->name << " attacks " << enemy->getType() << " with a "
					<< this->weapon->getName() << std::endl;
		this->weapon->attack();
		enemy->takeDamage(this->weapon->getDamage());
		if (enemy->getHP() <= 0)
			delete (enemy);
	}
}

std::string const	&Character::getName() const
{
	return (this->name);
}

int					Character::getAp() const
{
	return (this->ap);
}

AWeapon				*Character::getWeapon() const
{
	return (this->weapon);
}

std::ostream	&operator<<(std::ostream &out, Character const &ch)
{
	out << ch.getName() << " has " << ch.getAp();
	if (ch.getWeapon() != NULL)
		out << " AP and wields a " << ch.getWeapon()->getName();
	else
		out << " AP and is unarmed";
	out << std::endl;
	return (out);
}
