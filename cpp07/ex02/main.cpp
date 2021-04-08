/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:00:42 by hroh              #+#    #+#             */
/*   Updated: 2021/04/08 20:44:07 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> i_arr(2);
	Array<float> f_arr(2);
	Array<double> d_arr;
	Array<std::string> s_arr_1(2);
	Array<std::string> s_arr_2(2);



	std::cout << "i_arr size : " << i_arr.size() << std::endl;
	std::cout << "f_arr size : " << f_arr.size() << std::endl;
	std::cout << "d_arr size : " << d_arr.size() << std::endl;
	std::cout << "s_arr_1 size : " << s_arr_1.size() << std::endl;
	std::cout << "s_arr_2 size : " << s_arr_2.size() << "\n\n";



	i_arr[0] = 5;
	std::cout << "i_arr[0] : " << i_arr[0] << std::endl;
	f_arr[0] = 5.5;
	std::cout << "f_arr[0] : " << f_arr[0] << std::endl;
	try
	{
		std::cout << "d_arr[0] : " << d_arr[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	s_arr_1[0] = "abc";
	s_arr_1[1] = "123";
	std::cout << "s_arr_1[0] : " << s_arr_1[0] << std::endl;
	std::cout << "s_arr_1[1] : " << s_arr_1[1] << std::endl;
	try
	{
		std::cout << "s_arr_1[3] : " << s_arr_1[3] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;



	s_arr_2 = s_arr_1;
	std::cout << "s_arr_2[0] : " << s_arr_2[0] << std::endl;
	std::cout << "s_arr_2[1] : " << s_arr_2[1] << std::endl;
}