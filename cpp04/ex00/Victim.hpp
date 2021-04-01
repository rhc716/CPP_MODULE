/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:02:55 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 16:59:58 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
protected:
	std::string name;
	Victim();
public:
	Victim(std::string const &name);
	Victim(Victim const &old_obj);
	virtual ~Victim();

	Victim				&operator=(Victim const &old_obj);
	std::string	const	&get_name();
	virtual void		getPolymorphed() const;
};

std::ostream &operator<<(std::ostream &out, Victim &victim);

#endif