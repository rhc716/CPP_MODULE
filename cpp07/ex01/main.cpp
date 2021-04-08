/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:49:12 by hroh              #+#    #+#             */
/*   Updated: 2021/04/08 20:05:11 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void ft_cout(T arg)
{
	std::cout << arg << std::endl;
}

int main()
{
	int			i_arr[5] = {1, 2, 3, 4, 5};
	float		f_arr[5] = {1.1f, 2.1f, 3.1f, 4.1f, 5.1f};
	std::string	s_arr[5] = {"123", "asd", "@_@", "+_+", "o_o"};

	iter<int>(i_arr, 5, &ft_cout);
	iter(i_arr, 5, &ft_cout);
	std::cout << std::endl;
	iter<float>(f_arr, 5, &ft_cout);
	iter(f_arr, 5, &ft_cout);
	std::cout << std::endl;
	iter<std::string>(s_arr, 5, &ft_cout);
	iter(s_arr, 5, &ft_cout);
}
