/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:40:14 by alfux             #+#    #+#             */
/*   Updated: 2022/10/27 04:12:12 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"

int const	Fixed::frac = 8;

Fixed::Fixed(void) : bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->bits = copy.getRawBits();
}

Fixed	&Fixed::operator=(Fixed const &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->bits = assign.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->bits);
}

void	Fixed::setRawBits(int const raw)
{
	this->bits = raw;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
