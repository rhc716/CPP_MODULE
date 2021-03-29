/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:33:55 by hroh              #+#    #+#             */
/*   Updated: 2021/03/29 20:42:18 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
}

Human::~Human(void)
{
}

std::string Human::identify(void)
{
	return (this->brain.identify());
};

Brain		&Human::getBrain(void)
{
	return (this->brain);
};
