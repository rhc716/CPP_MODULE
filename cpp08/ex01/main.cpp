/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:11:20 by hroh              #+#    #+#             */
/*   Updated: 2021/04/15 20:47:17 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span span_1(1);

	std::cout << "[Empty Vector]" << std::endl;
	try
	{
		std::cout << "span_1 <Shortest Span> : " << span_1.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	
	span_1.addNumber(1);
	std::cout << "[Full Vector]" << std::endl;
	try
	{
		span_1.addNumber(2);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << "[N : 1]" << std::endl;
	try
	{
		std::cout << "span_1 <Shortest Span> : " << span_1.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "span_1 <Longest Span> : " << span_1.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	

	Span span_2(3);
	span_2.addNumber(2147483647);
	span_2.addNumber(2147483605);
	span_2.addNumber(-2147483648);
	std::cout << "[N : 3]" << std::endl;
	std::cout << "span_2 <Shortest Span> : " << span_2.shortestSpan() << std::endl;
	std::cout << "span_2 <Longest Span> : " << span_2.longestSpan() << std::endl << std::endl;



	Span span_3(20000);
	std::vector<int> vec(20000, 0);
	vec[0] = -2147483648;
	vec[19999] = 2147483647;

	span_3.addNumber(vec.begin(), vec.end());
	std::cout << "[N : 20000]" << std::endl;
	std::cout << "span_3 <Shortest Span> : " << span_3.shortestSpan() << std::endl;
	std::cout << "span_3 <Longest Span> : " << span_3.longestSpan() << std::endl;
}
