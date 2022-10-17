/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:47:20 by alfux             #+#    #+#             */
/*   Updated: 2022/10/17 07:11:41 by alfux            ###   ########.fr       */
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

int	Contact::prntblk(std::string str)
{
	if (str.size() > 10)
	{
		str.resize(9);
		str.resize(10, '.');
	}
	std::cout << '|' << std::setw(10) << std::setfill(' ');
	std::cout << std::setiosflags(std::ios::right) << str;
	return (0);
}

int	Contact::fillblk(std::string pmt, std::string &str)
{
	std::cout << pmt;
	(void)std::getline(std::cin, str);
	if (Contact::isempty(str))
		return (1);
	return (0);
}

int	Contact::fillnum(std::string pmt, std::string &num)
{
	std::cout << pmt;
	(void)std::getline(std::cin, num);
	if (Contact::isempty(num))
		return (1);
	if (num.size() > 15)
		return (1);
	if (num.find_first_not_of("0123456789") != std::string::npos)
		return (1);
	return (0);
}

int	Contact::fill(void)
{
	Contact::clear();
	if (!Contact::fillblk("First name: ", frst))
		if (!Contact::fillblk("Last name: ", last))
			if (!Contact::fillblk("Nickname: ", nick))
				if (!Contact::fillnum("Phone number: ", numb))
					if (!Contact::fillblk("Darkest secret ... : ", dark))
						return (0);
	std::cerr << "Error: syntax" << std::endl;
	Contact::clear();
	return (1);
}

int	Contact::show(void)
{
	std::cout << "\nFirst name: " << frst << std::endl;
	std::cout << "Last name: " << last << std::endl;
	std::cout << "Nickname: " << nick << std::endl;
	std::cout << "Phone number: " << numb << std::endl;
	std::cout << "Darkest secret: " << dark << std::endl << std::endl;
	return (0);
}

int	Contact::colones(void)
{
	(void)Contact::prntblk(frst);
	(void)Contact::prntblk(last);
	(void)Contact::prntblk(nick);
	std::cout << "\n";
	return (0);
}

int	Contact::isempty(void)
{
	if (frst.empty())
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

Contact::~Contact(void) {}
