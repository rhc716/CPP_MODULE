/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:18:14 by hroh              #+#    #+#             */
/*   Updated: 2021/04/02 22:59:54 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria
{
private:
	std::string		_type;
	unsigned int	_xp;

public:
	AMateria(std::string const &type);
	AMateria(AMateria const &old_obj);
	virtual ~AMateria();
	AMateria &operator=(AMateria const &old_obj);
	std::string const	&getType() const;
	unsigned int		getXP() const;
	virtual AMateria	*clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif