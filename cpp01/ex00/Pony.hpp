/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:07:26 by hroh              #+#    #+#             */
/*   Updated: 2021/03/26 17:23:46 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <ctime>
# include <iomanip>

class Pony
{
private:
	std::string birthday;

public:
	Pony(void);
	~Pony(void);

	std::string get_birthday(void);
};

#endif
