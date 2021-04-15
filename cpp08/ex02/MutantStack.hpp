/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:43:27 by hroh              #+#    #+#             */
/*   Updated: 2021/04/15 19:59:51 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
private:

public:
	MutantStack();
	MutantStack(MutantStack<T> const &old_obj);
	~MutantStack();
	MutantStack<T> &operator=(MutantStack<T> const &old_obj);

	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	iterator				begin(void);
	iterator				end(void);
	
	const_iterator			begin(void) const;
	const_iterator			end(void) const;
	
	reverse_iterator		rbegin(void);
	reverse_iterator		rend(void);
	
	const_reverse_iterator	rbegin(void) const;
	const_reverse_iterator	rend(void) const;
};

template<typename T>
MutantStack<T>::MutantStack() :
	std::stack<T>::stack()
{
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &old_obj) :
	std::stack<T>::stack(old_obj)
{
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &old_obj)
{
	std::stack<T>::operator=(old_obj);
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator				MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator				MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator			MutantStack<T>::begin(void) const
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator			MutantStack<T>::end(void) const
{
	return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::reverse_iterator		MutantStack<T>::rbegin(void)
{
	return (std::stack<T>::c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator		MutantStack<T>::rend(void)
{
	return (std::stack<T>::c.rend());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin(void) const
{
	return (std::stack<T>::c.rbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend(void) const
{
	return (std::stack<T>::c.rend());
}

#endif