/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:33:57 by alfux             #+#    #+#             */
/*   Updated: 2022/10/30 05:09:17 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "Scav default constructor:" << std::endl
		<< "Nameless ClapTrap evolved into ScavTrap !\n" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &cpy) : ClapTrap(cpy)
{
	std::cout << "Scav copy constructor:" << std::endl
		<< "ScavTrap " << cpy.name << " has been copied.\n" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "Scav string constructor:" << std::endl;
	std::cout << "ClapTrap " << this->name << " evolved into ScavTrap !\n\n";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Scav destructor:" << std::endl
		<< "ScavTrap " << this->name << " regressed into ClapTrap.\n\n";
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &cpy)
{
	std::cout << "Scav overloaded assignment operator:" << std::endl
		<< "ScavTrap " << this->name << " becomes a copy of " << cpy.name
		<< std::endl << std::endl;
	this->name = cpy.name;
	this->hit_points = cpy.hit_points;
	this->energy_points = cpy.energy_points;
	this->attack_damage = cpy.attack_damage;
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << "Scav attack:" << std::endl;
	std::cout << "ScavTrap " << this->name << " ripped " << target
		<< "'s throat for " << this->attack_damage << " damage.\n" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "DANGER: SCAVTRAP " << this->name << " ULTIMATE GATEKEEPER "
		<< "MODE ACTIVATED. AUTOMATIC TURETS ARMED AND READY.\n" << std::endl;
}
