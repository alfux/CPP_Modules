/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:51:20 by alfux             #+#    #+#             */
/*   Updated: 2023/03/31 06:40:48 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

int main(int ac, char **av)
{
	try
	{
		std::string	rpn;
		ssize_t		i;
		RPN			calculator;

		if (ac < 2)
			throw (Error(EARG));
		for (i = 1; i < ac; ++i)
			rpn += std::string(*(av + i)) + std::string(" ");
		calculator = rpn;
		calculator.solve();
	}
	catch (std::exception const &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
