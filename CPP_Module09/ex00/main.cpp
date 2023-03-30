/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:31:59 by alfux             #+#    #+#             */
/*   Updated: 2023/03/30 09:25:22 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Error.hpp>
#include <BitcoinExchange.hpp>

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw (Error("could not open file."));
		BitcoinExchange	data_base;

		data_base << *(av + 1);
	}
	catch (std::exception const &e)
		{std::cerr << "Error: " << e.what() << std::endl;}
	return (0);
}
