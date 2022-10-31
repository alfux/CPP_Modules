/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:21:52 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 17:32:09 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"

Animal::Animal(std::string const &type) : type(type)
{
	std::cout << "[Animal' string constructor called]" << std::endl;
}

Animal::Animal(void) : type("Creature")
{
	std::cout << "[Animal's default constructor called]" << std::endl;
}

Animal::Animal(Animal const &cpy) : type(cpy.type)
{
	std::cout << "[Animal's copy constructor called]" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "[Animal's destructor called]" << std::endl;
}

Animal	&Animal::operator=(Animal const &cpy)
{
	this->type = cpy.type;
	return (*this);
}

std::string	Animal::getType(void)
{
	return (this->type);
}
