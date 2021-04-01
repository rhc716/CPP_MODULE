/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:04:11 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 21:03:30 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
private:
	int hp;
	std::string type;
	Enemy();
public:
	Enemy(int hp, std::string const &type);
	Enemy(Enemy const &old_obj);
	virtual ~Enemy();

	Enemy &operator=(Enemy const &old_obj);
	
	std::string const &getType() const;
	int					getHP() const;
	virtual void 		takeDamage(int damage);
};

#endif