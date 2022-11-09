/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:58:55 by alfux             #+#    #+#             */
/*   Updated: 2022/11/09 14:02:08 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Convert.hpp"

int	main(int ac, char **av)
{
	Convert	conv;

	if (ac < 2)
		return (0);
	if (ac > 2)
	{
		std::cerr << "error: too much arguments" << std::endl;
		return (1);
	}
	try
		{conv = *(av + 1);}
	catch (std::exception &exc)
	{
		std::cerr << "error: " << exc.what() << std::endl;
		return (1);
	}
	std::cout << conv << std::endl;
	return (0);
}
