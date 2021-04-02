/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:41:10 by hroh              #+#    #+#             */
/*   Updated: 2021/04/02 19:09:10 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main()
{
	std::cout << "====== new ======" << std::endl;
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISpaceMarine* roy = new TacticalMarine;
	ISpaceMarine* aron = new AssaultTerminator;
	ISquad* vlc = new Squad;
	Squad *squard_1 = new Squad;
	Squad *squard_2 = new Squad;
	std::cout << "====== new ======\n" << std::endl;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	std::cout << "\n==================\n" << std::endl;
	squard_1->push(roy);
	squard_2->push(aron);
	squard_1->getUnit(0)->battleCry();
	squard_2->getUnit(0)->battleCry();
	*squard_2 = *squard_1;
	squard_1->getUnit(0)->battleCry();
	squard_2->getUnit(0)->battleCry();
	std::cout << "\n==================\n" << std::endl;
	std::cout << "\n====== delete ======" << std::endl;
	delete vlc;
	delete squard_1;
	delete squard_2;
	std::cout << "====== delete ======" << std::endl;
	return 0;
}
