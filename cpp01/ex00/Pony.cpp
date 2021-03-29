/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:11:01 by hroh              #+#    #+#             */
/*   Updated: 2021/03/29 20:59:40 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(void)
{
	time_t temp;
    struct tm* timeinfo;
	std::ostringstream str;

	std::cout << "Pony Constructor" << std::endl;
	time(&temp);
    timeinfo = localtime(&temp);
	str << std::to_string(timeinfo->tm_year + 1900) << "/";
	str << std::setw(2) << std::setfill('0') << std::to_string(timeinfo->tm_mon + 1);
	str << "/" << std::setw(2) << std::to_string(timeinfo->tm_mday);
	this->birthday = str.str();
}

Pony::~Pony(void)
{
	std::cout << "Pony Destructor" << std::endl;
}

std::string Pony::get_birthday(void)
{
	return (this->birthday);
}