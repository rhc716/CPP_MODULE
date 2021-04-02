/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:38:39 by hroh              #+#    #+#             */
/*   Updated: 2021/04/03 01:27:03 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src_1 = new MateriaSource();
	MateriaSource* src_2 = new MateriaSource();
	MateriaSource* src_3 = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	AMateria* materia_1;
	AMateria* materia_2;
	AMateria* materia_3;
	AMateria* materia_4;

	src_1->learnMateria(new Ice());
	src_1->learnMateria(new Cure());

	materia_1 = src_1->createMateria("ice");
	me->equip(materia_1);
	materia_2 = src_1->createMateria("cure");
	me->equip(materia_2);
	materia_3 = src_1->createMateria("ice");
	me->equip(materia_3);
	materia_4 = src_1->createMateria("cure");
	me->equip(materia_4);

	std::cout << "##########################################\n" << std::endl;

	for (int i = -1; i < 5; i++)
	{
		std::cout << "i : " << i << std::endl;
		me->use(i, *bob);
	}

	std::cout << "\n##########################################\n" << std::endl;

	for (int i = 0; i < 5; i++)
		me->unequip(0);

	delete materia_1;
	delete materia_2;
	delete materia_3;
	delete materia_4;

	materia_1 = src_1->createMateria("ice");
	me->equip(materia_1);
	for (int i = 1; i < 6; i++)
	{
		me->use(0, *bob);
		std::cout << "i : " << i << " / _xp : " << materia_1->getXP() << std::endl;
	}
	me->unequip(0);
	delete materia_1;
	materia_1 = NULL;

	std::cout << "\n##########################################\n" << std::endl;

	materia_1 = src_1->createMateria("ice");
	materia_2 = src_1->createMateria("cure");
	*materia_1 = *materia_2;
	std::cout << "material_1 (type) : " << materia_1->getType() << std::endl;
	delete materia_1;
	delete materia_2;

	std::cout << "\n##########################################\n" << std::endl;

	src_2->learnMateria(new Ice());
	src_2->learnMateria(new Cure());
	*src_3 = *src_2;
	
	materia_1 = src_3->createMateria("ice");
	me->equip(materia_1);
	materia_2 = src_3->createMateria("cure");
	me->equip(materia_2);
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n##########################################\n" << std::endl;

	delete src_1;
	delete src_2;
	delete src_3;
	delete bob;
	delete me;
	return 0;
}