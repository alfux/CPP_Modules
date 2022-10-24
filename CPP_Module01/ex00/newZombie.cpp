/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:31:10 by alfux             #+#    #+#             */
/*   Updated: 2022/10/24 01:58:22 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*newZ;

	try
	{
		newZ = new Zombie(name);
	}
	catch (std::bad_alloc &bad)
	{
		std::cerr << "error: " << bad.what() << std::endl;
		return ((Zombie *)0);
	}
	catch (...)
	{
		std::cerr << "error: unexpected error occured" << std::endl;
		return ((Zombie *)0);
	}
	return (newZ);
}
