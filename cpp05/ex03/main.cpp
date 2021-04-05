/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:02:43 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 22:07:36 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	*bureaucrat = new Bureaucrat("AAA", 1);
	Intern		*intern = new Intern();
	std::cout << *bureaucrat << std::endl;

	Form *form_1;
	Form *form_2;
	Form *form_3;
	Form *form_4;
	Form *form_5;

	form_1 = intern->makeForm("shrubbery creation", "ABC");
	form_2 = intern->makeForm("robotomy request", "Marvin");
	form_3 = intern->makeForm("presidential pardon", "ArthurDent");
	form_4 = intern->makeForm("shrubbery creation11111", "ABC");
	form_5 = intern->makeForm("robotomy request11111", "Marvin");

	form_1->beSigned(*bureaucrat);
	form_2->beSigned(*bureaucrat);
	form_3->beSigned(*bureaucrat);

	std::cout << *form_1;
	std::cout << *form_2;
	std::cout << *form_3 << std::endl;

	// ShrubberyCreationForm
	delete bureaucrat;
	delete intern;
	delete form_1;
	delete form_2;
	delete form_3;
}
