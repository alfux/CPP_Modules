/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:11:38 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 03:05:39 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
	{std::cout << "[Cure's default constructor called]" << std::endl;}

Cure::Cure(Cure const &cpy) : AMateria(cpy)
	{std::cout << "[Cure's copy constructor called]" << std::endl;}

Cure::~Cure(void)
	{std::cout << "[Cure's destructor called]" << std::endl;}

Cure	&Cure::operator=(Cure const &cpy)
{
	(void)cpy;
	return (*this);
}

void	Cure::use(ICharacter &target)
	{std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;}

AMateria	*Cure::clone(void) const
{
	AMateria	*tmp;

	try
		{tmp = new Cure(*this);}
	catch (...)
		{return ((AMateria *)0);}
	return (tmp);
}
