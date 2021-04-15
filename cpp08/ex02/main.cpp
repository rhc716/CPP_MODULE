/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:33:11 by hroh              #+#    #+#             */
/*   Updated: 2021/04/15 20:51:56 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	for (int i = 0; i < 10; ++i)
		mstack.push(i + 1);
	while (!mstack.empty())
	{
		std::cout << "top : " << mstack.top() << ", size : " << mstack.size() << std::endl;
		mstack.pop();
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; ++i)
		mstack.push(i + 1);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "*iterator : " << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	MutantStack<int>::reverse_iterator r_it = mstack.rbegin();
	MutantStack<int>::reverse_iterator r_ite = mstack.rend();
	++r_it;
	--r_it;
	while (r_it != r_ite)
	{
		std::cout << "*reverse_iterator : " << *r_it << std::endl;
		++r_it;
	}
	std::cout << std::endl;

	MutantStack<int>::const_iterator c_it = mstack.begin();
	MutantStack<int>::const_iterator c_ite = mstack.end();
	++c_it;
	--c_it;
	while (c_it != c_ite)
	{
		std::cout << "*const_iterator : " << *c_it << std::endl;
		++c_it;
	}
	std::cout << std::endl;

	MutantStack<int>::const_reverse_iterator cr_it = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator cr_ite = mstack.rend();
	++cr_it;
	--cr_it;
	while (cr_it != cr_ite)
	{
		std::cout << "*const_reverse_iterator : " << *cr_it << std::endl;
		++cr_it;
	}
	std::cout << std::endl;

	std::cout << "Stack copy" << std::endl;
	std::stack<int> copy_s(mstack);
	while (!copy_s.empty())
	{
		std::cout << "top : " << copy_s.top() << ", size : " << copy_s.size() << std::endl;
		copy_s.pop();
	}
	return 0;
}