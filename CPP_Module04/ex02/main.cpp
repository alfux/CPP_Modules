/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:15:04 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 17:59:20 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"
#include "Dog.hpp"

#define A_ARMY 10 * 2

int	main(void)
{
	Animal	*tab[A_ARMY];
	Animal	*ptr;
	int		i;

	for (i = 0; i < A_ARMY - 1; i += 2)
	{
		tab[i] = new Dog();
		tab[i + 1] = new Cat();
	}
	ptr = new Dog(*(Dog *)tab[0]);
	for (i = 0; i < A_ARMY - 1; i += 2)
	{
		std::cout << tab[i]->getType() << ": ";
		tab[i]->makeSound();
		std::cout << tab[i + 1]->getType() << ": ";
		tab[i + 1]->makeSound();
	}
	std::cout << ptr->getType() << ": ";
	ptr->makeSound();
	for (i = 0; i < A_ARMY; i++)
		delete tab[i];
	delete ptr;
	return (0);
}
