/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:24:21 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 03:04:50 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
	{std::cout << "[Ice's default constructor called]" << std::endl;}

Ice::Ice(Ice const &cpy) : AMateria(cpy)
	{std::cout << "[Ice's copy constructor called]" << std::endl;}

Ice::~Ice(void)
	{std::cout << "[Ice's destructor called]" << std::endl;}

Ice	&Ice::operator=(Ice const &cpy)
{
	(void)cpy;
	return (*this);
}

void	Ice::use(ICharacter &target)
	{std::cout << "* shoots an ice bolt at " << target.getName() << " *" 
		<< std::endl;}

AMateria	*Ice::clone(void) const
{
	AMateria	*tmp;

	try
		{tmp = new Ice(*this);}
	catch (...)
		{return ((AMateria *)0);}
	return (tmp);
}
