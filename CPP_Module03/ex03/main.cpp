/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:19:01 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 01:59:21 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	monster;
	ScavTrap	*scav;
	FragTrap	*frag;
	ClapTrap	*clap;

	scav = &monster;
	frag = &monster;
	clap = &monster;
	monster.whoAmI();
	scav->attack("everyone");
	scav->guardGate();
	frag->attack("everyone");
	frag->highFivesGuys();
	clap->attack("everyone");
	scav->takeDamage(50);
	frag->takeDamage(49);
	clap->takeDamage(1);
	scav->beRepaired(1);
	frag->beRepaired(49);
	clap->beRepaired(50);
	monster.beRepaired((uint32_t)(1 << 31) - 1 + (uint32_t)(1 << 31));
	return (0);
}
