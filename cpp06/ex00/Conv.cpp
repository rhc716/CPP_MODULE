/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conv.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:06:12 by hroh              #+#    #+#             */
/*   Updated: 2021/04/07 02:47:18 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conv.hpp"

Conv::Conv(std::string const &str) :
	char_val(' '), int_val(0), float_val(0.0f)
{
	if (str.length() == 1 && std::isprint(str[0]) && (str[0] < 48 || str[0] > 57))
		this->double_val = static_cast<double>(str[0]);
	else
		this->double_val = atof(str.c_str());
	if (str[0] != '0' && this->double_val == 0.0)
		throw ImpossibleArgumentException();
}

Conv::Conv(Conv const &old_obj) :
	char_val(old_obj.char_val), int_val(old_obj.int_val), 
	float_val(old_obj.float_val), double_val(old_obj.double_val)
{
}

Conv::~Conv()
{
}

Conv &Conv::operator=(Conv const &old_obj)
{
	this->char_val = old_obj.char_val;
	this->int_val = old_obj.int_val;
	this->float_val = old_obj.float_val;
	this->double_val = old_obj.double_val;
	return (*this);
}

void	Conv::to_char()
{
	this->char_val = static_cast<char>(this->double_val);
	if (std::isinf(this->double_val) || std::isnan(this->double_val))
		throw ImpossibleException();
	else if (this->double_val < std::numeric_limits<char>::lowest() ||
			this->double_val > std::numeric_limits<char>::max())
		throw ImpossibleException();
	else if (this->char_val < 32 || this->char_val > 126)
		throw NonDisplayException();
}

void	Conv::to_int()
{
	this->int_val = static_cast<int>(this->double_val);
	if (std::isinf(this->double_val) || std::isnan(this->double_val))
		throw ImpossibleException();
	if (std::numeric_limits<int>::max() < this->double_val ||
		std::numeric_limits<int>::lowest() > this->double_val)
		throw ImpossibleException();
}

void	Conv::to_float()
{
	this->float_val = static_cast<float>(this->double_val);
}

void	Conv::scalar_print()
{
	long long temp;

	try
	{
		this->to_char();
		std::cout << "char: '" << this->char_val << "'" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "char: " << e.what() << std::endl;
	}
	try
	{
		this->to_int();
		std::cout << "int: " << this->int_val << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "int: " << e.what() << std::endl;
	}
	this->to_float();
	temp = static_cast<long long>(this->float_val);
	if (this->float_val - temp == 0.0f)
		std::cout << "float: " << this->float_val << ".0f" << std::endl;
	else
		std::cout << "float: " << this->float_val << "f" << std::endl;
	temp = static_cast<long long>(this->double_val);
	if (this->double_val - temp == 0.0)
		std::cout << "double: " << this->double_val << ".0" << std::endl;
	else
		std::cout << "double: " << this->double_val << std::endl;
}

const char* Conv::NonDisplayException::what() const throw()
{
	return ("Non displayable");
}

const char* Conv::ImpossibleException::what() const throw()
{
	return ("impossible");
}

const char* Conv::ImpossibleArgumentException::what() const throw()
{
	return ("Not the correct argument.\n=== Possible literal arguments ===\nchar / int / float / double");
}