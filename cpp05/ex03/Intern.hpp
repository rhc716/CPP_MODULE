/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:04:41 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 21:06:22 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:

public:
	Intern();
	Intern(Intern const &old_obj);
	~Intern();

	Intern &operator=(Intern const &old_obj);
	
	Form *makeForm(std::string const &formName, std::string const &target) const;
};
#endif