/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:45:43 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 06:56:19 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), brain((Brain *)0)
{
	std::cout << "[Dog's default constructor called]" << std::endl;
	try
		{this->brain = new Brain();}
	catch (...)
	{
		this->brain = (Brain *)0;
		std::cerr << "error: " << this->type << " is braindead (brain=NULL)\n";
	}
}

Dog::Dog(Dog const &cpy) : Animal(cpy), brain((Brain *)0)
{
	std::cout << "[Dog's copy constructor called]" << std::endl;
	try
		{this->brain = new Brain(*cpy.brain);}
	catch (...)
	{
		this->brain = (Brain *)0;
		std::cerr << "error: " << this->type << " is braindead (brain=NULL)\n";
	}
}

Dog::~Dog(void)
{
	std::cout << "[Dog's destructor called]" << std::endl;
	if (this->brain)
		delete this->brain;
}

Dog	&Dog::operator=(Dog const &cpy)
{
	this->type = cpy.type;
	*this->brain = *cpy.brain;
	return (*this);
}

void	Dog::makeSound(void)
{
	std::cout << "*Bark*" << std::endl;
}
