/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:48:35 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 02:54:20 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AMateria.hpp"

AMateria::AMateria(void) : type("abstractum")
	{std::cout << "[AMateria's default constructor called]" << std::endl;}

AMateria::AMateria(AMateria const &cpy) : type(cpy.type)
	{std::cout << "[AMateria's copy constructor called]" << std::endl;}

AMateria::AMateria(std::string const &type) : type(type)
	{std::cout << "[AMateria' string constructor called]" << std::endl;}

AMateria::~AMateria(void)
	{std::cout << "[AMateria's destructor called]" << std::endl;}

AMateria	&AMateria::operator=(AMateria const &cpy)
{
	(void)cpy;
	return (*this);
}

std::string const	&AMateria::getType(void) const
	{return (this->type);}

void	AMateria::use(ICharacter &target)
	{std::cout << "* abstracts "<< target.getName() << " *" << std::endl;}
