/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:21:31 by hroh              #+#    #+#             */
/*   Updated: 2021/03/29 20:59:21 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->zombie_type = "Fool";
}

Zombie::Zombie(std::string name)
{
	this->zombie_name = name;
	this->zombie_type = "Fool";
}

Zombie::~Zombie()
{
	std::cout << "Zombie committed suicide" << std::endl;
}

void Zombie::set_type(std::string type)
{
	this->zombie_type = type;
}

void Zombie::announce(void)
{
	std::cout << "<" << this->zombie_name << " (" << this->zombie_type << ")> "
	<< "Braiiiiiiinnnssss..." << std::endl;
}
