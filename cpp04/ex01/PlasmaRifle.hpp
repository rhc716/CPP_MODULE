/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:22:47 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 22:01:36 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
private:

public:
	PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &old_obj);
	~PlasmaRifle();

	PlasmaRifle &operator=(PlasmaRifle const &old_obj);

	void attack() const;
};
#endif