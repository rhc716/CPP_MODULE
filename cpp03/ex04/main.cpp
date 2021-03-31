/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:51:30 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 01:57:54 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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
	ClapTrap *clap = new ClapTrap("jjagjjag");
	FragTrap *frt = new FragTrap("R2D2");
	ScavTrap *scv = new ScavTrap("SCV");
	NinjaTrap *nin = new NinjaTrap("ZED");
	NinjaTrap *nin2 = new NinjaTrap("SHEN");
	SuperTrap *sp = new SuperTrap("superman");
	frt->meleeAttack("SCV");
	frt->rangedAttack("SCV");
	frt->takeDamage(20);
	frt->beRepaired(20);
	frt->takeDamage(110);
	frt->beRepaired(110);
	frt->skillAttack("SCV", *scv);
	scv->meleeAttack("R2D2");
	scv->rangedAttack("R2D2");
	scv->takeDamage(20);
	scv->beRepaired(20);
	scv->takeDamage(110);
	scv->beRepaired(110);
	scv->skillAttack("R2D2", *frt);
	frt->beRepaired(100);
	frt->restoreEnergy(100);
	scv->skillAttack("R2D2", *frt);
	nin->meleeAttack("SCV");
	nin->rangedAttack("SCV");
	nin->takeDamage(20);
	nin->beRepaired(20);
	nin->takeDamage(110);
	nin->beRepaired(110);
	nin->ninjaShoebox(*clap);
	nin->ninjaShoebox(*frt);
	nin->ninjaShoebox(*scv);
	nin->ninjaShoebox(*nin2);
	sp->vaulthunter_dot_exe("ZED");
	sp->restoreEnergy(25);
	sp->ninjaShoebox(*clap);
	sp->ninjaShoebox(*frt);
	sp->ninjaShoebox(*scv);
	sp->ninjaShoebox(*nin2);
	sp->print_member();
	delete clap;
	delete frt;
	delete scv;
	delete nin;
	delete nin2;
	delete sp;
	return (0);
}
