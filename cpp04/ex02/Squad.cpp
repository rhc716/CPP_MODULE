/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:01:33 by hroh              #+#    #+#             */
/*   Updated: 2021/04/02 18:38:08 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() :
	count(0), units(NULL)
{
}

Squad::Squad(Squad const &old_obj) :
	count(0), units(NULL)
{
	for (int i = 0; i < old_obj.getCount(); i++)
		this->push(old_obj.getUnit(i)->clone());
}

Squad::~Squad()
{
	for (int i = 0; i < this->count; i++)
			delete (this->units[i]);
	delete[] (this->units);
}

Squad &Squad::operator=(Squad const &old_obj)
{
	if (this->units)
	{
		for (int i = 0; i < this->count; i++)
			delete (this->units[i]);
		delete[] (this->units);
		this->units = NULL;
	}
	for (int i = 0; i < old_obj.getCount(); i++)
		this->push(old_obj.getUnit(i)->clone());
	return (*this);
}

int 		Squad::getCount() const
{
	return (this->count);
}

ISpaceMarine* Squad::getUnit(int index) const
{
	if (index < 0 || index >= count)
		return (NULL);
	return (this->units[index]);
}

int 		Squad::push(ISpaceMarine *unit)
{
	if (!unit)
		return (this->count);
	if (this->units)
	{
		for (int i = 0; i < this->count; i++)
			if (this->units[i] == unit)
				return (this->count);
		ISpaceMarine **expand = new ISpaceMarine*[this->count + 1];
		for (int i = 0; i < this->count; i++)
			expand[i] = this->units[i];
		delete[] (this->units);
		this->units = expand;
		this->units[this->count] = unit;
		this->count++;
	}
	else
	{
		this->units = new ISpaceMarine*[1];
		this->units[0] = unit;
		this->count = 1;
	}
	return (this->count);
}
