/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RStream.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:47:16 by alfux             #+#    #+#             */
/*   Updated: 2022/10/25 18:02:01 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RStream.hpp"

RStream::RStream(void) {}

void	RStream::open(std::string file_name)
{
	in.open(file_name.c_str(), std::fstream::in);
	if (!in.is_open())
	{
		std::cerr << "error: fail to open \"" << file_name << "\"" << std::endl;
		return ;
	}
	file_name += ".replace";
	out.open(file_name.c_str(), std::fstream::out);
}

void	RStream::replace(std::string s1, std::string s2)
{
	std::string	buf;
	std::size_t	i;

	while (in.is_open() && !in.eof() && s1.size() > 0)
	{
		while (str.size() < s1.size() && !in.eof())
		{
			(void)std::getline(in, buf);
			str += buf + '\n';
		}
		for (i = 0; i != std::string::npos; )
		{
			i = str.find(s1, 0);
			if (i == std::string::npos)
				out << str;
			else
			{
				out << str.substr(0, i) << s2;
				str.erase(0, i + s1.size());
			}
		}
		buf.clear();
		str.clear();
	}
}

RStream::~RStream(void) {}
