/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:27:08 by hroh              #+#    #+#             */
/*   Updated: 2021/03/25 11:39:57 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <limits>

class Contact
{
private:
	int					index;
	std::string			info[12];
	static std::string	field_names[12];
	enum Fields
	{
		FirstName,
		LastName,
		NickName,
		Login,
		Postal,
		Email,
		Address,
		PhoneNumber,
		Birthday,
		FavoriteMeal,
		UnderwearColor,
		DarkestSecret
	};
public:
	Contact(void);
	~Contact(void);

	bool set_info(int index);
	void show_info(void);
	void show_header(void);
};

#endif