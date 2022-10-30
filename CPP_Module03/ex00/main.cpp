/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:19:01 by alfux             #+#    #+#             */
/*   Updated: 2022/10/30 02:56:52 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	john("John");
	ClapTrap	dick;
	ClapTrap	cloned_john(john);
	int			i;

	dick = ClapTrap("Persistant ghost Emerick");
	for (i = 0; i < 3; i++)
	{
		john.attack("John");
		john.attack("Persistant ghost Emerick");
		john.attack("");
		john.attack("nothing");
		cloned_john.takeDamage(5);
		dick.beRepaired((1 << 31));
		dick.beRepaired((1 << 31));
		dick.beRepaired((1 << 31));
		dick.beRepaired((1 << 31));
		dick.beRepaired((1 << 31));
	}
	std::cout << "What a mess..." << std::endl;
}
