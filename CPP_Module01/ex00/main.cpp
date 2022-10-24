/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:30:21 by alfux             #+#    #+#             */
/*   Updated: 2022/10/24 03:51:07 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

int	delcrowd(Zombie **crowd)
{
	int	i;

	i = 0;
	while (*(crowd + i))
		delete *(crowd + i++);
	delete[] crowd;
	return (0);
}

int	main(int ac, char **av)
{
	std::string	name;
	Zombie		**crowd;
	int			i;

	try
	{
		crowd = new Zombie *[ac];
	}
	catch (std::bad_alloc &bad)
	{
		std::cerr << "error: " << bad.what() << std::endl;
		return (1);
	}
	*(crowd + ac - 1) = (Zombie *)0;
	for (i = 0; (i < ac - 1); i++)
	{
		*(crowd + i) = newZombie(*(av + i + 1));
		if (!*(crowd + i))
			return (1 + delcrowd(crowd));
		name = name.assign(*(av + i + 1)) + "'s soul";
		(*(crowd + i))->announce();
		randomChump(name);
	}
	delcrowd(crowd);
	return (0);
}
