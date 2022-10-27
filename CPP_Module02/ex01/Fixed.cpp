/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:40:14 by alfux             #+#    #+#             */
/*   Updated: 2022/10/27 04:02:42 by alfux            ###   ########.fr       */
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
	*this = copy;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	bits = n << Fixed::frac;
	if (n < 0)
		bits *= -1;
}

Fixed::Fixed(float const flo)
{
	int	expo;
	int	mant;
	int	i;
	int	j;
	int	x;

	std::cout << "Float constructor called" << std::endl;
	x = *((int *)&flo);
	expo = 255 & ((int)x >> 23);
	mant = (int)x & ((1 << 23) - 1);
	this->bits = 0;
	if (!expo && !mant)
		return ;
	if (expo > 126)
		this->bits += (1 << (expo - 127));
	for (i = 1; (expo - i) > 126; i++)
		this->bits += ((mant >> (23 - i)) & 1) * (1 << (expo - 127 - i));
	this->bits = this->bits << Fixed::frac;
	j = 0;
	while (i < 24 && j < Fixed::frac)
		this->bits += ((mant >> (23 - i++)) & 1)
			* (1 << (Fixed::frac - j++ - 1));
	this->bits = this->bits | 1;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->bits);
}

void	Fixed::setRawBits(int const raw)
{
	this->bits = raw;
}

float	Fixed::toFloat(void) const
{
	char	msb;
	int		flo;
	int		i;

	if (!this->bits)
		return ((float)0);
	for (msb = 30; !((this->bits >> msb) & 1); msb--);
	flo = (119 + msb) << 23;
	i = 0;
	while (--msb >= 0)
		flo = flo | (((this->bits >> msb) & 1) << (22 - i++));
	flo = flo | (this->bits & (1 << 31));
	return (*((float *)(&flo)));
}

int	Fixed::toInt(void) const
{
	return (this->bits >> Fixed::frac);
}

Fixed	&Fixed::operator=(Fixed const &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->bits = assign.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &flux, Fixed const &n)
{
	if (n.getRawBits() << 24 != 0)
		return (flux << n.toFloat());
	return (flux << n.toInt());
}
