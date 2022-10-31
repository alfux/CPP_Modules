/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:12:56 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 06:57:24 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat"), brain((Brain *)0)
{
	std::cout << "[WrongCat's default constructor called]" << std::endl;
	try
		{this->brain = new Brain();}
	catch (...)
	{
		this->brain = (Brain *)0;
		std::cerr << "error: " << this->type << " is braindead (brain=NULL)\n";
	}
}

WrongCat::WrongCat(WrongCat const &cpy) : WrongAnimal(cpy), brain((Brain *)0)
{
	std::cout << "[WrongCat's copy constructor called]" << std::endl;
	try
		{this->brain = new Brain(*cpy.brain);}
	catch (...)
	{
		this->brain = (Brain *)0;
		std::cerr << "error: " << this->type << " is braindead (brain=NULL)\n";
	}
}

WrongCat::~WrongCat(void)
{
	std::cout << "[WrongCat's destructor called]" << std::endl;
	if (this->brain)
		delete this->brain;
}

WrongCat	&WrongCat::operator=(WrongCat const &cpy)
{
	this->type = cpy.type;
	*this->brain = *cpy.brain;
	return (*this);
}

void	WrongCat::makeSound(void)
{
	std::cout << "*WrongMeeeow*" << std::endl;
}
