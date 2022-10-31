/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:16:21 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 01:45:41 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->name = this->ClapTrap::name;
	this->energy_points = 50;
	ClapTrap::name = this->name + "_clap_trap";
	std::cout << "Diamond constructor:" << std::endl;
	std::cout << "A " << this->name << " atrocity has emerged from darkness\n"
		<< std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy)
	: ClapTrap(cpy), ScavTrap(*this), FragTrap(*this)
{
	this->name = cpy.name;
	std::cout << "Diamond copy constructor:" << std::endl;
	std::cout << "A " << this->name << " filth has risen from darkness\n"
		<< std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name)
	: ClapTrap(name + "_clap_trap"), ScavTrap(name + "_clap_trap"),
		FragTrap(name + "_clap_trap")
{
	this->name = name;
	this->energy_points = 50;
	std::cout << "Diamond string constructor:" << std::endl;
	std::cout << "A " << this->name << " garbage has jumped from darkness\n"
		<< std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Diamond destructor:" << std::endl;
	std::cout << "Atrocity " << this->name << " disappeared\n" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &cpy)
{
	(void)ClapTrap::operator=(cpy);
	std::cout << "Diamond assignment operator:" << std::endl
		<< "DiamondTrap " << this->name << " turns into " << cpy.name
		<< std::endl << std::endl;
	this->name = cpy.name;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "whoami: " << std::endl;
	std::cout << "I AM " << this->name << " SON OF " << ScavTrap::name
		<< std::endl << std::endl;
}
