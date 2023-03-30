/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:33:36 by alfux             #+#    #+#             */
/*   Updated: 2023/03/30 09:25:11 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange(void)
{
	std::fstream	file("data.csv", std::fstream::in);
	std::string		line;
	size_t			len;

	if (!file.is_open())
		throw (Error("failed to open data.csv."));
	this->getLine(file, line);
	if (line.compare("date,exchange_rate"))
		throw (Error("corrupted data.csv."));
	for (this->getLine(file, line); !file.eof(); this->getLine(file, line))
	{
		len = line.find_first_of(",");
		if (len == std::string::npos)
			throw (Error("invalid syntax."));
		data.insert(std::pair<Date, double>(this->getDate(line.substr(
			0, len)), std::stod(line.substr(len + 1))));
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy): data(cpy.data) {}

BitcoinExchange::BitcoinExchange(std::string const &data_base)
{
	std::fstream	file(data_base, std::fstream::in);
	std::string		line;
	size_t			len;

	if (!file.is_open())
		throw (Error("failed to open data base \"" + data_base + "\"."));
	this->getLine(file, line);
	if (line.compare("date,exchange_rate"))
		throw (Error("corrupted data.csv."));
	for (this->getLine(file, line); !file.eof(); this->getLine(file, line))
	{
		len = line.find_first_of(",");
		if (len == std::string::npos)
			throw (Error("invalid syntax."));
		data.insert(std::pair<Date, double>(this->getDate(line.substr(
			0, len)), std::stod(line.substr(len + 1))));
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &cpy)
{
	this->data = cpy.data;
	return (*this);
}

BitcoinExchange	&BitcoinExchange::operator<<(std::string const &file_name)
{
	std::fstream				file(file_name, std::fstream::in);
	std::string					line;

	if (!file.is_open())
		throw (Error("could not open file \"" + file_name + "\"."));
	this->getLine(file, line);
	this->checkHeader(file_name, line);
	for (this->getLine(file, line); !file.eof(); this->getLine(file, line))
	{
		try
			{this->printMatch(line);}
		catch (std::exception const &e)
			{std::cerr << "Error: " << e.what() << std::endl;}
	}
	file.close();
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

void	BitcoinExchange::checkHeader(std::string const &file_name, std::string &line)
{
	size_t	date;
	size_t	sep;
	size_t	value;

	if (!line.size())
		throw (Error("invalid header in file \"" + file_name + "\"."));
	date = line.find("date");
	sep = line.find("|");
	value = line.find("value");
	if (date == std::string::npos || sep == std::string::npos
		|| value == std::string::npos || !(date < sep && sep < value))
		throw (Error("invalid header in file \"" + file_name + "\"."));
	line.erase(date, 4);
	line.erase(sep - 4, 1);
	line.erase(value - 5, 5);
	if (line.find_first_not_of("\t\n\r\v\f ") != std::string::npos)
		throw (Error("invalid header in file \"" + file_name + "\"."));
}

void	BitcoinExchange::printMatch(std::string const &line)
{
	t_multimap::const_iterator	match;
	size_t						len;
	Date						date;
	double						value;

	len = line.find_first_of("|");
	if (len == std::string::npos)
		throw (Error("bad input => " + line));
	date = this->getDate(line.substr(0, len));
	value = this->checkValue(line.substr(len + 1));
	match = this->data.lower_bound(date);
	if (match == data.end() || (match != data.begin() && match->first != date))
		--match;
	std::cout << date << " => " << value << " = ";
	std::cout << match->second * value << std::endl;
}

Date	BitcoinExchange::getDate(std::string date)
{
	Date	num;
	size_t	len;

	len = date.find_first_not_of("\t\n\r\v\f ");
	date.erase(0, len);
	len = date.find_first_not_of("0123456789");
	if (!len || date[len] != '-')
		throw (Error("invalid syntax => " + date + "."));
	num.setYear(std::stoi(date.substr(0, len)));
	date.erase(0, len + 1);
	len = date.find_first_not_of("0123456789");
	if (!len || date[len] != '-')
		throw (Error("invalid syntax => " + date + "."));
	num.setMonth(std::stoi(date.substr(0, len)));
	date.erase(0, len + 1);
	len = date.find_first_not_of("0123456789");
	if (!len || date.find_first_not_of("\t\n\r\v\f ", len) != std::string::npos)
		throw (Error("invalid syntax => " + date + "."));
	num.setDay(std::stoi(date.substr(0, len)));
	return (num);
}

double	BitcoinExchange::checkValue(std::string value)
{
	size_t	len;
	double	val;

	val = std::stod(value);
	if (val > 2147483647)
		throw (Error("too large a number."));
	else if (val < 0)
		throw (Error("not a positive number."));
	len = value.find_last_of("0123456789");
	len = value.find_first_not_of("\t\n\r\v\f ", len + 1);
	if (len != std::string::npos)
		throw (Error("invalid syntax."));
	return (val);
}
