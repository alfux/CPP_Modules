/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:49:06 by alfux             #+#    #+#             */
/*   Updated: 2022/10/26 03:49:05 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Harl.hpp"

void	ft_switch(char const &lvl)
{
	Harl	harl;

	switch (lvl)
	{
		case 'D':
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 'I':
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
		case 'W':
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
		case 'E':
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	}
}

int	main(int ac, char **av)
{
	std::string	lvl;

	if (ac == 2)
	{
		lvl = *(av + 1);
		if (lvl.compare("DEBUG") && lvl.compare("INFO")
			&& lvl.compare("WARNING") && lvl.compare("ERROR"))
			lvl.clear();
	}
	ft_switch(lvl.front());
	return (0);
}
