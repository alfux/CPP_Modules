/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:59:05 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 03:07:27 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ICharacter.hpp"

ICharacter::ICharacter(void)
	{std::cout << "[ICharacter's default constructor called]" << std::endl;}

ICharacter::ICharacter(ICharacter const &cpy)
{
	(void)cpy;
	std::cout << "[ICharacter's copy constructor called]" << std::endl;
}

ICharacter::~ICharacter(void)
	{std::cout << "[ICharacter's destructor called]" << std::endl;}

ICharacter	&ICharacter::operator=(ICharacter const &cpy)
{
	(void)cpy;
	return (*this);
}
