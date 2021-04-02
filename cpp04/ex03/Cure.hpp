/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:21:04 by hroh              #+#    #+#             */
/*   Updated: 2021/04/02 20:42:03 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
private:

public:
	Cure();
	Cure(Cure const &old_obj);
	~Cure();

	Cure	&operator=(Cure const &old_obj);
	Cure	*clone() const;
	void	use(ICharacter& target);
};

#endif