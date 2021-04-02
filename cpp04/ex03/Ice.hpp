/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:23:47 by hroh              #+#    #+#             */
/*   Updated: 2021/04/02 21:50:20 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
private:

public:
	Ice();
	Ice(Ice const &old_obj);
	~Ice();

	Ice		&operator=(Ice const &old_obj);
	Ice		*clone() const;
	void	use(ICharacter& target);
};

#endif