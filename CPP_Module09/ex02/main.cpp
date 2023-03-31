/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:13:53 by alfux             #+#    #+#             */
/*   Updated: 2023/03/31 21:13:22 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int	main(int ac, char **av)
{
	try
	{
		PmergeMe	to_sort;
		std::string	arg;
		int			i;

		if (ac < 2)
			throw (Error(EARG));
		for (i = 1; i < ac; ++i)
			arg += std::string(*(av + i)) + " ";
		to_sort = arg;
		to_sort >> std::cout << std::endl;
	}
	catch (std::exception const &e)
		{std::cerr << "Error: " << e.what() << std::endl;}
	return (0);
}
