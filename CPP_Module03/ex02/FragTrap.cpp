/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:33:57 by alfux             #+#    #+#             */
/*   Updated: 2022/10/30 05:26:46 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "Frag default constructor:" << std::endl
		<< "Nameless ClapTrap evolved into FragTrap !\n" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap(cpy)
{
	std::cout << "Frag copy constructor:" << std::endl
		<< "FragTrap " << cpy.name << " has been copied.\n" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "Frag string constructor:" << std::endl;
	std::cout << "ClapTrap " << this->name << " evolved into FragTrap !\n\n";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Frag destructor:" << std::endl
		<< "FragTrap " << this->name << " regressed into ClapTrap.\n\n";
}

FragTrap	&FragTrap::operator=(FragTrap const &cpy)
{
	std::cout << "Frag overloaded assignment operator:" << std::endl
		<< "FragTrap " << this->name << " becomes a copy of " << cpy.name
		<< std::endl << std::endl;
	this->name = cpy.name;
	this->hit_points = cpy.hit_points;
	this->energy_points = cpy.energy_points;
	this->attack_damage = cpy.attack_damage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->name << ": HEY ! HIGH FIVES guys ! *waving hand*\n"
		<< std::endl;
}
