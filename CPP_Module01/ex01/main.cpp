/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:30:21 by alfux             #+#    #+#             */
/*   Updated: 2022/10/24 18:02:50 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie	*z;
	int		i;

	if (ac < 2)
		return (0);
	z = zombieHorde(ac - 1, *(av + 1));
	for (i = 0; i < ac - 1; i++)
		(z + i)->announce();
	delete[] z;
	return (0);
}
