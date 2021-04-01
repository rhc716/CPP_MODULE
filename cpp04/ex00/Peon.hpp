/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:02:17 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 16:54:59 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim
{
private:

public:
	Peon(std::string const &name);
	Peon(Peon const &old_obj);
	~Peon();

	Peon	&operator=(Peon const &old_obj);
	void	getPolymorphed() const;
};

#endif