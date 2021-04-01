/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:58:44 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 22:02:44 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
private:

public:
	SuperMutant();
	SuperMutant(SuperMutant const &old_obj);
	~SuperMutant();

	SuperMutant &operator=(SuperMutant const &old_obj);
	void takeDamage(int damage);
};
#endif