/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:59:29 by hroh              #+#    #+#             */
/*   Updated: 2021/04/06 23:47:49 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conv.hpp"

int main(int argc, char **argv)
{
	Conv *conv;

	if (argc != 2)
		std::cout << "Requires 1 argument" << std::endl;
	else
	{
		try
		{
			conv = new Conv(argv[1]);
			conv->scalar_print();
			delete conv;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
