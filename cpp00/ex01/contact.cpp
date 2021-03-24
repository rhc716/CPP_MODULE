/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:55:38 by hroh              #+#    #+#             */
/*   Updated: 2021/03/25 00:43:12 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact()
{
	field_names[0] = "First Name";
	field_names[1] = "Last Name";
	field_names[2] = "Nick Name";
	field_names[3] = "Login";
	field_names[4] = "Postal";
	field_names[5] = "Email";
	field_names[6] = "Address";
	field_names[7] = "Phone Number";
	field_names[8] = "Birthday";
	field_names[9] = "Favorite Meal";
	field_names[10] = "Underwear Color";
	field_names[11] = "Darkest Secret";
};

Contact::~Contact()
{
};

bool Contact::set_info(int index)
{
	int name_len_sum;

	this->index = index;
	name_len_sum = 0;
	for (int i = 0; i <= DarkestSecret; i++)
	{
		std::cout << field_names[i] << " : ";
		std::getline(std::cin, info[i]);
		if (i >= FirstName && i <= NickName)
			name_len_sum += info[i].length();
		if (i == NickName && name_len_sum == 0)
		{
			std::cout << "You must enter your Name or Nick Name" << std::endl;
			return (false);
		}
	}
	return (true);
};

void Contact::show_info(void)
{
	for (int i = 0; i <= DarkestSecret; i++)
		std::cout << field_names[i] << " : " << info[i] << std::endl;
};

void Contact::show_header(void)
{
	std::cout << "|";
	std::cout << std::setw(10) << std::right << index;
	for (int i = FirstName; i <= NickName; i++)
	{
		std::cout << "|";
		if (info[i].length() > 10)
			std::cout << std::right << info[i].substr(0, 9) << '.';
		else
			std::cout << std::setw(10) << std::right << info[i];
	}
	std::cout << "|" << std::endl;
};
