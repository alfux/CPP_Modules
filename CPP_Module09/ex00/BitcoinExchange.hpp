/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:32:49 by alfux             #+#    #+#             */
/*   Updated: 2023/03/30 09:18:05 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <fstream>
# include <string>
# include <map>
# include <iostream>
# include <iomanip>
# include <Error.hpp>
# include <Date.hpp>

class	BitcoinExchange
{
	typedef std::multimap<Date, double, std::less<Date> >	t_multimap;

	t_multimap	data;

	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &cpy);
		BitcoinExchange(std::string const &data_file);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(BitcoinExchange const &cpy);
		BitcoinExchange	&operator<<(std::string const &file_name);

	private:
		std::istream	&getLine(std::istream &is, std::string &str);
		void			checkHeader(std::string const &file_name, std::string &line);
		void			printMatch(std::string const &line);
		Date			getDate(std::string date);
		double			checkValue(std::string value);
};

#endif
