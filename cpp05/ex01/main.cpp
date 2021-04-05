/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:02:43 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 20:40:22 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *bureaucrat_1 = new Bureaucrat("AAA", 1);
	Bureaucrat *bureaucrat_2 = new Bureaucrat("BBB", 100);

	std::cout << *bureaucrat_1;
	std::cout << *bureaucrat_2 << std::endl;

	// Form
	// constructor exception
	Form *form;
	try
	{
		form = new Form("Form_AAA", 0, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		form = new Form("Form_AAA", 1, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// beSigned exception
	form = new Form("Form_AAA", 5, 5);
	std::cout << *form;
	try
	{
		form->beSigned(*bureaucrat_1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *form;
	delete form;

	form = new Form("Form_BBB", 99, 99);
	std::cout << *form;
	try
	{
		form->beSigned(*bureaucrat_2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *form;
	delete form;

	delete bureaucrat_1;
	delete bureaucrat_2;
}
