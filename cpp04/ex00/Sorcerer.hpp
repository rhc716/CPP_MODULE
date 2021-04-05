/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:02:49 by hroh              #+#    #+#             */
/*   Updated: 2021/04/03 16:41:23 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
private:
	std::string name;
	std::string title;

public:
	Sorcerer(std::string const &name, std::string const &title);
	Sorcerer(Sorcerer const &old_obj);
	~Sorcerer();

	Sorcerer			&operator=(Sorcerer const &old_obj);
	void				polymorph(Victim const &victim) const;

	std::string const	&get_name();
	std::string const	&get_title();
};

std::ostream &operator<<(std::ostream &out, Sorcerer &sorcerer);

#endif