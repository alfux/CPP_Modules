/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:12:56 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 04:16:13 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "[Cat's default constructor called]" << std::endl;
}

Cat::Cat(Cat const &cpy) : Animal(cpy)
{
	std::cout << "[Cat's copy constructor called]" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "[Cat's destructor called]" << std::endl;
}

Cat	&Cat::operator=(Cat const &cpy)
{
	this->type = cpy.type;
	return (*this);
}

void	Cat::makeSound(void)
{
	std::cout << "*Meeeow*" << std::endl;
}
