/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:17:57 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 18:59:50 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
private:
	std::string name;
	int			required_grade_sign;
	int			required_grade_exec;
	bool		_signed;

public:
	Form(const std::string &name, int required_grade_sign, int required_grade_exec);
	Form(Form const &old_obj);
	~Form();
	Form &operator=(Form const &old_obj);

	const std::string	&getName() const;
	int					getGradeSign() const;
	int					getGradeExec() const;
	bool				getSigned() const;

	void				beSigned(Bureaucrat const &bureaucrat);
	
	class GradeTooHighException: public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, Form const &obj);

#endif