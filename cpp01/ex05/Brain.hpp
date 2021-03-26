/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:33:53 by hroh              #+#    #+#             */
/*   Updated: 2021/03/26 22:02:57 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <sstream>
#include <string>

class Brain
{
private:
	
public:
	Brain(void);
	~Brain(void);

	std::string identify(void);
};

#endif