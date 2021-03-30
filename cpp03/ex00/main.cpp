/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:51:30 by hroh              #+#    #+#             */
/*   Updated: 2021/03/30 19:02:47 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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
	FragTrap ft("R2D2");
	ft.meleeAttack("SCV");
	ft.rangedAttack("SCV");
	ft.takeDamage(20);
	ft.beRepaired(10);
	ft.takeDamage(50);
	ft.beRepaired(100);
	ft.takeDamage(150);
	ft.beRepaired(20);
	ft.vaulthunter_dot_exe("SCV");
}