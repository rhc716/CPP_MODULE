/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:18:25 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 20:25:21 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()
{
	this->hp = 0;
	this->type = "";
}

Enemy::Enemy(int hp, std::string const &type)
{
	this->hp = hp;
	this->type = type;
}

Enemy::Enemy(Enemy const &old_obj)
{
	this->hp = old_obj.hp;
	this->type = old_obj.type;
}

Enemy::~Enemy()
{
}

Enemy &Enemy::operator=(Enemy const &old_obj)
{
	this->hp = old_obj.hp;
	this->type = old_obj.type;
	return (*this);
}

std::string const	&Enemy::getType() const
{
	return (this->type);
}

int					Enemy::getHP() const
{
	return (this->hp);
}

void 				Enemy::takeDamage(int damage)
{
	if (damage >= 0)
	{
		this->hp -= damage;
		if (this->hp < 0)
			this->hp = 0;
	}
}
