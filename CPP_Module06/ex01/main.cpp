/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:12:18 by alfux             #+#    #+#             */
/*   Updated: 2022/11/10 02:35:57 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Serial.hpp"

int	main(void)
{
	uintptr_t	intptr;
	Data		struc;
	Data		*ret;

	struc.dummy = '*';
	struc.dummy_ = 41;
	struc._dummy = 40.22f;
	struc.dduummmmyy = 44.22;
	intptr = serialize(&struc);
	ret = deserialize(intptr);
	std::cout << "original adress: " << &struc << std::endl;
	std::cout << "serialize: " << intptr << std::endl;
	std::cout << "deserialize: " << ret << std::endl;
	std::cout << "struc.dummy = " << struc.dummy << std::endl;
	std::cout << "ret->dummy = " << ret->dummy << std::endl;
	std::cout << "struc.dummy_ = " << struc.dummy_ << std::endl;
	std::cout << "ret->dummy_ = " << ret->dummy_ << std::endl;
	std::cout << "struc._dummy = " << struc._dummy << std::endl;
	std::cout << "ret->_dummy = " << ret->_dummy << std::endl;
	std::cout << "struc.dduummmmyy = " << struc.dduummmmyy << std::endl;
	std::cout << "ret->dduummmmyy = " << ret->dduummmmyy << std::endl;
	return (0);
}
