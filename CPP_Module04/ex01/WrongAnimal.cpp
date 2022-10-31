/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:21:52 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 05:15:35 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string const &type) : type(type)
{
	std::cout << "[WrongAnimal' string constructor called]" << std::endl;
}

WrongAnimal::WrongAnimal(void) : type("WrongCreature")
{
	std::cout << "[WrongAnimal's default constructor called]" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &cpy) : type(cpy.type)
{
	std::cout << "[WrongAnimal's copy constructor called]" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "[WrongAnimal's destructor called]" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &cpy)
{
	this->type = cpy.type;
	return (*this);
}

void	WrongAnimal::makeSound(void)
{
	std::cout << "*WrongBrglglglergl*" << std::endl;
}

std::string	WrongAnimal::getType(void)
{
	return (this->type);
}
