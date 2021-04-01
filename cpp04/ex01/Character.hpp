/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:34:02 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 22:08:10 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
	std::string name;
	int			ap;
	AWeapon		*weapon;

public:
	Character(std::string const & name);
	Character(Character const &old_obj);
	~Character();

	Character &operator=(Character const &old_obj);

	void recoverAP();
	void equip(AWeapon* weapon);
	void attack(Enemy* enemy);
	std::string const	&getName() const;
	int					getAp() const;
	AWeapon				*getWeapon() const;
};

std::ostream	&operator<<(std::ostream &out, Character const &ch);

#endif