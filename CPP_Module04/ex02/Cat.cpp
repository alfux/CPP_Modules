/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:12:56 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 06:56:59 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), brain((Brain *)0)
{
	std::cout << "[Cat's default constructor called]" << std::endl;
	try
		{this->brain = new Brain();}
	catch (...)
	{
		this->brain = (Brain *)0;
		std::cerr << "error: " << this->type << " is braindead (brain=NULL)\n";
	}
}

Cat::Cat(Cat const &cpy) : Animal(cpy), brain((Brain *)0)
{
	std::cout << "[Cat's copy constructor called]" << std::endl;
	try
		{this->brain = new Brain(*cpy.brain);}
	catch (...)
	{
		this->brain = (Brain *)0;
		std::cerr << "error: " << this->type << " is braindead (brain=NULL)\n";
	}
}

Cat::~Cat(void)
{
	std::cout << "[Cat's destructor called]" << std::endl;
	if (this->brain)
		delete this->brain;
}

Cat	&Cat::operator=(Cat const &cpy)
{
	this->type = cpy.type;
	*this->brain = *cpy.brain;
	return (*this);
}

void	Cat::makeSound(void)
{
	std::cout << "*Meeeow*" << std::endl;
}
