/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:01:34 by hroh              #+#    #+#             */
/*   Updated: 2021/03/26 21:32:41 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*ptr = &str;
	std::string	&ref = str;
	std::cout << "string : " << str << std::endl;
	std::cout << "*pointer : " << *ptr << std::endl;
	std::cout << "reference : " << ref << std::endl;
}
