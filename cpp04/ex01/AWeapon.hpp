/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:06:31 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 20:20:08 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{
private:
	std::string	name;
	int			damage;
	int			apcost;
	AWeapon();
public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &old_obj);
	virtual ~AWeapon();

	AWeapon				&operator=(AWeapon const &old_obj);

	std::string const 	&getName() const;
	int					getAPCost() const;
	int					getDamage() const;

	virtual void		attack() const = 0;
};

#endif