/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:03:38 by hroh              #+#    #+#             */
/*   Updated: 2021/04/08 20:46:25 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
	T		*array;
	size_t	length;

public:
	Array();
	Array(size_t n);
	Array(Array const &old_obj);
	~Array();

	Array	&operator=(Array const &old_obj);
	T		&operator[](size_t i);

	size_t	size() const;

	class OutOfBoundsException: public std::exception {
		virtual const char* what() const throw()
		{ return "Index exceeded the range of the array"; }
	};
};

template <typename T>
Array<T>::Array() :
	array(new T[0]), length(0)
{
}

template <typename T>
Array<T>::Array(size_t n) :
	array(new T[n]), length(n)
{
}

template <typename T>
Array<T>::Array(Array const &old_obj) :
	length(old_obj.length)
{
	this->array = new T[this->length];
	for (size_t i = 0; i < this->length; ++i)
		this->array[i] = old_obj.array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &old_obj)
{
	if (this->length > 0)
		delete [] this->array;
	this->length = old_obj.length;
	this->array = new T[this->length];
	for (size_t i = 0; i < this->length; ++i)
		this->array[i] = old_obj.array[i];
	return (*this);
}

template <typename T>
T		&Array<T>::operator[](size_t i)
{
	if (i >= this->length)
		throw Array::OutOfBoundsException();
	return (this->array[i]);
}

template <typename T>
size_t Array<T>::size() const
{
	return (this->length);
}

#endif
