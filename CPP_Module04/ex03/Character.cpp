/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:16:05 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 03:08:49 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Character.hpp"

Character::Character(void) : name("Nameless")
{
	std::cout << "[Character's default constructor called]" << std::endl;
	this->inventory[0] = (AMateria *)0;
	this->inventory[1] = (AMateria *)0;
	this->inventory[2] = (AMateria *)0;
	this->inventory[3] = (AMateria *)0;
}

Character::Character(Character const &cpy) : ICharacter(cpy), name(cpy.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (cpy.inventory[i])
		{
			this->inventory[i] = cpy.inventory[i]->clone();
			if (!this->inventory[i])
				std::cerr << "error: couldn't clone inventory slot " << i
					<< std::endl;
		}
		else
			this->inventory[i] = (AMateria *)0;
	}
	std::cout << "[Character's copy constructor called]" << std::endl;
}

Character::Character(std::string const &name) : name(name)
{
	std::cout << "[Character' string constructor called]" << std::endl;
	this->inventory[0] = (AMateria *)0;
	this->inventory[1] = (AMateria *)0;
	this->inventory[2] = (AMateria *)0;
	this->inventory[3] = (AMateria *)0;
}

Character::~Character(void)
{
	std::cout << "[Character's destructor called]" << std::endl;
	if (this->inventory[0])
		delete this->inventory[0];
	if (this->inventory[1])
		delete this->inventory[1];
	if (this->inventory[2])
		delete this->inventory[2];
	if (this->inventory[3])
		delete this->inventory[3];
}

Character	&Character::operator=(Character const &cpy)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = (AMateria *)0;
		}
		if (cpy.inventory[i])
		{
			this->inventory[i] = cpy.inventory[i]->clone();
			if (!this->inventory[i])
				std::cerr << "error: couldn't clone inventory slot " << i
					<< std::endl;
		}
	}
	this->name = cpy.name;
	return (*this);
}

std::string const	&Character::getName(void) const
	{return (this->name);}

void	Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	this->inventory[idx] = (AMateria *)0;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}
