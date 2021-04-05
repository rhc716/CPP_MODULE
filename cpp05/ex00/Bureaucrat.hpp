/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:20:53 by hroh              #+#    #+#             */
/*   Updated: 2021/04/05 17:34:22 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
private:
	std::string name;
	int			grade;

public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &old_obj);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &old_obj);
	std::string	const &getName() const;
	int			getGrade() const;
	void		increase_grade();
	void		decrease_grade();

	class GradeTooHighException: public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat obj);

#endif