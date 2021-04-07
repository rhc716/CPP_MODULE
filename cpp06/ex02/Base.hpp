/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:49:41 by hroh              #+#    #+#             */
/*   Updated: 2021/04/07 18:42:28 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <ctime>
# include <unistd.h>
# include <iostream>
# include <cstdlib>

class Base
{
public:
	virtual ~Base();
};

Base *generate(void);

#endif