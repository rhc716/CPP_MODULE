/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:23:36 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 20:36:19 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	Form("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &old_obj) :
	Form(old_obj), target(old_obj.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &old_obj)
{
	Form::operator=(old_obj);
	this->target = old_obj.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << "Shhheeeeing... wweeeeeeinng..." << std::endl;
	if ((std::rand() % 100) > 50)
		std::cout << "<" << this->target << "> has been robotomized successfully" << std::endl;
	else
		std::cout << "<" << this->target << "> failed to be robotomize" << std::endl;
}