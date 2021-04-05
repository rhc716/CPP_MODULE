/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:23:49 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 20:29:40 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	Form("PresidentialPardonForm", 25, 25), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &old_obj) :
	Form(old_obj), target(old_obj.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &old_obj)
{
	Form::operator=(old_obj);
	this->target = old_obj.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << "<" << this->target << "> has been pardoned by Zafod Beeblebrox" << std::endl;
}