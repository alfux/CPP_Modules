/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 06:01:08 by alfux             #+#    #+#             */
/*   Updated: 2022/10/25 17:59:11 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RStream.hpp"

int	main(int ac, char **av)
{
	RStream	file;

	if (ac != 4)
	{
		std::cerr << "error: incorrect parameters" << std::endl;
		return (1);
	}
	file.open(*(av + 1));
	file.replace(*(av + 2), *(av + 3));
	return (0);
}
