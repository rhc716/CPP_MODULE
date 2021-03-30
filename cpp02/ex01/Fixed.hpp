/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:30:56 by hroh              #+#    #+#             */
/*   Updated: 2021/03/30 10:50:46 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int value;
	static const int frac_bits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &old_obj);
	Fixed(const int i);
	Fixed(const float f);
	~Fixed(void);

	Fixed 		&operator=(const Fixed &old_obj);
	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	float		toFloat(void) const;
	int			toInt(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &obj);

#endif