/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:08:07 by alfux             #+#    #+#             */
/*   Updated: 2022/10/15 07:21:36 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	command;
	PhoneBook	book;

	(void)std::getline(std::cin, command);
	while (command.compare("EXIT"))
	{
		if (!command.compare("ADD"))
			book.add();
		else if (!command.compare("SEARCH"))
			book.search();
		(void)std::getline(std::cin, command);
	}
	return (0);
}
