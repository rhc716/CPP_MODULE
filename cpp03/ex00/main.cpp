/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:51:30 by hroh              #+#    #+#             */
/*   Updated: 2021/03/30 16:16:14 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	print_ascii()
{
	std::ifstream	ifs("ascii");
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
	FragTrap ft("R2D2");
	usleep(T_USLEEP);
	ft.meleeAttack("SCV");
	usleep(T_USLEEP);
	ft.rangedAttack("SCV");
	usleep(T_USLEEP);
	ft.takeDamage(20);
	usleep(T_USLEEP);
	ft.beRepaired(10);
	usleep(T_USLEEP);
	ft.takeDamage(50);
	usleep(T_USLEEP);
	ft.beRepaired(100);
	usleep(T_USLEEP);
	ft.takeDamage(150);
	usleep(T_USLEEP);
	ft.beRepaired(20);
	usleep(T_USLEEP);
	ft.vaulthunter_dot_exe("SCV");
}
