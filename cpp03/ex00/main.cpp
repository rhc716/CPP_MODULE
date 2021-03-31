/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:51:30 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 01:56:45 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	print_ascii()
{
	std::string		path_1 = "./ascii";
	std::string		path_2 = "../ascii";
	std::ifstream	ifs;
	char			buf[100];

	ifs.open(path_1);
	if(!ifs.is_open())
		ifs.open(path_2);
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
	ft.beRepaired(20);
	ft.takeDamage(110);
	ft.beRepaired(110);
	ft.vaulthunter_dot_exe("SCV");
}
