/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:49:06 by alfux             #+#    #+#             */
/*   Updated: 2022/10/26 02:05:48 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cerr << "fatal error: incorrect parameters" << std::endl;
		return (1);
	}
	harl.complain(*(av + 1));
	return (0);
}
