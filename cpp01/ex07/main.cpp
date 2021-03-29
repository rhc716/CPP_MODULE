/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 00:34:46 by hroh              #+#    #+#             */
/*   Updated: 2021/03/29 20:33:07 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void	io_filestream_open(std::ifstream &ifs, std::ofstream &ofs, const std::string &file_name)
{
	ifs.open(file_name);
	if (ifs.is_open() == false)
		throw "Input File cannot be opened";
	ofs.open(file_name + ".replace", std::ios::out | std::ios::trunc);
	if (ofs.is_open() == false)
	{
		ifs.close();
		throw "Output File cannot be opened";
	}
}

void	replace_line(std::string &line, const std::string &find, const std::string &replace)
{
	size_t	pos;

	while ((pos = line.find(find, 0)) != std::string::npos)
		line.replace(pos, find.length(), replace);
}

void	replace(const std::string &file_name, const std::string &find, const std::string &replace)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		buf;

	io_filestream_open(ifs, ofs, file_name);
	while (std::getline(ifs, buf))
	{
		replace_line(buf, find, replace);
		ofs << buf;
		if (ifs.eof())
			break ;
		ofs << std::endl;
	}
	ifs.close();
	ofs.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Arguments Error!!"
					<< "\n1. File Name"
					<< "\n2. Find String"
					<< "\n3. Replace String" << std::endl;
	}
	else
	{
		try
		{
			replace(argv[1], argv[2], argv[3]);
		}
		catch (const char *err_msg)
		{
			std::cerr << err_msg << std::endl;
		}
	}
}
