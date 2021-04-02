/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:24:24 by hroh              #+#    #+#             */
/*   Updated: 2021/04/03 00:53:24 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->sources[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &old_obj)
{
	for (int i = 0; i < 4; i++)
	{
		this->sources[i] = NULL;
		if (old_obj.sources[i])
			this->sources[i] = old_obj.sources[i]->clone();
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->sources[i])
			delete this->sources[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &old_obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->sources[i])
		{
			delete this->sources[i];
			this->sources[i] = NULL;
		}
		if (old_obj.sources[i])
			this->sources[i] = old_obj.sources[i]->clone();
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->sources[i] == NULL)
		{
			this->sources[i] = m;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (this->sources[i] != NULL && this->sources[i]->getType() == type)
				return (this->sources[i]->clone());
	return (0);
}
