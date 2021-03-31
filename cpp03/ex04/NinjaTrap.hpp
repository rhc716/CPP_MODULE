/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:53:09 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 01:03:53 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
protected:
	NinjaTrap();
	unsigned int	energy_copy;
	unsigned int	energy_max_copy;	
	unsigned int	melee_damage_copy;
public:
	NinjaTrap(const std::string &name);
	NinjaTrap(const NinjaTrap &old_obj);
	~NinjaTrap();
	NinjaTrap &operator=(const NinjaTrap &old_obj);

	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	unsigned int	skillAttack(std::string const &target, ClapTrap &target_obj);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			ninjaShoebox(ClapTrap &trap);
	void			ninjaShoebox(FragTrap &trap);
	void			ninjaShoebox(ScavTrap &trap);
	void			ninjaShoebox(NinjaTrap &trap);
};
#endif