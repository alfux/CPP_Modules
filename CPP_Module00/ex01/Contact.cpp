/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:47:20 by alfux             #+#    #+#             */
/*   Updated: 2022/10/14 20:16:44 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"

Contact::Contact() {}

int	Contact::isempty(std::string &str)
{
	size_t	i;

	i = 0;
	while (std::isspace(str[i]))
		i++;
	if (!str[i])
		return (0);
	return (1);
}

void	Contact::fill()
{
	std::cout << "First name: > ";
	(void)std::getline(std::cin, frst);
	if (Contact::isempty(frst))
	{
		std::cout << "Last name: > ";
		(void)std::getline(std::cin, last);
		if (Contact::isempty(last))
		{
			std::cout << "Nickname: > ";
			(void)std::getline(std::cin, nick);
			if (Contact::isempty(nick))
			{
				std::cout << "Darkest secret ... :> ";
				(void)std::getline(std::cin, dark);
				if (Contact::isempty(dark))
					return ;
			}
		}
	}
	std::cerr << "Error: empty field" << std::endl;
}

void	Contact::show()
{
	std::cout << "First name: " << frst << std::endl;
	std::cout << "Last name: " << last << std::endl;
	std::cout << "Nickname: " << nick << std::endl;
	std::cout << "Darkest secret: " << dark << std::endl;
}

Contact::~Contact() {}
