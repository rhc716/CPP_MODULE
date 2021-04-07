/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:59:29 by hroh              #+#    #+#             */
/*   Updated: 2021/04/07 17:28:03 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main()
{
	void *raw;
	Data *data;

	std::srand(std::time(NULL) * getpid());
	raw = serialize();
	data = deserialize(raw);
	std::cout << "data s1\t: " << data->s1 << std::endl;
	std::cout << "data n\t: " << data->n << std::endl;
	std::cout << "data s2\t: " << data->s2 << std::endl;

	delete[] reinterpret_cast<char*>(raw);
	delete data;
	return (0);
}
