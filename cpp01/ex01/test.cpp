/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:22:02 by hroh              #+#    #+#             */
/*   Updated: 2021/03/27 20:23:56 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int		main()
{
	memoryLeak();
	system("echo \"\n===== leak check =====\n\"; leaks a.out | grep leaked");
	return (0);
}