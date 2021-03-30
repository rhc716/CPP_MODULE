/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:36:49 by hroh              #+#    #+#             */
/*   Updated: 2021/03/30 21:56:46 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "FragTrap.hpp"

class ScavTrap
{
private:
	std::string		name;
	unsigned int	level;
	unsigned int	hp;
	unsigned int	hp_max;
	unsigned int	energy;
	unsigned int	energy_max;	
	unsigned int	melee_damage;
	unsigned int	range_damage;
	unsigned int	armor;
public:
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &old_obj, int mute);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &old_obj);
	
	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			set_spec(unsigned int hp, int damage_adj, unsigned int armor);
	void			challengeNewcomer(FragTrap &challenger);
	void			enemy_10_kill_challenges(FragTrap &challenger);
	bool			enemy_fight_to_challenger(FragTrap &challenger, ScavTrap &scarv);
	void			boss_kill_challenges(FragTrap &challenger);
	void			append_name_nbr(int i);
};

#endif