/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:19:01 by alfux             #+#    #+#             */
/*   Updated: 2022/10/30 05:29:26 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap	john("John");
	ScavTrap	dick(john);
	ClapTrap	cloned_john(john);
	FragTrap	killer("KillerBee");
	int			i;

	dick = ScavTrap("Dick");
	for (i = 0; i < 3; i++)
	{
		killer.attack("everyone");
		killer.takeDamage(50);
		killer.beRepaired(20);
		killer.highFivesGuys();
		john.attack("John");
		john.attack("Dick");
		john.attack("nothing");
		cloned_john.takeDamage(5);
		cloned_john.attack("John");
		cloned_john.attack("Dick");
		cloned_john.attack("emptyness");
		cloned_john.attack("emptyness");
		dick.beRepaired((1 << 31));
		dick.beRepaired((1 << 31));
		dick.beRepaired((1 << 31));
		dick.beRepaired((1 << 31));
		dick.beRepaired((1 << 31));
	}
	john.guardGate();
	dick.guardGate();
	std::cout << "What a mess..." << std::endl;
}
