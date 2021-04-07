/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:21:33 by hroh              #+#    #+#             */
/*   Updated: 2021/04/07 14:59:40 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int		main()
{
	ZombieEvent ev;
	Zombie		*zombie;

	zombie = ev.newZombie("Named Zombies");
	zombie->announce();
	ev.zombies_life(zombie);
	for (int i = 0; i < 3; ++i)
	{
		usleep(USLEEPTIME);
		std::cout << std::endl;
		zombie = ev.randomChump();
		ev.zombies_life(zombie);
	}
}