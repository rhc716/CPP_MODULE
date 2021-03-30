/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:49:53 by hroh              #+#    #+#             */
/*   Updated: 2021/03/30 21:53:45 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
{
	this->name = name;
	this->level = 1;
	this->hp = 100;
	this->hp_max = 100;
	this->energy = 100;
	this->energy_max = 100;
	this->melee_damage = 30;
	this->range_damage = 20;
	this->armor = 5;
	this->kill_count = 0;
	print_border(FRAGTRAP);
	std::cout << GREEN << this->name << " : online. Somebody called for an exterminator?" DEFAULT << std::endl;
	print_border(FRAGTRAP);
}

FragTrap::FragTrap(const FragTrap &old_obj)
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
	this->kill_count = old_obj.kill_count;
	print_border(FRAGTRAP);
	std::cout << GREEN << this->name << " : online. Somebody called for an exterminator?" DEFAULT << std::endl;
	print_border(FRAGTRAP);
}

FragTrap::~FragTrap()
{
	print_border(FRAGTRAP);
	std::cout << RED << this->name << " : System ... System down... Bye.." DEFAULT << std::endl;
	print_border(FRAGTRAP);
}

FragTrap &FragTrap::operator=(const FragTrap &old_obj)
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
	this->kill_count = old_obj.kill_count;
	return (*this);
}

void	FragTrap::rangedAttack(std::string const &target)
{
	print_border(FRAGTRAP);
	std::cout << "<" << this->name 
		<< "> attacks <" << target << "> at range, causing <"
		<< this->range_damage << "> points of damage!" << std::endl;
	print_border(FRAGTRAP);
}

void	FragTrap::meleeAttack(std::string const &target)
{
	print_border(FRAGTRAP);
	std::cout << "<" << this->name 
		<< "> attacks <" << target << "> at melee, causing <"
		<< this->melee_damage << "> points of damage!" << std::endl;
	print_border(FRAGTRAP);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	unsigned int damage = 0;

	if (amount > this->armor)
		damage = amount - this->armor;
	if (this->hp > damage)
		this->hp -= damage;
	else
		this->hp = 0;
	print_border(FRAGTRAP);
	std::cout << this->name << " : take " << damage << " points of damage!" << std::endl;
	std::cout << this->name << " : Current HP is " << this->hp << std::endl;
	print_border(FRAGTRAP);
}

void	FragTrap::beRepaired(unsigned int amount)
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
	print_border(FRAGTRAP);
	std::cout << this->name << " : Repaired for " << repaired << " points of hp!" << std::endl;
	std::cout << this->name << " : Current HP is " << this->hp << std::endl;
	print_border(FRAGTRAP);
}

void	FragTrap::restoreEnergy(unsigned int amount)
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

unsigned int	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int				random_num;
	std::string		skill[10] = {"Drop the Hammer!", "I Am Rubber, You Are Glue!", "Hyperion Punch!",
								"Rainbow coolant!", "Tripleclocked!", "Kimchi SSadaegi!", "Hydro pump!",
								"Yamato cannon!", "nuclear bomb!", "Finger snap!"};
	unsigned int	damage[10] = {15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
	unsigned int	total_damage = 0;

	if (this->energy < 25)
	{
		print_border(FRAGTRAP);
		std::cout << this->name << " : Lack of energy.. Current energy is " << this->energy << std::endl;
		std::cout << this->name << " : vaulthunter.exe needs 25 energy." << std::endl;
		print_border(FRAGTRAP);
		return (0);
	}
	else
	{
		this->energy -= 25;
		print_border(FRAGTRAP);
		std::cout << this->name << PURPLE " : vaulthunter_dot_exe Running..." DEFAULT << std::endl;
		std::cout << this->name << PURPLE " : Hacking the Vault Hunters' skills..." DEFAULT << std::endl;
		print_border(FRAGTRAP);
		for (int i = 0; i < 5; i++)
		{
			random_num = std::rand() % 10;
			std::cout << this->name << " : [" << i + 1 << "] " GREEN << skill[random_num] << std::endl;
			std::cout << DEFAULT "<" << this->name 
						<< "> attacks <" << target << "> with " << skill[random_num] << " <"
						<< damage[random_num] << "> points of damage!" << std::endl;
			if (i != 4)
				std::cout << std::endl;
			total_damage += damage[random_num];
			usleep(T_USLEEP / 2);
		}
		print_border(FRAGTRAP);
		std::cout << this->name << PURPLE " : vaulthunter_dot_exe End..." DEFAULT << std::endl;
		print_border(FRAGTRAP);
	}
	return (total_damage);
}

unsigned int	FragTrap::get_hp()
{
	return (this->hp);
}

std::string		&FragTrap::get_name()
{
	return (this->name);
}

unsigned int	FragTrap::get_melee_damage()
{
	return (this->melee_damage);
}

unsigned int	FragTrap::get_range_damage()
{
	return (this->range_damage);
}

unsigned int	FragTrap::set_kill_count()
{
	return (this->kill_count++);
}

void	print_border(unsigned int type_of_trap)
{
	usleep(T_USLEEP / 2);
	if (type_of_trap == FRAGTRAP)
		std::cout << CYAN;
	else if (type_of_trap == SCARVTRAP)
		std::cout << GREY;
	std::cout << "==============================================================" DEFAULT << std::endl;
	usleep(T_USLEEP / 2);
}
