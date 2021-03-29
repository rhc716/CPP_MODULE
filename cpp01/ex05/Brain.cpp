/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:33:50 by hroh              #+#    #+#             */
/*   Updated: 2021/03/29 20:37:05 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	this->cell = 42;
}

Brain::~Brain(void)
{
}

std::string Brain::identify(void)
{
	std::stringstream ss;

	ss << "0x" << std::uppercase << std::hex << (uintptr_t)this;
	return (ss.str());
};
