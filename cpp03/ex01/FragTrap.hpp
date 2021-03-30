/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:48:57 by hroh              #+#    #+#             */
/*   Updated: 2021/03/30 22:52:47 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

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
# define T_USLEEP	300000

# define FRAGTRAP	1
# define SCARVTRAP	2

class FragTrap
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
	unsigned int	kill_count;
public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &old_obj);
	~FragTrap();
	FragTrap &operator=(const FragTrap &old_obj);

	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			restoreEnergy(unsigned int amount);
	unsigned int	vaulthunter_dot_exe(std::string const &target);
	unsigned int	get_hp();
	std::string		&get_name();
	unsigned int	get_melee_damage();
	unsigned int	get_range_damage();
	unsigned int	set_kill_count();
};

void		print_border(unsigned int type_of_trap);

#endif