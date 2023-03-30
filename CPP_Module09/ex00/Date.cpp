/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:42:02 by alfux             #+#    #+#             */
/*   Updated: 2023/03/30 04:40:50 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Date.hpp>

Date::Date(void): year(0), month(0), day(0) {}

Date::Date(Date const &cpy):
	year(cpy.year),
	month(cpy.month),
	day(cpy.day) {}

Date::Date(ssize_t year, ssize_t month, ssize_t day)
{
	this->checkDate(year, month, day);
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::~Date(void) {}

void	Date::checkDate(ssize_t year, ssize_t month, ssize_t day) const
{
	if (year < 0)
		throw (Error("invalid year"));
	if (month <= 0 || month > 12)
		throw (Error("invalid month"));
	switch (day)
	{
		case 2:
			if (day > 28 + !(year % 4) || day <= 0)
				throw (Error("invalid day"));
			break ;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30 || day <= 0)
				throw (Error("invalid day"));
			break;
		default:
			if (day > 31 || day <= 0)
				throw (Error("invalid day"));
	}
}

void	Date::setYear(ssize_t year)
{
	if (year < 0)
		throw (Error("invalid year"));
	if (this->month && this->day)
		this->checkDate(year, this->month, this->day);
	this->year = year;
}

void	Date::setMonth(ssize_t month)
{
	if (month <= 0 || month > 12)
		throw (Error("invalid month"));
	if (this->day)
		this->checkDate(this->year, month, this->day);
	this->month = month;
}

void	Date::setDay(ssize_t day)
{
	if (day <= 0 || day > 31)
		throw (Error("invalid day"));
	if (this->month)
		this->checkDate(this->year, this->month, day);
	this->day = day;
}

size_t	Date::getYear(void) const
{
	return (this->year);
}

uint8_t	Date::getMonth(void) const
{
	return (this->month);
}

uint8_t	Date::getDay(void) const
{
	return (this->day);
}

Date	&Date::operator=(Date const &cpy)
{
	this->year = cpy.year;
	this->month = cpy.month;
	this->day = cpy.day;
	return (*this);
}

bool	Date::operator==(Date const &rhs) const
{
	if (this->year == rhs.year && this->month == rhs.month && this->day == rhs.day)
		return (true);
	return (false);
}

bool	Date::operator!=(Date const &rhs) const
{
	if (this->year == rhs.year && this->month == rhs.month && this->day == rhs.day)
		return (false);
	return (true);
}

bool	Date::operator<=(Date const &rhs) const
{
	if (this->year == rhs.year)
	{
		if (this->month == rhs.month)
		{
			if (this->day == rhs.day)
				return (true);
			return (this->day < rhs.day);
		}
		return (this->month < rhs.month);
	}
	return (this->year < rhs.year);
}

bool	Date::operator>=(Date const &rhs) const
{
	if (this->year == rhs.year)
	{
		if (this->month == rhs.month)
		{
			if (this->day == rhs.day)
				return (true);
			return (this->day > rhs.day);
		}
		return (this->month > rhs.month);
	}
	return (this->year > rhs.year);
}

bool	Date::operator<(Date const &rhs) const
{
	if (this->year == rhs.year)
	{
		if (this->month == rhs.month)
		{
			if (this->day == rhs.day)
				return (false);
			return (this->day < rhs.day);
		}
		return (this->month < rhs.month);
	}
	return (this->year < rhs.year);
}

bool	Date::operator>(Date const &rhs) const
{
	if (this->year == rhs.year)
	{
		if (this->month == rhs.month)
		{
			if (this->day == rhs.day)
				return (false);
			return (this->day > rhs.day);
		}
		return (this->month > rhs.month);
	}
	return (this->year > rhs.year);
}

std::ostream	&operator<<(std::ostream &os, Date const &date)
{
	os << date.getYear() << "-";
	os << std::setw(2) << std::setfill('0') << static_cast<int> (date.getMonth()) << "-";
	os << std::setw(2) << std::setfill('0') << static_cast<int> (date.getDay());
	return (os);
}
