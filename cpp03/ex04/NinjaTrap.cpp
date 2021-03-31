/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:53:17 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 01:42:42 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{
	
}

NinjaTrap::NinjaTrap(const std::string &name)
{
	this->name = name;
	this->level = 1;
	this->hp = 60;
	this->hp_max = 60;
	this->energy = 120;
	this->energy_max = 120;
	this->melee_damage = 60;
	this->range_damage = 5;
	this->armor = 0;
	this->energy_copy = this->energy;
	this->energy_max_copy = this->energy_max;
	this->melee_damage_copy = this->melee_damage;
	print_border(NINJATRAP);
	std::cout << GREEN << this->name << " : The shadows have enlightened me." DEFAULT << std::endl;
	print_border(NINJATRAP);
}

NinjaTrap::NinjaTrap(const NinjaTrap &old_obj)
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
	print_border(NINJATRAP);
	std::cout << GREEN << this->name << " : The shadows have enlightened me." DEFAULT << std::endl;
	print_border(NINJATRAP);
}

NinjaTrap::~NinjaTrap()
{
	print_border(NINJATRAP);
	std::cout << RED << this->name << " : Ignorance is fatal." DEFAULT << std::endl;
	print_border(NINJATRAP);
}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &old_obj)
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

void	NinjaTrap::rangedAttack(std::string const &target)
{
	print_border(NINJATRAP);
	std::cout << "NinjaTrap <" << this->name 
		<< "> attacks <" << target << "> at range, causing <"
		<< this->range_damage << "> points of damage!" << std::endl;
	print_border(NINJATRAP);
}

void	NinjaTrap::meleeAttack(std::string const &target)
{
	print_border(NINJATRAP);
	std::cout << "NinjaTrap <" << this->name 
		<< "> attacks <" << target << "> at melee, causing <"
		<< this->melee_damage << "> points of damage!" << std::endl;
	print_border(NINJATRAP);
}

unsigned int NinjaTrap::skillAttack(std::string const &target, ClapTrap &target_obj)
{
	std::cout << "NinjaTrap <" << this->name 
		<< "> skill attacks <" << target << ">" << std::endl;
	ninjaShoebox(target_obj);
	return (0);
}

void	NinjaTrap::takeDamage(unsigned int amount)
{
	unsigned int damage = 0;

	if (amount > this->armor)
		damage = amount - this->armor;
	if (this->hp > damage)
		this->hp -= damage;
	else
		this->hp = 0;
	print_border(NINJATRAP);
	std::cout << "NinjaTrap <" << this->name << "> : take " << damage << " points of damage!" << std::endl;
	std::cout << "NinjaTrap <" << this->name << "> : Current HP is " << this->hp << std::endl;
	print_border(NINJATRAP);
}

void	NinjaTrap::beRepaired(unsigned int amount)
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
	print_border(NINJATRAP);
	std::cout << "NinjaTrap <" << this->name << "> : Repaired for " << repaired << " points of hp!" << std::endl;
	std::cout << "NinjaTrap <" << this->name << "> : Current HP is " << this->hp << std::endl;
	print_border(NINJATRAP);
}

void	NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
	print_border(NINJATRAP);
	std::cout << "NinjaTrap <" << this->name << "> : Viva Free Pandora! Viva la Robolution!" << std::endl;
	print_border(NINJATRAP);
	print_border(CLAPTRAP);
	std::cout << "ClapTrap <" << trap.get_name() << "> : We are the claptraps and we are legion! Viva la Robolution!" << std::endl;
	print_border(CLAPTRAP);
}

void	NinjaTrap::ninjaShoebox(FragTrap &trap)
{
	print_border(NINJATRAP);
	std::cout << "NinjaTrap <" << this->name << "> : How do YOU like target practice? Huh? HUH?!" << std::endl;
	print_border(NINJATRAP);
	print_border(FRAGTRAP);
	std::cout << "FragTrap <" << trap.get_name() << "> : ? ?" << std::endl;
	print_border(FRAGTRAP);
}

void	NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
	print_border(NINJATRAP);
	std::cout << "NinjaTrap <" << this->name << "> : What's happening to me?" << std::endl;
	print_border(NINJATRAP);
	print_border(SCARVTRAP);
	std::cout << "ScavTrap <" << trap.get_name() << "> : Hello, Traveler!" << std::endl;
	print_border(SCARVTRAP);
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
	print_border(NINJATRAP);
	std::cout << "NinjaTrap <" << this->name << "> : Challenge me, Shen... you shall not be an orphan long!" << std::endl;
	print_border(NINJATRAP);
	print_border(NINJATRAP);
	std::cout << "NinjaTrap <" << trap.get_name() << "> : You're already dead, you just haven't caught up yet." << std::endl;
	print_border(NINJATRAP);
}
