/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:18:21 by hroh              #+#    #+#             */
/*   Updated: 2021/04/07 14:58:30 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	count = 0;
};

PhoneBook::~PhoneBook(void)
{
};

void PhoneBook::add_contact(void)
{
	if (this->count < 8)
	{
		if (this->contacts[this->count].set_info(this->count + 1) == true)
			this->count++;
	}
	else
		std::cout << "Phonebook is full" << std::endl;
};

void PhoneBook::show_contacts_header(void)
{
	int max;

	max = this->count;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << std::left << "   index";
	std::cout << "|";
	std::cout << std::setw(10) << std::left << "first name";
	std::cout << "|";
	std::cout << std::setw(10) << std::left << "last name";
	std::cout << "|";
	std::cout << std::setw(10) << std::left << " nickname";
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < max; ++i)
		this->contacts[i].show_header();
	if (max == 0)
		std::cout << "               No information               " << std::endl;
	else
		std::cout << "---------------------------------------------" << std::endl;
};

void PhoneBook::show_contact(void)
{
	int index;
	int max;

	if (this->count == 0)
		return ;
	std::cout << "Enter the index of the contact" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "> ";
	std::cin >> index;
	max = this->count + 1;
	if (index > 0 && index < max)
		this->contacts[index - 1].show_info();
	else
		std::cout << "Invalid Index" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};
