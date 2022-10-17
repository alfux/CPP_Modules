/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:40:47 by alfux             #+#    #+#             */
/*   Updated: 2022/10/17 07:17:59 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : n(0) {}

int	PhoneBook::add(void)
{
	Contact	buf;
	size_t	i;

	i = 0;
	while (i < MAX_CONTACT)
	{
		if (contacts[i].isempty())
		{
			if (contacts[i].fill())
				return (1);
			return ((0 * n++));
		}
		i++;
	}
	if (buf.fill())
		return (1);
	(void)contacts[0].clear();
	i = 0;
	while (i < MAX_CONTACT - 1)
	{
		contacts[i] = contacts[i + 1];
		i++;
	}
	contacts[MAX_CONTACT - 1] = buf;
	return (0);
}

int	PhoneBook::no_contact(void)
{
	std::cout << "\n    Phone book is empty\n\n";
	return (0);
}

int	PhoneBook::search(void)
{
	std::string choice;
	int			i;

	i = 0;
	if (!n)
		return (PhoneBook::no_contact());
	std::cout << "\n     Index|First Name| Last Name|  Nickname\n";
	while (i < n)
	{
		std::cout << std::setw(10) << std::setfill(' ');
		std::cout << std::setiosflags(std::ios::right) << i + 1;
		(void)contacts[i++].colones();
	}
	std::cout << "\nIndex: ";
	if (!std::getline(std::cin, choice) || choice.size() != 1
		|| choice.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cerr << "Error: syntax\n";
		return (1);
	}
	i = std::stoi(choice);
	if (i > 0 && i <= n)
		return (contacts[i - 1].show());
	std::cout << "No matches found\n";
	return (0);
}

PhoneBook::~PhoneBook(void) {}
