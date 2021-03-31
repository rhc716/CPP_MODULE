/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:38:34 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 01:52:04 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	print_border(CLAPTRAP);
	std::cout << GREEN << "ClapTrap has been created." DEFAULT << std::endl;
	print_border(CLAPTRAP);
}

ClapTrap::ClapTrap(const std::string &name)
{
	this->name = name;
	this->level = 1;
	this->hp = 80;
	this->hp_max = 80;
	this->energy = 80;
	this->energy_max = 80;
	this->melee_damage = 30;
	this->range_damage = 20;
	this->armor = 5;
	print_border(CLAPTRAP);
	std::cout << GREEN << "ClapTrap <" << this->name << "> has been created." DEFAULT << std::endl;
	print_border(CLAPTRAP);
}

ClapTrap::ClapTrap(const ClapTrap &old_obj)
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
	print_border(CLAPTRAP);
	std::cout << GREEN << "ClapTrap <" << this->name << "> has been created." DEFAULT << std::endl;
	print_border(CLAPTRAP);
}

ClapTrap::~ClapTrap()
{
	print_border(CLAPTRAP);
	std::cout << GREEN << "ClapTrap <" << this->name << "> is gone" DEFAULT << std::endl;
	print_border(CLAPTRAP);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &old_obj)
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

void	ClapTrap::rangedAttack(std::string const &target)
{
	print_border(CLAPTRAP);
	std::cout << "ClapTrap <" << this->name 
		<< "> attacks <" << target << "> at range, causing <"
		<< this->range_damage << "> points of damage!" << std::endl;
	print_border(CLAPTRAP);
}

void	ClapTrap::meleeAttack(std::string const &target)
{
	print_border(CLAPTRAP);
	std::cout << "ClapTrap <" << this->name 
		<< "> attacks <" << target << "> at melee, causing <"
		<< this->melee_damage << "> points of damage!" << std::endl;
	print_border(CLAPTRAP);
}

unsigned int ClapTrap::skillAttack(std::string const &target, ClapTrap &target_obj)
{
	std::cout << "ClapTrap <" << this->name 
		<< "> skill attacks <" << target_obj.get_name() << "> " << std::endl;
	return (target.length());
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int damage = 0;

	if (amount > this->armor)
		damage = amount - this->armor;
	if (this->hp > damage)
		this->hp -= damage;
	else
		this->hp = 0;
	print_border(CLAPTRAP);
	std::cout << "ClapTrap <" << this->name << "> : take "
				<< damage << " points of damage!" << std::endl;
	std::cout << this->name << " : Current HP is " << this->hp << std::endl;
	print_border(CLAPTRAP);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int repaired = 0;

	repaired = amount;
	if (this->hp + amount >= this->hp_max)
	{
		repaired = this->hp_max - this->hp;
		this->hp = 100;
	}
	else
		this->hp += amount;
	print_border(CLAPTRAP);
	std::cout << "ClapTrap <" << this->name << "> : Repaired for " 
				<< repaired << " points of hp!" << std::endl;
	std::cout << this->name << " : Current HP is " << this->hp << std::endl;
	print_border(CLAPTRAP);
}

void	ClapTrap::restoreEnergy(unsigned int amount)
{
	unsigned int restored = 0;

	restored = amount;
	if (this->energy + amount >= this->energy_max)
	{
		restored = this->energy_max - this->energy;
		this->energy = 100;
	}
	else
		this->energy += amount;
	print_border(FRAGTRAP);
	std::cout << this->name << " : Restored for " << restored << " points of energy!" << std::endl;
	std::cout << this->name << " : Current Energy is " << this->energy << std::endl;
	print_border(FRAGTRAP);
}

unsigned int	ClapTrap::get_hp()
{
	return (this->hp);
}

std::string		&ClapTrap::get_name()
{
	return (this->name);
}

unsigned int	ClapTrap::get_melee_damage()
{
	return (this->melee_damage);
}

unsigned int	ClapTrap::get_range_damage()
{
	return (this->range_damage);
}

void			ClapTrap::print_member()
{
	print_border(CLAPTRAP);
	std::cout << GREEN << "name : " << this->name << std::endl;
	std::cout << GREEN << "level : " << this->level << std::endl;
	std::cout << GREEN << "hp : " << this->hp << std::endl;
	std::cout << GREEN << "hp_max : " << this->hp_max << std::endl;
	std::cout << GREEN << "energy : " << this->energy << std::endl;
	std::cout << GREEN << "energy_max : " << this->energy_max << std::endl;
	std::cout << GREEN << "melee_damage : " << this->melee_damage << std::endl;
	std::cout << GREEN << "range_damage : " << this->range_damage << std::endl;
	std::cout << GREEN << "armor : " << this->armor << std::endl;
	print_border(CLAPTRAP);
}

void	print_border(unsigned int type_of_trap)
{
	usleep(T_USLEEP / 2);
	if (type_of_trap == FRAGTRAP)
		std::cout << CYAN;
	else if (type_of_trap == SCARVTRAP)
		std::cout << GREY;
	else if (type_of_trap == CLAPTRAP)
		std::cout << BLUE;
	else if (type_of_trap == NINJATRAP)
		std::cout << PURPLE;
	else if (type_of_trap == SUPERTRAP)
		std::cout << YELLOW;
	std::cout << "==============================================================" DEFAULT << std::endl;
	usleep(T_USLEEP / 2);
}
