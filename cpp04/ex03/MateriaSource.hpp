/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:22:15 by hroh              #+#    #+#             */
/*   Updated: 2021/04/02 22:52:52 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *sources[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &old_obj);
	~MateriaSource();

	MateriaSource &operator=(MateriaSource const &old_obj);
	void		learnMateria(AMateria *m);
	AMateria	*createMateria(std::string const &type);
};

#endif