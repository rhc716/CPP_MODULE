/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:38:27 by hroh              #+#    #+#             */
/*   Updated: 2021/03/31 19:51:38 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <fstream>
# include <unistd.h>
# include <string>
# include <sstream>
# include <ctime>
# include <iomanip>

# define DEFAULT	"\e[0;0m"
# define RED		"\e[0;31m"
# define GREEN		"\e[0;92m"
# define GREY		"\e[0;2m"
# define YELLOW		"\e[0;33m"
# define BLUE		"\e[0;94m"
# define PURPLE		"\e[0;35m"
# define CYAN		"\e[0;36m"
# define T_USLEEP	100000

# define CLAPTRAP	0
# define FRAGTRAP	1
# define SCARVTRAP	2

class ClapTrap
{
protected:
	std::string		name;
	unsigned int	level;
	unsigned int	hp;
	unsigned int	hp_max;
	unsigned int	energy;
	unsigned int	energy_max;	
	unsigned int	melee_damage;
	unsigned int	range_damage;
	unsigned int	armor;
	ClapTrap();
public:
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &old_obj);
	virtual ~ClapTrap();
	ClapTrap &operator=(const ClapTrap &old_obj);

	virtual void			rangedAttack(std::string const &target);
	virtual void			meleeAttack(std::string const &target);
	virtual unsigned int	skillAttack(std::string const &target, ClapTrap &target_obj);
	virtual void			takeDamage(unsigned int amount);
	virtual void			beRepaired(unsigned int amount);
	void					restoreEnergy(unsigned int amount);
		
	std::string				&get_name();
	unsigned int			get_hp();
	unsigned int			get_melee_damage();
	unsigned int			get_range_damage();
};

void		print_border(unsigned int type_of_trap);

#endif