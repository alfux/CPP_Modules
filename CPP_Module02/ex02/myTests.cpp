/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myTests.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:39:20 by alfux             #+#    #+#             */
/*   Updated: 2022/10/28 05:45:23 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"

int	main(void)
{
	Fixed	a(-83);
	Fixed	b(4242.42f);

	if (a >= b)
		std::cout << "a(" << a << ") >= b(" << b << ")" << std::endl;
	else
		std::cout << "a(" << a << ") < b(" << b << ")" << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "min(a,b) = " << Fixed::min(a,b) << std::endl;
	std::cout << "max(a,b) = " << Fixed::max(a,b) << std::endl;
	std::cout << "min(234.7, -0.68) = " << a.min(Fixed(234.7f), Fixed(-0.68f))
		<< std::endl;
	std::cout << "max(234.7, -0.68) = " << b.max(Fixed(234.7f), Fixed(-0.68f))
		<< std::endl;
	std::cout << "a == b returns " << (a == b) << std::endl;
	std::cout << "a != b returns " << (a != b) << std::endl;
	std::cout << "Fixed(1.1) == Fixed(1.1) returns "
		<< (Fixed(1.1f) == Fixed(1.1f)) << std::endl;
	std::cout << "Fixed(1.1) != Fixed(1.1) returns "
		<< (Fixed(1.1f) != Fixed(1.1f)) << std::endl;
	return (0);
}
