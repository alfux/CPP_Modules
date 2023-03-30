/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:31:59 by alfux             #+#    #+#             */
/*   Updated: 2023/03/29 18:48:22 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int	main(void)
{
	try
	{
		BitcoinExchange	data_base("data.csv");
	}
	catch (std::exception const &e)
		{std::cerr << "Error: " << e.what() << std::endl;}
	return (0);
}
