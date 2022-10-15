/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:40:47 by alfux             #+#    #+#             */
/*   Updated: 2022/10/15 07:37:35 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}

int	PhoneBook::add(void)
{
	Contact	buf;
	size_t	i;

	i = 0;
	while (i < MAX_CONTACT)
	{
		if (contacts[i].isempty())
			return (contacts[i].fill());
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

int	PhoneBook::search(void)
{
	size_t	i;

	i = 0;
	while (i < MAX_CONTACT)
		contacts[i++].show();
	return (0);
}

PhoneBook::~PhoneBook(void) {}
