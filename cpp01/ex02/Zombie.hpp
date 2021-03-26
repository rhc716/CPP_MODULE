/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:20:38 by hroh              #+#    #+#             */
/*   Updated: 2021/03/26 18:54:25 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
	std::string zombie_name;
	std::string zombie_type;

public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);
	void set_type(std::string type);
};

#endif