/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:36:49 by hroh              #+#    #+#             */
/*   Updated: 2021/03/31 21:25:15 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	
public:
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &old_obj, int mute);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &old_obj);

	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	unsigned int	skillAttack(std::string const &target, ClapTrap &target_obj);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			set_spec(unsigned int hp, int damage_adj, unsigned int armor);
	void			challengeNewcomer(ClapTrap &challenger);
	void			enemy_10_kill_challenges(ClapTrap &challenger);
	bool			fight_to_challenger(ClapTrap &challenger, ScavTrap &scarv);
	void			boss_kill_challenges(ClapTrap &challenger);
	void			append_name_nbr(int i);
};

#endif