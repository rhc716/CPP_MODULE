/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:02:43 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 17:36:14 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *bureaucrat_1 = new Bureaucrat("AAA", 1);
	Bureaucrat *bureaucrat_2 = new Bureaucrat("BBB", 100);
	Bureaucrat *bureaucrat_3 = new Bureaucrat("CCC", 150);

	std::cout << *bureaucrat_1;
	std::cout << *bureaucrat_2;
	std::cout << *bureaucrat_3 << std::endl;

	try
	{
		bureaucrat_1->increase_grade();
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		bureaucrat_2->increase_grade();
		std::cout << *bureaucrat_2;
		bureaucrat_2->decrease_grade();
		std::cout << *bureaucrat_2;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		bureaucrat_3->decrease_grade();
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	// constructor exception
	Bureaucrat *bureaucrat_4;
	Bureaucrat *bureaucrat_5;
	try
	{
		bureaucrat_4 = new Bureaucrat("DDD", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		bureaucrat_5 = new Bureaucrat("DDD", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	delete bureaucrat_1;
	delete bureaucrat_2;
	delete bureaucrat_3;
}
