/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:25:58 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 22:02:40 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
private:

public:
	RadScorpion();
	RadScorpion(RadScorpion const &old_obj);
	~RadScorpion();

	RadScorpion &operator=(RadScorpion const &old_obj);
};
#endif