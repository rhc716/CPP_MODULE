/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:48:16 by hroh              #+#    #+#             */
/*   Updated: 2021/03/27 00:27:44 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon		*weapon;

public:
	HumanA(std::string name);
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	attack(void);
	void	setWeapon(Weapon &weapon);
};

#endif