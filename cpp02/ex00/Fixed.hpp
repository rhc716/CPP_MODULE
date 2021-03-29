/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:30:56 by hroh              #+#    #+#             */
/*   Updated: 2021/03/29 22:35:45 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int value;
	static const int frac_bits = 8;

public:
	Fixed();
	Fixed(const Fixed &old_obj);
	~Fixed();

	Fixed	&operator=(const Fixed &old_obj);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif