/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:30:40 by alfux             #+#    #+#             */
/*   Updated: 2022/10/24 02:09:25 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

int	Zombie::nbZ = 0;

Zombie::Zombie(void)
{
	if (!nbZ)
		name = "patient0";
	else
		name = "zombie" + std::to_string(nbZ);
	nbZ++;
}

Zombie::Zombie(std::string newname)
{
	name = newname;
	nbZ++;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << name << ": humanity restored" << std::endl;
}
