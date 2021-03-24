/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:18:10 by hroh              #+#    #+#             */
/*   Updated: 2021/03/24 21:28:38 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "contact.hpp"

class PhoneBook
{
private:
	Contact		contacts[8];
	int			count;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void add_contact(void);
	void show_contacts_header(void);
	void show_contact(void);
};

#endif
