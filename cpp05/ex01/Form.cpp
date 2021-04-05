/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:52:17 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 19:29:26 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int required_grade_sign, int required_grade_exec)
{
	if (required_grade_sign < 1 || required_grade_exec < 1)
		throw Form::GradeTooHighException();
	else if (required_grade_sign > 150 || required_grade_exec > 150)
		throw Form::GradeTooLowException();
	this->name = name;
	this->required_grade_sign = required_grade_sign;
	this->required_grade_exec = required_grade_exec;
	this->_signed = false;
}

Form::Form(Form const &old_obj)
{
	if (old_obj.required_grade_sign < 1 || old_obj.required_grade_exec < 1)
		throw Form::GradeTooHighException();
	else if (old_obj.required_grade_sign > 150 || old_obj.required_grade_exec > 150)
		throw Form::GradeTooLowException();
	this->name = old_obj.name;
	this->required_grade_sign = old_obj.required_grade_sign;
	this->required_grade_exec = old_obj.required_grade_exec;
	this->_signed = old_obj._signed;
}

Form::~Form()
{
}

Form &Form::operator=(Form const &old_obj)
{
	if (old_obj.required_grade_sign < 1 || old_obj.required_grade_exec < 1)
		throw Form::GradeTooHighException();
	else if (old_obj.required_grade_sign > 150 || old_obj.required_grade_exec > 150)
		throw Form::GradeTooLowException();
	this->name = old_obj.name;
	this->required_grade_sign = old_obj.required_grade_sign;
	this->required_grade_exec = old_obj.required_grade_exec;
	this->_signed = old_obj._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Form const &obj)
{
	out << "==================================\n";
	out << "Form <" << obj.getName() << ">" << std::endl;
	out << "Grade required for signing : <" << obj.getGradeSign() << ">" << std::endl;
	out << "Grade required for execution : <" << obj.getGradeExec() << ">" << std::endl;
	out << "id Signed : " << obj.getSigned() << std::endl;
	out << "==================================\n";
	return (out);
}

const std::string	&Form::getName() const
{
	return (this->name);
}

int					Form::getGradeSign() const
{
	return (this->required_grade_sign);
}

int					Form::getGradeExec() const
{
	return (this->required_grade_exec);
}

bool				Form::getSigned() const
{
	return (this->_signed);
}

void				Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->required_grade_sign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form::The Grade of Bureaucrat is Too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form::The Grade of Bureaucrat is Too Low");
}