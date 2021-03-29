/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:33:58 by hroh              #+#    #+#             */
/*   Updated: 2021/03/29 20:42:05 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"

class Human
{
private:
	Brain brain;

public:
	Human(void);
	~Human(void);

	std::string identify(void);
	Brain		&getBrain(void);
};



#endif