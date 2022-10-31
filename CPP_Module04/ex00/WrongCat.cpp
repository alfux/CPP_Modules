/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:12:56 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 05:20:57 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat's default constructor called]" << std::endl;
}

WrongCat::WrongCat(WrongCat const &cpy) : WrongAnimal(cpy)
{
	std::cout << "[WrongCat's copy constructor called]" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "[WrongCat's destructor called]" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &cpy)
{
	this->type = cpy.type;
	return (*this);
}

void	WrongCat::makeSound(void)
{
	std::cout << "*WrongMeeeow*" << std::endl;
}
