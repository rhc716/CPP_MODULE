/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:56:55 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 20:23:19 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	Form("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &old_obj) :
	Form(old_obj), target(old_obj.target)
{	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &old_obj)
{
	Form::operator=(old_obj);
	this->target = old_obj.target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::string file_name = (this->target + "_shrubbery");
	std::ofstream ofs(file_name, std::ios::out | std::ios::app);

	if (!ofs.is_open() || ofs.bad())
		throw "The file cannot be opened";
	ofs << "      /\\      " << std::endl;
	ofs << "     /\\*\\     " << std::endl;
	ofs << "    /\\O\\*\\    " << std::endl;
	ofs << "   /*/\\/\\/\\   " << std::endl;
	ofs << "  /\\O\\/\\*\\/\\  " << std::endl;
	ofs << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	ofs << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	ofs << "      ||      " << std::endl;
	ofs << "      ||      " << std::endl;
	ofs << "      ||      " << std::endl;
	ofs.close();
}
