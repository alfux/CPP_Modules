/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:30:21 by alfux             #+#    #+#             */
/*   Updated: 2022/10/24 02:52:55 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

int	main(int ac, char **av)
{
	std::string	name;
	Zombie		**crowd;

	crowd = new Zombie *[ac];
	*(crowd + --ac) = (Zombie *)0;
	while (--ac >= 0)
	{
		*(crowd + ac) = new Zombie(*(av + ac + 1));
		name = *(av + ac + 1);
		name += "'s soul";
		(*(crowd + ac))->announce();
		randomChump(name);
	}
	ac = 0;
	while (*(crowd + ac))
		delete *(crowd + ac++);
	delete[] crowd;
	return (0);
}
