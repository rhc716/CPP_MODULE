/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:55:38 by hroh              #+#    #+#             */
/*   Updated: 2021/03/25 11:55:04 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact()
{
};

Contact::~Contact()
{
};

std::string	Contact::field_names[12] =
{
	"First Name",
	"Last Name",
	"Nick Name",
	"Login",
	"Postal",
	"Email",
	"Address",
	"Phone Number",
	"Birthday",
	"Favorite Meal",
	"Underwear Color",
	"Darkest Secret"
};

bool Contact::set_info(int index)
{
	int name_len_sum;

	this->index = index;
	name_len_sum = 0;
	for (int i = 0; i <= DarkestSecret; i++)
	{
		std::cout << Contact::field_names[i] << " : ";
		std::getline(std::cin, info[i]);
		if (i >= FirstName && i <= NickName)
			name_len_sum += this->info[i].length();
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
		std::cout << Contact::field_names[i] << " : " << this->info[i] << std::endl;
};

void Contact::show_header(void)
{
	std::cout << "|";
	std::cout << std::setw(10) << std::right << index;
	for (int i = FirstName; i <= NickName; i++)
	{
		std::cout << "|";
		if (info[i].length() > 10)
			std::cout << std::right << this->info[i].substr(0, 9) << '.';
		else
			std::cout << std::setw(10) << std::right << this->info[i];
	}
	std::cout << "|" << std::endl;
};
