/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:14:18 by alfux             #+#    #+#             */
/*   Updated: 2022/10/25 02:25:34 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "HumanB.hpp"

HumanB::HumanB(std::string new_name) : weapon((Weapon *)0), name(new_name){}

void	HumanB::setWeapon(Weapon &w)
{
	weapon = &w;
}

void	HumanB::attack(void)
{
	if (weapon)
	{
		std::cout << name << " attacks with their " << weapon->getType();
		std::cout << std::endl;
	}
	else
		std::cout << name << " attacks with their bare fists\n";
}

HumanB::~HumanB(void) {}
