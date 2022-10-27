/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:40:14 by alfux             #+#    #+#             */
/*   Updated: 2022/10/27 22:46:17 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"

int const	Fixed::frac = 8;

static void	twos_complement(unsigned int &bit)
{
	for (int b = 0; b < 32; b++)
		bit += (bit & (1 << b)) ? (-1) * (1 << b) : 1 << b;
	bit += 1;
}

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
	if (n > (1 << 23) - 1 || n < (-1) * (1 << 23))
		std::cerr << "warning: number " << n << " is out of range"
			<< " (undefined behavior)" << std::endl;
	this->bits = (*(unsigned int *)(&n)) << Fixed::frac;
}

Fixed::Fixed(float const x)
{
	unsigned int	b;
	unsigned int	mant;
	unsigned char	expo;

	std::cout << "Float constructor called" << std::endl;
	if (x > (1 << 23) - 1 || x < (-1) * (1 << 23))
		std::cerr << "warning: number " << x << " is out of range"
			<< " (undefined behavior)" << std::endl;
	b = *(unsigned int *)(&x);
	mant = ((1 << 23) - 1) & b;
	expo = (((1 << 8) - 1) & (b >> 23));
	this->bits = mant | (1 << 23);
	if (!mant && !expo)
		this->bits = 0;
	if ((expo - 127) > 15)
		this->bits = this->bits << ((expo - 127) - 15);
	else
		this->bits = this->bits >> (15 - (expo - 127));
	if (x < 0)
		twos_complement(this->bits);
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

int	Fixed::toInt(void) const
{
	unsigned int	ret;

	if (!this->bits)
		return (0);
	ret = this->bits;
	if ((this->bits & (1 << 31)))
	{
		twos_complement(ret);
		ret = ret >> Fixed::frac;
		twos_complement(ret);
	}
	else
		ret = ret >> Fixed::frac;
	return ((*(int *)(&ret)));
}

float	Fixed::toFloat(void) const
{
	unsigned int	ret;
	unsigned char	msb;

	if (!this->bits)
		return (0.f);
	ret = this->bits;
	if ((this->bits & (1 << 31)))
		twos_complement(ret);
	for (msb = 30; msb > 0 && !(ret & (1 << msb)); msb--);
	if (msb > 23)
		ret = ret >> (msb - 23);
	else
		ret = ret << (23 - msb);
	ret = (ret - (1 << 23)) | ((msb + 119) << 23);
	if ((this->bits & (1 << 31)))
		ret += (1 << 31);
	return (*(float *)(&ret));
}

Fixed	&Fixed::operator=(Fixed const &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->bits = assign.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &flux, Fixed const &n)
{
	if (n.getRawBits() << 24 == 0)
		return (flux << n.toInt());
	return (flux << n.toFloat());
}
