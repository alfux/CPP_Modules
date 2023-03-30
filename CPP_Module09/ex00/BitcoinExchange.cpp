/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:33:36 by alfux             #+#    #+#             */
/*   Updated: 2023/03/30 05:50:53 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange(void)
{
	std::fstream	file("data.csv", std::fstream::in);
	std::string		line;
	size_t			len;

	if (!file.is_open())
		throw (Error("failed to open data.csv"));
	this->getLine(file, line);
	if (line.compare("date,exchange_rate"))
		throw (Error("corrupted data.csv"));
	for (this->getLine(file, line); !file.eof(); this->getLine(file, line))
	{
		len = line.find_first_of(",");
		if (len == std::string::npos)
			throw (Error("invalid syntax"));
		data.insert(std::pair<Date, double>(this->getDate(line.substr(
			0, len)), std::stod(line.substr(len + 1))));
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy): data(cpy.data) {}

BitcoinExchange::BitcoinExchange(std::string const &data_file)
{
	std::fstream	file(data_file, std::fstream::in);
	std::string		line;
	size_t			len;

	if (!file.is_open())
		throw (Error("failed to open file: " + data_file));
	this->getLine(file, line);
	if (this->checkHeader(line))
		throw (Error("data file: invalid header"));
	for (this->getLine(file, line); !file.eof(); this->getLine(file, line))
	{
		len = line.find_first_of("|");
		if (len == std::string::npos)
			throw (Error("invalid syntax"));
		data.insert(std::pair<Date, double>(this->getDate(line.substr(
			0, len)), this->checkValue(std::stod(line.substr(len + 1)))));
	}
	file.close();
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
	while (!is.eof() && (!str.size()
		|| str.find_first_not_of("\t\n\r\v\f ") == std::string::npos))
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

double	BitcoinExchange::checkValue(double val)
{
	if (val < 0 || val > 1000)
		throw (Error("invalid value"));
	return (val);
}

bool	BitcoinExchange::checkHeader(std::string &line)
{
	size_t	date;
	size_t	sep;
	size_t	value;

	if (!line.size())
		return (true);
	date = line.find("date");
	sep = line.find("|");
	value = line.find("value");
	if (date == std::string::npos || sep == std::string::npos
		|| value == std::string::npos || !(date < sep && sep < value))
		return (true);
	line.erase(date, 4);
	line.erase(sep, 1);
	line.erase(value, 5);
	if (line.find_first_not_of("\t\n\r\v\f ") != std::string::npos)
		return (true);
	return (false);
}
