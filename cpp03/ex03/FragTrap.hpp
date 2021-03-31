/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:48:57 by hroh              #+#    #+#             */
/*   Updated: 2021/03/31 20:47:17 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	
public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &old_obj);
	~FragTrap();
	FragTrap &operator=(const FragTrap &old_obj);

	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	unsigned int	skillAttack(std::string const &target, ClapTrap &target_obj);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	unsigned int	vaulthunter_dot_exe(std::string const &target);
};

#endif