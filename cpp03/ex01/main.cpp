/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:51:30 by hroh              #+#    #+#             */
/*   Updated: 2021/03/30 22:52:25 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void	print_ascii()
{
	std::ifstream	ifs("../ascii");
	char			buf[100];

	if (ifs.is_open())
	{
		while (ifs)
		{
			ifs.getline(buf, 100);
			std::cout << buf << std::endl;
			usleep(T_USLEEP / 10);
		}
		ifs.close();
	}
}

int		main()
{
	std::srand(std::time(NULL));
	print_ascii();
	FragTrap frt("R2D2");
	ScavTrap scv("SCV");
	frt.meleeAttack("SCV");
	frt.rangedAttack("SCV");
	frt.takeDamage(20);
	frt.beRepaired(10);
	frt.takeDamage(50);
	frt.beRepaired(100);
	frt.takeDamage(150);
	frt.beRepaired(20);
	frt.beRepaired(20);
	frt.vaulthunter_dot_exe("SCV");
	frt.vaulthunter_dot_exe("SCV");
	scv.meleeAttack("R2D2");
	scv.rangedAttack("R2D2");
	scv.takeDamage(15);
	scv.beRepaired(15);
	scv.takeDamage(100);
	scv.beRepaired(110);
	scv.challengeNewcomer(frt);
	frt.beRepaired(100);
	frt.restoreEnergy(100);
	scv.challengeNewcomer(frt);
	return (0);
}
