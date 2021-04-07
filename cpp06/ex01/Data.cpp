/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:37:50 by hroh              #+#    #+#             */
/*   Updated: 2021/04/07 18:44:23 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	get_random_int()
{
	if (std::rand() % 2 == 0)
		return (std::numeric_limits<int>::min() + std::rand());
	else
		return (std::rand());
}

void *serialize(void)
{
	static const char alnum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
	char *ret = new char[20];

	for (int i = 0; i < 8; ++i)
        ret[i] += alnum[std::rand() % (sizeof(alnum) - 1)];
	*reinterpret_cast<int*>(ret + 8) = get_random_int();
	for (int i = 0; i < 8; ++i)
        ret[i + 12] += alnum[std::rand() % (sizeof(alnum) - 1)];
	return (ret);
}

Data *deserialize(void *raw)
{
	Data *ret = new Data();

	ret->s1 = std::string(reinterpret_cast<char*>(raw), 8);
	ret->n = *reinterpret_cast<int*>(reinterpret_cast<char*>(raw) + 8);
	ret->s2 = std::string(reinterpret_cast<char*>(raw) + 12, 8);
	return (ret);
}
