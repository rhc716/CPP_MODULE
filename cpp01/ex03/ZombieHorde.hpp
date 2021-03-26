/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:21:04 by hroh              #+#    #+#             */
/*   Updated: 2021/03/26 20:58:09 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# define USLEEPTIME 300000

# include "Zombie.hpp"
# include <ctime>
# include <unistd.h>

class ZombieHorde
{
private:
	Zombie **horde;
	int		nbr_zombies;

public:
	ZombieHorde(int n);
	~ZombieHorde(void);

	void		setZombieType(Zombie *zombie, std::string type);
	Zombie		*newZombie (std::string name);
	Zombie		*randomChump(void);
	void		announce(void);
};

std::string		get_random_type(void);
std::string		get_random_name(void);

#endif