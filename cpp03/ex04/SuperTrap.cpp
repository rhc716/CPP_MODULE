/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:32:08 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 02:15:44 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(const std::string &name) :
	FragTrap(name), NinjaTrap(name)
{
	this->name = name;
	this->level = 1;
	this->hp = FragTrap::hp_copy;
	this->hp_max = FragTrap::hp_max_copy;
	this->energy = NinjaTrap::energy_copy;
	this->energy_max = NinjaTrap::energy_max_copy;
	this->melee_damage = NinjaTrap::melee_damage_copy;
	this->range_damage = FragTrap::range_damage_copy;
	this->armor = FragTrap::armor_copy;
	print_border(SUPERTRAP);
	std::cout << GREEN << this->name << " : Supertrap is here" DEFAULT << std::endl;
	print_border(SUPERTRAP);
}

SuperTrap::SuperTrap(const SuperTrap &old_obj)
{
	this->name = old_obj.name;
	this->level = old_obj.level;
	this->hp = old_obj.hp;
	this->hp_max = old_obj.hp_max;
	this->energy = old_obj.energy;
	this->energy_max = old_obj.energy_max;
	this->melee_damage = old_obj.melee_damage;
	this->range_damage = old_obj.range_damage;
	this->armor = old_obj.armor;
	print_border(SUPERTRAP);
	std::cout << GREEN << this->name << " : Supertrap is here" DEFAULT << std::endl;
	print_border(SUPERTRAP);
}

SuperTrap::~SuperTrap()
{
	print_border(SUPERTRAP);
	std::cout << RED << this->name << " : Bye~!" DEFAULT << std::endl;
	print_border(SUPERTRAP);
}

SuperTrap &SuperTrap::operator=(const SuperTrap &old_obj)
{
	this->name = old_obj.name;
	this->level = old_obj.level;
	this->hp = old_obj.hp;
	this->hp_max = old_obj.hp_max;
	this->energy = old_obj.energy;
	this->energy_max = old_obj.energy_max;
	this->melee_damage = old_obj.melee_damage;
	this->range_damage = old_obj.range_damage;
	this->armor = old_obj.armor;
	return (*this);
}

void		SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::meleeAttack(target);
}

void		SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}

unsigned int SuperTrap::skillAttack(std::string const &target, ClapTrap &target_obj)
{
	FragTrap::vaulthunter_dot_exe(target);
	NinjaTrap::ninjaShoebox(target_obj);
	return (0);
}

void	SuperTrap::takeDamage(unsigned int amount)
{
	unsigned int damage = 0;

	if (amount > this->armor)
		damage = amount - this->armor;
	if (this->hp > damage)
		this->hp -= damage;
	else
		this->hp = 0;
	print_border(SUPERTRAP);
	std::cout << "Supertrap <" << this->name << "> : take " << damage << " points of damage!" << std::endl;
	std::cout << "Supertrap <" << this->name << "> : Current HP is " << this->hp << std::endl;
	print_border(SUPERTRAP);
}

void	SuperTrap::beRepaired(unsigned int amount)
{
	unsigned int repaired = 0;

	repaired = amount;
	if (this->hp + amount >= this->hp_max)
	{
		repaired = this->hp_max - this->hp;
		this->hp = this->hp_max;
	}
	else
		this->hp += amount;
	print_border(SUPERTRAP);
	std::cout << "Supertrap <" << this->name << "> : Repaired for " << repaired << " points of hp!" << std::endl;
	std::cout << "Supertrap <" << this->name << "> : Current HP is " << this->hp << std::endl;
	print_border(SUPERTRAP);
}
