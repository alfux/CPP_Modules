/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:14:11 by alfux             #+#    #+#             */
/*   Updated: 2022/10/25 01:42:47 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Weapon.hpp"

Weapon::Weapon(void)
{
	type = "little wooden stick";
}

Weapon::Weapon(std::string new_type)
{
	type = new_type;
}

std::string const	&Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string new_type)
{
	type = new_type;
}

Weapon::~Weapon(void) {}
