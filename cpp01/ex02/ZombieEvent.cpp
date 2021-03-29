/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:21:20 by hroh              #+#    #+#             */
/*   Updated: 2021/03/29 20:59:28 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
}

ZombieEvent::~ZombieEvent(void)
{
}

void		ZombieEvent::setZombieType(Zombie *zombie, std::string type)
{
	zombie->set_type(type);
}

Zombie		*ZombieEvent::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}

std::string get_random_name(void)
{
	int			random_num;
	std::string random_name;
	std::string color[10] = {"Red", "Blue", "Black", "Violet", "Navy", "Brown", "Purple", "Gold", "Whilte", "Silver"};
	std::string animal[10] = {"Dog", "Cat", "Horse", "Mouse", "Sheep", "Cow", "Bear", "Wolf", "Lion", "Monkey"};

	std::srand(std::time(NULL));
	random_num = std::rand() % 10;
	random_name = color[random_num] + " ";
	random_num = std::rand() % 10;
	random_name += animal[random_num];
	random_name += " Zombie";
	return (random_name);
}

Zombie		*ZombieEvent::randomChump(void)
{
	Zombie *zombie = new Zombie(get_random_name());
	zombie->announce();
	return (zombie);
}

void		ZombieEvent::zombies_life(Zombie *zombie)
{
	usleep(USLEEPTIME);
	zombie->set_type("Smart");
	zombie->announce();
	usleep(USLEEPTIME);
	zombie->set_type("Too Smart");
	zombie->announce();
	usleep(USLEEPTIME);
	delete(zombie);
}
