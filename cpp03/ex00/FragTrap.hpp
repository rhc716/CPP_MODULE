/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:48:57 by hroh              #+#    #+#             */
/*   Updated: 2021/03/30 15:29:23 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <fstream>
# include <unistd.h>
# include <ctime>

# define DEFAULT	"\e[0;0m"
# define RED		"\e[0;31m"
# define GREEN		"\e[0;32m"
# define YELLOW		"\e[0;33m"
# define BLUE		"\e[0;94m"
# define PURPLE		"\e[0;35m"
# define CYAN		"\e[0;36m"
# define T_USLEEP	500000

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
public:
	FragTrap(const std::string &name);
	~FragTrap();

	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);
};

void		print_border();

#endif