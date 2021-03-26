/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:41:21 by hroh              #+#    #+#             */
/*   Updated: 2021/03/26 23:54:14 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
	std::string weapon_type;

public:
	Weapon(std::string type);
	~Weapon(void);

	void				setType(std::string type);
	const std::string	&getType(void);
};

#endif