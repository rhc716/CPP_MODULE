/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:22:39 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 22:02:08 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
private:

public:
	PowerFist();
	PowerFist(PowerFist const &old_obj);
	~PowerFist();

	PowerFist &operator=(PowerFist const &old_obj);

	void attack() const;
};
#endif