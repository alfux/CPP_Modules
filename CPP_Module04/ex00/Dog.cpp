/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:45:43 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 04:04:02 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "[Dog's default constructor called]" << std::endl;
}

Dog::Dog(Dog const &cpy) : Animal(cpy)
{
	std::cout << "[Dog's copy constructor called]" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "[Dog's destructor called]" << std::endl;
}

Dog	&Dog::operator=(Dog const &cpy)
{
	this->type = cpy.type;
	return (*this);
}

void	Dog::makeSound(void)
{
	std::cout << "*Bark*" << std::endl;
}
