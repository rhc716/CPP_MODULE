/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:49:53 by hroh              #+#    #+#             */
/*   Updated: 2021/03/30 16:30:45 by hroh             ###   ########.fr       */
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
	print_border();
	std::cout << GREEN << this->name << " : online. Somebody called for an exterminator?" DEFAULT << std::endl;
	print_border();
}

FragTrap::~FragTrap()
{
	print_border();
	std::cout << RED << this->name << " : System ... System down... Bye.." DEFAULT << std::endl;
	print_border();
}

void	FragTrap::rangedAttack(std::string const &target)
{
	print_border();
	std::cout << "<" << this->name 
		<< "> attacks <" << target << "> at range, causing <"
		<< this->range_damage << "> points of damage!" << std::endl;
	print_border();
};

void	FragTrap::meleeAttack(std::string const &target)
{
	print_border();
	std::cout << "<" << this->name 
		<< "> attacks <" << target << "> at melee, causing <"
		<< this->melee_damage << "> points of damage!" << std::endl;
	print_border();
};

void	FragTrap::takeDamage(unsigned int amount)
{
	unsigned int damage = 0;

	if (amount > this->armor)
		damage = amount - this->armor;
	if (this->hp > damage)
		this->hp -= damage;
	else
		this->hp = 0;
	print_border();
	std::cout << this->name << " : take " << damage << " points of damage!" << std::endl;
	std::cout << this->name << " : Current HP is " << this->hp << std::endl;
	print_border();
};

void	FragTrap::beRepaired(unsigned int amount)
{
	unsigned int repaired = 0;

	repaired = amount;
	if (this->hp + amount >= this->hp_max)
	{
		this->hp = 100;
		repaired = this->hp_max - this->hp;
	}
	else
		this->hp += amount;
	print_border();
	std::cout << this->name << " : Repaired for " << repaired << " points of hp!" << std::endl;
	std::cout << this->name << " : Current HP is " << this->hp << std::endl;
	print_border();
};

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int			random_num;
	std::string		skill[10] = {"Drop the Hammer!", "I Am Rubber, You Are Glue!", "Hyperion Punch!",
								"Rainbow coolant!", "Tripleclocked!", "Kimchi SSadaegi!", "Hydro pump!",
								"Yamato cannon!", "nuclear bomb!", "Finger snap!"};
	unsigned int	damage[10] = {15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

	if (this->energy < 25)
	{
		print_border();
		std::cout << this->name << " : Lack of energy.. Current energy is " << this->energy << std::endl;
		std::cout << this->name << " : vaulthunter.exe needs 25 energy." << std::endl;
		print_border();
		return ;
	}
	else
	{
		this->energy -= 25;
		print_border();
		std::cout << this->name << PURPLE " : vaulthunter_dot_exe Running..." DEFAULT << std::endl;
		usleep(T_USLEEP);
		std::cout << this->name << PURPLE " : Hacking the Vault Hunters' skills..." DEFAULT << std::endl;
		print_border();
		usleep(T_USLEEP);
		for (int i = 0; i < 5; i++)
		{
			random_num = std::rand() % 10;
			usleep(T_USLEEP);
			std::cout << this->name << " : [" << i + 1 << "] " GREEN << skill[random_num] << std::endl;
			usleep(T_USLEEP);
			std::cout << DEFAULT "<" << this->name 
						<< "> attacks <" << target << "> with " << skill[random_num] << " <"
						<< damage[random_num] << "> points of damage!" << std::endl;
			if (i != 4)
				std::cout << std::endl;
		}
		print_border();
		std::cout << this->name << PURPLE " : vaulthunter_dot_exe End..." DEFAULT << std::endl;
		print_border();
	}
};

void	print_border()
{
	std::cout << CYAN "==============================================================" DEFAULT << std::endl;
}
