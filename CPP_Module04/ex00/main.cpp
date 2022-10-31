/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:18:19 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 04:52:22 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal	*meta = new Animal();
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();
	Animal	*copycat = new Animal(*cat);

	std::cout << std::endl << meta->getType() << ": ";
	meta->makeSound();
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << cat->getType() << ": ";
	cat->makeSound();
	std::cout << copycat->getType() << ": ";
	copycat->makeSound();
	std::cout << std::endl;
	delete meta;
	delete dog;
	delete cat;
	delete copycat;
	return (0);
}
