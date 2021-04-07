/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conv.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:04:32 by hroh              #+#    #+#             */
/*   Updated: 2021/04/07 18:42:18 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_HPP
# define CONV_HPP

# include <iostream>
# include <limits>
# include <cmath>
# include <cstdlib>

class Conv
{
private:
	char	char_val;
	int		int_val;
	float	float_val;
	double	double_val;
	
public:
	Conv(std::string const &str);
	Conv(Conv const &old_obj);
	~Conv();
	Conv &operator=(Conv const &old_obj);

	void	to_char();
	void	to_int();
	void	to_float();

	void	scalar_print();

	class NonDisplayException: public std::exception {
		const char* what() const throw();
	};
	class ImpossibleException: public std::exception {
		const char* what() const throw();
	};
	class ImpossibleArgumentException: public std::exception {
		const char* what() const throw();
	};
};

#endif
	