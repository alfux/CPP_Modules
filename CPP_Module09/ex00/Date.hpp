/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:47:32 by alfux             #+#    #+#             */
/*   Updated: 2023/03/30 09:04:18 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP
# include <iostream>
# include <iomanip>
# include <Error.hpp>

class	Date
{
	size_t	year;
	uint8_t	month;
	uint8_t	day;

	public:
		Date(void);
		Date(Date const &cpy);
		Date(ssize_t year, ssize_t month, ssize_t day);
		~Date(void);
		
		void	checkDate(ssize_t year, ssize_t month, ssize_t day) const;
		void	setYear(ssize_t year);
		void	setMonth(ssize_t month);
		void	setDay(ssize_t day);
		size_t	getYear(void) const;
		uint8_t	getMonth(void) const;
		uint8_t	getDay(void) const;

		Date	&operator=(Date const &py);
		bool	operator==(Date const &rhs) const;
		bool	operator!=(Date const &rhs) const;
		bool	operator<=(Date const &rhs) const;
		bool	operator>=(Date const &rhs) const;
		bool	operator<(Date const &rhs) const;
		bool	operator>(Date const &rhs) const;

	private:
		std::string	invalidDate(ssize_t year, ssize_t month, ssize_t day) const;
};

std::ostream	&operator<<(std::ostream &os, Date const &date);

#endif
