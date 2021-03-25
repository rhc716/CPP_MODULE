/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:21:46 by hroh              #+#    #+#             */
/*   Updated: 2021/03/25 16:26:31 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	PhoneBook	book;
	std::string cmd;

	while (1)
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Enter the command : ADD / SEARCH / EXIT" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			return (0);
		else if (cmd == "ADD")
			book.add_contact();
		else if (cmd == "SEARCH")
		{
			book.show_contacts_header();
			book.show_contact();
		}
	}
}
