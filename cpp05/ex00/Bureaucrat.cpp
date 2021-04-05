/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:34:29 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 17:34:13 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &old_obj)
{
	if (old_obj.grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (old_obj.grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->name = old_obj.name;
	this->grade = old_obj.grade;
}


Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &old_obj)
{
	if (old_obj.grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (old_obj.grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->name = old_obj.name;
	this->grade = old_obj.grade;
	return (*this);
}

std::string const &Bureaucrat::getName() const
{
	return (this->name);
}

int			Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::increase_grade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void		Bureaucrat::decrease_grade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat obj)
{
	out << "<" << obj.getName() << ">, bureaucrat grade <" << obj.getGrade() << ">" << std::endl;
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is Too Low");
}
