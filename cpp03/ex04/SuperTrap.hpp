/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:32:00 by hroh              #+#    #+#             */
/*   Updated: 2021/04/01 00:58:26 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
private:
	
public:
	SuperTrap(const std::string &name);
	SuperTrap(const SuperTrap &old_obj);
	~SuperTrap();
	SuperTrap &operator=(const SuperTrap &old_obj);
	
	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	unsigned int	skillAttack(std::string const &target, ClapTrap &target_obj);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};
#endif