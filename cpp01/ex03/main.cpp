/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:21:33 by hroh              #+#    #+#             */
/*   Updated: 2021/03/26 20:55:31 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int		main()
{
	ZombieHorde *horde = new ZombieHorde(10);
	horde->announce();
	std::cout << "\nHordes of zombies are being hunted...\n\n";
	delete(horde);
}