/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:52:52 by hroh              #+#    #+#             */
/*   Updated: 2021/04/15 20:43:50 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <set>
#include <list>
#include <deque>

int main()
{
	std::vector<int> con_1;
	std::set<int> con_2;
	std::list<int> con_3;
	std::deque<int> con_4;
	con_1.reserve(3);

	con_1.push_back(1);
	con_1.push_back(2);
	con_1.push_back(3);
	con_2.insert(1);
	con_2.insert(2);
	con_2.insert(3);
	con_3.push_back(1);
	con_3.push_back(2);
	con_3.push_back(3);
	con_4.push_back(1);
	con_4.push_front(2);
	con_4.push_back(3);
	
	std::cout << "[1, 2, 3]" << std::endl;
	std::cout << "vector\tfind(3) : " << *easyfind(con_1, 3) << std::endl;
	std::cout << "set\tfind(3) : " << *easyfind(con_2, 3) << std::endl;
	std::cout << "list\tfind(3) : " << *easyfind(con_3, 3) << std::endl;
	std::cout << "deque\tfind(3) : " << *easyfind(con_4, 3) << std::endl;
	try
	{
		std::cout << "vector\tfind(4) : " << *easyfind(con_1, 4) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "set\tfind(4) : " << *easyfind(con_2, 4) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "list\tfind(4) : " << *easyfind(con_3, 4) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "deque\tfind(4) : " << *easyfind(con_4, 4) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
