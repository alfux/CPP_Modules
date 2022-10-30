/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:57:59 by alfux             #+#    #+#             */
/*   Updated: 2022/10/30 02:21:15 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Nameless")
{
	std::cout << "Default Constructo:" << std::endl;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "Behold ! A Nameless ClapTrap has been born !\n" << std::endl;
}

ClapTrap::ClapTrap(std::string const &new_name) : name(new_name)
{
	std::cout << "String Constructor:" << std::endl;
	if (this->name == "")
		this->name = "Nameless";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "Behold ! The birth of " << this->name << " the ClapTrap\n"
		<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cpy) : name(cpy.name)
{
	std::cout << "Copy Constructor:" << std::endl;
	this->hit_points = cpy.hit_points;
	this->energy_points = cpy.energy_points;
	this->attack_damage = cpy.attack_damage;
	std::cout << "Oh... no, oh god please NO ! " << cpy.name
		<< " has been CLONED !?\n" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor:" << std::endl;
	std::cout << "To be, or not to be, that is the question:" << std::endl;
	std::cout << "Whether 'tis nobler in the mind to suffer" << std::endl;
	std::cout << "The slings and arrows of outrageous fortune," << std::endl;
	std::cout << "Or to take arms against a sea of troubles" << std::endl;
	std::cout << "And by opposing end them. To die—to sleep," << std::endl;
	std::cout << "No more..." << " Thus, " << this->name << " died.\n"
		<< std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &cpy)
{
	std::cout << "Overloaded assignment operator:" << std::endl;;
	std::cout << "ClapTrap " << this->name << " used a metamorphosis lotion,";
	this->name = cpy.name;
	this->hit_points = cpy.hit_points;
	this->energy_points = cpy.energy_points;
	this->attack_damage = cpy.attack_damage;
	std::cout << " it's exactly like " << this->name << " now.\n" << std::endl;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "Attack:" << std::endl;
	if (!this->energy_points)
	{
		std::cout << "Error 404: ClapTrap " << this->name << "'s connection"
			<< " has been lost. No more Energy Points left.\n" << std::endl;
		return ;
	}
	this->energy_points--;
	std::cout << "ClapTrap " << this->name << " falsly sings to " << target
		<< ", causing " << this->attack_damage << " points of damage ! "
		<< "Energy Points drained to " << this->energy_points << ".\n"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Take damage:" << std::endl;
	if (amount >= this->hit_points)
	{
		std::cout << "ClapTrap " << this->name << " lost all of its "
			<< this->hit_points << " Hit Points ! It's basically "
			<<  "fucking dead now.\n" << std::endl;
		this->hit_points = 0;
		return ;
	}
	this->hit_points -= amount;
	std::cout << "ClapTrap " << this->name << " has internal injuries, "
		<< "if it had real organs, it would be dying. Hopefully, it just "
		<< "lost " << amount << " Hit Points... you'd still have "
		<< this->hit_points << " more to go to put it out of its misery.\n"
		<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "Be repaired:" << std::endl;
	if (!this->energy_points)
	{
		std::cout << "Error 404: ClapTrap " << this->name << "'s connection"
			<< " has been lost. No more Energy Points left.\n" << std::endl;
		return ;
	}
	std::cout << "Energy drained to " << --this->energy_points << " points... ";
	if (CLAPGOD - amount <= this->hit_points)
	{
		this->hit_points = CLAPGOD;
		std::cout << "OVERLOAD ! OVERLOAD ! Critical Hit Points level has been "
			<< "reached ! It's over " << this->hit_points << "! ClapTrap "
			<< this->name << " is about to become a God!\n" << std::endl;
		return ;
	}
	if (!this->hit_points)
		std::cout << "WOW! " << this->name << " has risen from the deads! ";
	this->hit_points += amount;
	std::cout << "Claptrap " << this->name << " has just found a massive piece "
		<< "of rusted iron. Millions of years of evolution, researches and new "
		<< "extra advanced technologies has permitted " << this->name << " to "
		<< "tape it around it as a " << amount << " Hit points shield ! "
		<< "It's got " << this->hit_points << " total Hit Points now !\n"
		<< std::endl;;
}
