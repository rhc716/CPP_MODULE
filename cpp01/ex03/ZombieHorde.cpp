/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:21:20 by hroh              #+#    #+#             */
/*   Updated: 2021/03/26 20:58:14 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
	std::srand(std::time(NULL));
	std::cout << "Hordes of zombies gather...\n\n";
	this->horde = new Zombie*[n];
	for (int i = 0; i < n; i++)
	{
		this->horde[i] = randomChump();
	}
	this->nbr_zombies = n;
}

ZombieHorde::~ZombieHorde(void)
{
	for(int i = 0; i < this->nbr_zombies; i++)
	{
		delete(this->horde[i]);
		usleep(USLEEPTIME);
	}
	delete(this->horde);
	std::cout << "\nThe zombie Horde is gone..." << std::endl;
}

void		ZombieHorde::setZombieType(Zombie *zombie, std::string type)
{
	zombie->set_type(type);
};

Zombie		*ZombieHorde::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
};

Zombie		*ZombieHorde::randomChump(void)
{
	Zombie *zombie = new Zombie(get_random_name());
	ZombieHorde::setZombieType(zombie, get_random_type());
	return (zombie);
};

void		ZombieHorde::announce(void)
{
	for(int i = 0; i < this->nbr_zombies; i++)
	{
		this->horde[i]->announce();
		usleep(USLEEPTIME);
	}
};

std::string get_random_name(void)
{
	int			random_num;
	std::string random_name;
	std::string color[10] = {"Red", "Blue", "Black", "Violet", "Navy", "Brown", "Purple", "Gold", "Whilte", "Silver"};
	std::string animal[10] = {"Dog", "Cat", "Horse", "Mouse", "Sheep", "Cow", "Bear", "Wolf", "Lion", "Monkey"};

	random_num = std::rand() % 10;
	random_name = color[random_num] + " ";
	random_num = std::rand() % 10;
	random_name += animal[random_num];
	random_name += " Zombie";
	return (random_name);
};

std::string get_random_type(void)
{
	int			random_num;
	std::string random_type;
	std::string type[5] = {"Fire", "Water", "Wind", "Poison", "Lightning"};

	random_num = std::rand() % 5;
	random_type = type[random_num];
	return (random_type);
};
