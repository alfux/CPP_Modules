/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:32:49 by alfux             #+#    #+#             */
/*   Updated: 2023/03/30 04:17:24 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <Error.hpp>
# include <Date.hpp>

class	BitcoinExchange
{
	std::map<Date, double>	data;

	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &cpy);
		BitcoinExchange(std::string const &data_file);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(BitcoinExchange const &cpy);

		Date	getDate(std::string date);

	private:
		std::istream	&getLine(std::istream &is, std::string &str);
};

#endif
