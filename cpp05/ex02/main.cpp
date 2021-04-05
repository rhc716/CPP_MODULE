/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:02:43 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 20:55:25 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat *bureaucrat_1 = new Bureaucrat("AAA", 1);
	Bureaucrat *bureaucrat_2 = new Bureaucrat("BBB", 100);

	std::cout << *bureaucrat_1;
	std::cout << *bureaucrat_2 << std::endl;

	Form *form_1 = new ShrubberyCreationForm("ABC");
	Form *form_2 = new RobotomyRequestForm("Marvin");
	Form *form_3 = new PresidentialPardonForm("ArthurDent");
	
	std::cout << *form_1;
	std::cout << *form_2;
	std::cout << *form_3 << std::endl;

	form_1->beSigned(*bureaucrat_1);
	form_2->beSigned(*bureaucrat_1);
	form_3->beSigned(*bureaucrat_1);
	
	std::cout << *form_1;
	std::cout << *form_2;
	std::cout << *form_3 << std::endl;
	
	form_1->execute(*bureaucrat_1);
	form_2->execute(*bureaucrat_1);
	form_3->execute(*bureaucrat_1);

	try
	{
		form_1->execute(*bureaucrat_2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		form_2->execute(*bureaucrat_2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		form_3->execute(*bureaucrat_2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// ShrubberyCreationForm
	delete bureaucrat_1;
	delete bureaucrat_2;
	delete form_1;
	delete form_2;
	delete form_3;
}
