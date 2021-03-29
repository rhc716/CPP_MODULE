/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:07:07 by hroh              #+#    #+#             */
/*   Updated: 2021/03/29 20:59:37 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony	*ponyOnTheHeap(void)
{
	Pony* pony = new Pony();

	std::cout << "Pony's birthday is [" << pony->get_birthday() << "]" << std::endl;
	return (pony);
}

void	ponyOnTheStack(void)
{
	Pony pony;

	std::cout << "Pony's birthday is [" << pony.get_birthday() << "]" << std::endl;
}

int		main()
{
	Pony *pony;

	std::cout << "----- ponyOnTheStack call -----" << std::endl;
	ponyOnTheStack();
	std::cout << "----- ponyOnTheStack end -----\n\n";
	std::cout << "----- ponyOnTheHeap call -----" << std::endl;
	pony = ponyOnTheHeap();
	std::cout << "----- ponyOnTheHeap end -----" << std::endl;
	std::cout << "=> main : delete(pony);" << std::endl;
	delete(pony);
	return (0);
}
