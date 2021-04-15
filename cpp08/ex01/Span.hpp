/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:03:27 by hroh              #+#    #+#             */
/*   Updated: 2021/04/15 20:46:14 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
private:
	unsigned int		limit_size;
	std::vector<int>	numbers;

public:
	Span(unsigned int n);
	Span(Span const &old_obj);
	~Span();
	Span &operator=(Span const &old_obj);


	void			addNumber(int nbr);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	class StorageFullException: public std::exception {
		const char* what() const throw() { return ("Your storage is full"); }
	};
	class LackException: public std::exception {
		const char* what() const throw() { return ("Need to store more than 2 numbers"); }
	};
	class RangeLimitException: public std::exception {
		const char* what() const throw() { return ("Range is greater than the limit"); }
	};

	template <typename Iter>
	void	addNumber(Iter begin, Iter end)
	{
		if (this->numbers.size() + std::distance(begin, end) <= this->limit_size)
			this->numbers.insert(this->numbers.end(), begin, end);
		else
			throw RangeLimitException();
	}
};

#endif