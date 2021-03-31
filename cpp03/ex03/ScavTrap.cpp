/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:37:02 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 02:15:18 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
{
	this->name = name;
	this->level = 1;
	this->hp = 100;
	this->hp_max = 100;
	this->energy = 100;
	this->energy_max = 100;
	this->melee_damage = 25;
	this->range_damage = 18;
	this->armor = 6;
	print_border(SCARVTRAP);
	std::cout << GREEN << this->name << " : I came to battle.." DEFAULT << std::endl;
	print_border(SCARVTRAP);
}

ScavTrap::ScavTrap(const ScavTrap &old_obj, int mute)
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
	if (mute == 1)
		return ;
	print_border(SCARVTRAP);
	std::cout << GREEN << this->name << " : I came to battle.." DEFAULT << std::endl;
	print_border(SCARVTRAP);
}

ScavTrap::~ScavTrap()
{
	print_border(SCARVTRAP);
	std::cout << RED << this->name << " : Shit...! You are the lucky one" DEFAULT << std::endl;
	print_border(SCARVTRAP);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &old_obj)
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

void	ScavTrap::rangedAttack(std::string const &target)
{
	print_border(SCARVTRAP);
	std::cout << "ScavTrap <" << this->name << "> Attempted range attack to <" 
				<< target << "> Damage is <" << this->range_damage << ">" << std::endl;
	print_border(SCARVTRAP);
}

void	ScavTrap::meleeAttack(std::string const &target)
{
	print_border(SCARVTRAP);
	std::cout << "ScavTrap <" << this->name << "> Attempted melee attack to <"
				<< target << "> Damage is <" << this->melee_damage << ">" << std::endl;
	print_border(SCARVTRAP);
}

unsigned int ScavTrap::skillAttack(std::string const &target, ClapTrap &target_obj)
{
	std::cout << "ScavTrap <" << this->name 
		<< "> skill attacks <" << target << ">" << std::endl;
	challengeNewcomer(target_obj);
	return (0);
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	unsigned int damage = 0;

	if (amount > this->armor)
		damage = amount - this->armor;
	if (this->hp > damage)
		this->hp -= damage;
	else
		this->hp = 0;
	print_border(SCARVTRAP);
	std::cout << this->name << " : i got hit ! <" << damage << "> points of damage!" << std::endl;
	std::cout << this->name << " : i have " << this->hp << " HP left !" << std::endl;
	print_border(SCARVTRAP);
}

void	ScavTrap::beRepaired(unsigned int amount)
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
	print_border(SCARVTRAP);
	std::cout << this->name << " : Self repairing ! : " << repaired << " points of hp!" << std::endl;
	std::cout << this->name << " : i have " << this->hp << " HP left !" << std::endl;
	print_border(SCARVTRAP);
}

void	ScavTrap::set_spec(unsigned int hp, int damage_adj, unsigned int armor)
{
	this->hp = hp;
	this->hp_max = hp;
	if ((int)range_damage + damage_adj > 0 && (int)melee_damage + damage_adj > 0)
	{
		this->melee_damage = (unsigned int)((int)this->melee_damage + damage_adj);
		this->range_damage = (unsigned int)((int)this->range_damage + damage_adj);
	}
	this->armor = armor;
}

void	ScavTrap::append_name_nbr(int i)
{
	std::stringstream ss;

	ss << this->name << "_" << std::setfill('0') << std::setw(3) << i;
	this->name = ss.str();
}

void	ScavTrap::challengeNewcomer(ClapTrap &challenger)
{
	unsigned int random = std::rand() % 2;
	std::string	challenge_mode[2] = {"Enemy 10 Kill Challenges", "Boss Kill Challenges"};

	print_border(FRAGTRAP);
	std::cout << "Chosen challenge : " << challenge_mode[random] << std::endl;
	print_border(FRAGTRAP);
	if (random == 0)
		enemy_10_kill_challenges(challenger);
	else
		boss_kill_challenges(challenger);
}

bool	ScavTrap::fight_to_challenger(ClapTrap &challenger, ScavTrap &scarv)
{
	int	ran;
	unsigned int damage = 0;

	std::cout << "The battle with ["<< scarv.name << "] began !" << std::endl;
	while (challenger.get_hp() > 0 && scarv.hp > 0)
	{
		ran = rand() % 6;
		if (ran == 0)
		{
			challenger.meleeAttack(scarv.name);
			scarv.takeDamage(challenger.get_melee_damage());
		}
		else if (ran == 1)
		{
			challenger.rangedAttack(scarv.name);
			scarv.takeDamage(challenger.get_range_damage());
		}
		else if (ran == 2)
		{
			scarv.meleeAttack(challenger.get_name());
			challenger.takeDamage(scarv.melee_damage);
		}
		else if (ran == 3)
		{
			scarv.rangedAttack(challenger.get_name());
			challenger.takeDamage(scarv.range_damage);
		}
		else if (ran == 4)
		{
			damage = challenger.skillAttack(scarv.name, scarv);
			scarv.takeDamage(damage);
		}
		else 
		{
			challenger.beRepaired(30);
			challenger.restoreEnergy(30);
		}
	}
	if (scarv.hp == 0)
	{
		delete (&scarv);
		return (false);
	}
	else
		return (true);
}

void	ScavTrap::enemy_10_kill_challenges(ClapTrap &challenger)
{
	ScavTrap	**horde = new ScavTrap*[10];
	bool		fail;
	int			i;

	set_spec(50, -5, 5);
	for (i = 0; i < 10; i++)
	{
		horde[i] = new ScavTrap(*this, 1);
		horde[i]->append_name_nbr(i + 1);
	}
	print_border(FRAGTRAP);
	std::cout << "10 enemies are coming..." << std::endl;
	print_border(FRAGTRAP);
	fail = false;
	for (i = 0; i < 10; i++)
	{
		fail = fight_to_challenger(challenger, *horde[i]);
		if (fail == true)
			break ;
	}
	print_border(FRAGTRAP);
	if (fail == true)
		std::cout << YELLOW "Challenge failure..." DEFAULT << std::endl;
	else
		std::cout << YELLOW "Challenge success !" DEFAULT << std::endl;
	print_border(FRAGTRAP);
	while (i < 10)
		delete (horde[i++]);
	delete[] (horde);
}

void	ScavTrap::boss_kill_challenges(ClapTrap &challenger)
{
	bool		fail;
	ScavTrap *boss = new ScavTrap("Boss");

	boss->set_spec(1000, 5, 5);
	fail = fight_to_challenger(challenger, *boss);
	print_border(FRAGTRAP);
	if (fail == true)
	{
		std::cout << YELLOW "Challenge failure..." DEFAULT << std::endl;
		delete (boss);
	}
	else
		std::cout << YELLOW "Challenge success !" DEFAULT << std::endl;
	print_border(FRAGTRAP);
}