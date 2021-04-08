/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:46:56 by hroh              #+#    #+#             */
/*   Updated: 2021/04/08 18:36:18 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T		min(T a, T b)
{
	return (a <= b ? a : b);
}

template <typename T>
T		max(T a, T b)
{
	return (a >= b ? a : b);
}

#endif