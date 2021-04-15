/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:17:05 by hroh              #+#    #+#             */
/*   Updated: 2021/04/15 20:42:40 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) :
	limit_size(n)
{
}

Span::Span(Span const &old_obj) :
	limit_size(old_obj.limit_size), numbers(old_obj.numbers)
{
}

Span::~Span()
{
}

Span &Span::operator=(Span const &old_obj)
{
	this->limit_size = old_obj.limit_size;
	this->numbers = old_obj.numbers;
	return (*this);
}

void			Span::addNumber(int nbr)
{
	if (this->numbers.size() < this->limit_size)
		this->numbers.push_back(nbr);
	else
		throw StorageFullException();
}

unsigned int	Span::shortestSpan()
{
	unsigned int span;
	unsigned int temp;

	if (this->numbers.size() < 2)
		throw LackException();
	span = std::abs(this->numbers[0] - this->numbers[1]);
	for (size_t i = 1; i < this->numbers.size() - 1; ++i)
		if ((temp = std::abs(this->numbers[i] - this->numbers[i + 1])) < span)
			span = temp;
	return (span);
}

unsigned int	Span::longestSpan()
{
	unsigned int span;

	if (this->numbers.size() < 2)
		throw LackException();
	span = *std::max_element(this->numbers.begin(), this->numbers.end())
			- *std::min_element(this->numbers.begin(), this->numbers.end());
	return (span);
}
