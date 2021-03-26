/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:41:53 by hroh              #+#    #+#             */
/*   Updated: 2021/03/27 00:27:35 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon		*weapon;

public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon &weapon);
	~HumanB(void);

	void	attack(void);
	void	setWeapon(Weapon &weapon);
};

#endif