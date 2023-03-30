/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:33:36 by alfux             #+#    #+#             */
/*   Updated: 2023/03/30 04:18:22 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy): data(cpy.data) {}

BitcoinExchange::BitcoinExchange(std::string const &data_file)
{
	std::fstream	file(data_file, std::fstream::in);
	std::string		line;
	size_t			len;

	if (!file.is_open())
		throw (Error("failed to open file"));
	this->getLine(file, line);
	if (line.compare("date,exchange_rate"))
		throw (Error("corrupted data base"));
	for (this->getLine(file, line); !file.eof(); this->getLine(file, line))
	{
		len = line.find_first_of(",");
		data.insert(std::pair<Date, double>(this->getDate(line.substr(
			0, len)), std::stod(line.substr(len + 1))));
	}
	file.close();
	for (std::map<Date, double>::iterator it = data.begin(); it != data.end(); ++it)
		std::cout << it->first << " " << it->second << std::endl;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &cpy)
{
	this->data = cpy.data;
	return (*this);
}

std::istream	&BitcoinExchange::getLine(std::istream &is, std::string &str)
{
	std::getline(is, str);
	while (!is.eof() && !str.size())
		std::getline(is, str);
	return (is);
}

Date	BitcoinExchange::getDate(std::string date)
{
	Date	num;
	size_t	len;

	len = date.find_first_not_of("\t\n\r\v\f ");
	date.erase(0, len);
	len = date.find_first_not_of("0123456789");
	if (!len || date[len] != '-')
		throw (Error("invalid syntax"));
	num.setYear(std::stoi(date.substr(0, len)));
	date.erase(0, len + 1);
	len = date.find_first_not_of("0123456789");
	if (!len || date[len] != '-')
		throw (Error("invalid syntax"));
	num.setMonth(std::stoi(date.substr(0, len)));
	date.erase(0, len + 1);
	len = date.find_first_not_of("0123456789");
	if (!len || date.find_first_not_of("\t\n\r\v\f ", len) != std::string::npos)
		throw (Error("invalid syntax"));
	num.setDay(std::stoi(date.substr(0, len)));
	return (num);
}
