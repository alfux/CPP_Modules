/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:47:20 by alfux             #+#    #+#             */
/*   Updated: 2022/10/15 06:30:36 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"

Contact::Contact(void) {}

int	Contact::isempty(std::string &str)
{
	size_t	i;

	i = 0;
	while (std::isspace(str[i]))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int	Contact::clear(void)
{
	if (!frst.empty())
		frst.clear();
	if (!last.empty())
		last.clear();
	if (!nick.empty())
		nick.clear();
	if (!dark.empty())
		dark.clear();
	return (0);
}

int	Contact::fill(void)
{
	Contact::clear();
	std::cout << "First name: > ";
	(void)std::getline(std::cin, frst);
	if (!Contact::isempty(frst))
	{
		std::cout << "Last name: > ";
		(void)std::getline(std::cin, last);
		if (!Contact::isempty(last))
		{
			std::cout << "Nickname: > ";
			(void)std::getline(std::cin, nick);
			if (!Contact::isempty(nick))
			{
				std::cout << "Darkest secret ... :> ";
				(void)std::getline(std::cin, dark);
				if (!Contact::isempty(dark))
					return (0);
			}
		}
	}
	std::cerr << "Error: empty field" << std::endl;
	Contact::clear();
	return (1);
}

int	Contact::show(void)
{
	std::cout << "First name: " << frst << std::endl;
	std::cout << "Last name: " << last << std::endl;
	std::cout << "Nickname: " << nick << std::endl;
	std::cout << "Darkest secret: " << dark << std::endl;
	return (0);
}

int	Contact::isempty(void)
{
	if (frst.empty())
		return (1);
	return (0);
}

Contact::~Contact(void) {}
