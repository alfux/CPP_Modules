/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:40:14 by alfux             #+#    #+#             */
/*   Updated: 2022/10/28 05:38:23 by alfux            ###   ########.fr       */
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

Fixed::Fixed(void) : bits(0) {}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed::Fixed(int const n)
{
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
	else if ((expo - 127) < 15)
	{
		this->bits = this->bits >> (14 - (expo - 127));
		this->bits += (this->bits & 1);
		this->bits = this->bits >> 1;
	}
	if (x < 0)
		twos_complement(this->bits);
}

Fixed::~Fixed(void) {}

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
	if (this->bits == (unsigned int)(1 << 31))
		return(-8388608.f);
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
	this->bits = assign.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator++(void)
{
	this->bits++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->bits--;
	return (*this);
}

Fixed	Fixed::operator++(int null)
{
	(void)null;
	++(*this);
	return (--Fixed(*this));
}

Fixed	Fixed::operator--(int null)
{
	(void)null;
	--(*this);
	return (++Fixed(*this));
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	ret;

	ret.setRawBits(this->bits + rhs.bits);
	return (ret);
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	ret;

	ret.setRawBits(this->bits - rhs.bits);
	return (ret);
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	unsigned int	a;
	unsigned int	b;
	Fixed			ret;
	int				i;

	a = *(unsigned int *)(&this->bits);
	b = *(unsigned int *)(&rhs.bits);
	if (((a >> 31) & 1) == 1)
		twos_complement(a);
	if (((b >> 31) & 1) == 1)
		twos_complement(b);
	for (i = 0; i < Fixed::frac; i++)
		ret.bits += (((b >> i) & 1) * a) >> (Fixed::frac - i);
	for (i = Fixed::frac; i < 32; i++)
		ret.bits += (((b >> i) & 1) * a) << (i - Fixed::frac);
	if (((this->bits >> 31) & 1) != ((rhs.bits >> 31) & 1))
		twos_complement(ret.bits);
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

int	Fixed::operator>(Fixed const &rhs) const
{
	int	a;
	int	b;

	a = *(int *)(&this->bits);
	b = *(int *)(&rhs.bits);
	if (a > b)
		return (1);
	return (0);
}

int	Fixed::operator>=(Fixed const &rhs) const
{
	int	a;
	int	b;

	a = *(int *)(&this->bits);
	b = *(int *)(&rhs.bits);
	if (a >= b)
		return (1);
	return (0);
}

int	Fixed::operator<(Fixed const &rhs) const
{
	int	a;
	int	b;

	a = *(int *)(&this->bits);
	b = *(int *)(&rhs.bits);
	if (a < b)
		return (1);
	return (0);
}

int	Fixed::operator<=(Fixed const &rhs) const
{
	int	a;
	int	b;

	a = *(int *)(&this->bits);
	b = *(int *)(&rhs.bits);
	if (a <= b)
		return (1);
	return (0);
}

int	Fixed::operator==(Fixed const &rhs) const
{
	if (this->bits == rhs.bits)
		return (1);
	return (0);
}

int	Fixed::operator!=(Fixed const &rhs) const
{
	if (this->bits != rhs.bits)
		return (1);
	return (0);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &flux, Fixed const &n)
{
	if (n.getRawBits() << 24 == 0)
		return (flux << n.toInt());
	return (flux << n.toFloat());
}
