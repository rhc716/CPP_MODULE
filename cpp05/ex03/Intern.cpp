/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:07:32 by hroh              #+#    #+#             */
/*   Updated: 2021/04/07 15:01:51 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &old_obj)
{
	(void)old_obj;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &old_obj)
{
	(void)old_obj;
	return (*this);
}

Form *new_form_shrubberycreation(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

Form *new_form_robotomyrequest(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

Form *new_form_presidentialpardon(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	Form *ret = NULL;
	typedef struct {std::string formname; Form* (*func)(std::string const &target);} t_pair;

	t_pair selectform[3] = 
	{
		{"shrubbery creation", &new_form_shrubberycreation}
		,{"robotomy request", &new_form_robotomyrequest}
		,{"presidential pardon", &new_form_presidentialpardon}
	};
	for (int i = 0; i < 3; ++i)
		if (selectform[i].formname == formName)
			ret = selectform[i].func(target);
	if (ret != NULL)
		std::cout << "Intern creates <" << ret->getName() << ">" << std::endl;
	else
		std::cout << "Intern : There are no matching forms" << std::endl;
	return (ret);
}
