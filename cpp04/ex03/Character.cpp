/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:50:51 by hroh              #+#    #+#             */
/*   Updated: 2021/04/07 15:01:27 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const &name) :
	name(name)
{
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = NULL;
}

Character::Character(Character const &old_obj) :
	name(old_obj.name)
{
	for (int i = 0; i < 4; ++i)
	{
		this->inventory[i] = NULL;
		if (old_obj.inventory[i])
			this->equip(old_obj.inventory[i]->clone());
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		if (this->inventory[i])
			delete this->inventory[i];
}

Character &Character::operator=(Character const &old_obj)
{
	this->name = old_obj.name;
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		if (old_obj.inventory[i])
			this->equip(old_obj.inventory[i]->clone());
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
	{
		this->inventory[idx] = NULL;
		for (int i = idx; i < 3; ++i)
		{
			if (this->inventory[i + 1] != NULL)
			{
				this->inventory[i] = this->inventory[i + 1];
				this->inventory[i + 1] = NULL;
			}
		}
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}
