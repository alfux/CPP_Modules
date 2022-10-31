/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:18:19 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 16:30:20 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal		*meta = new Animal();
	Animal		*dog = new Dog();
	Animal		*cat = new Cat();
	WrongAnimal	*wrongcat = new WrongCat();
	WrongCat	*truewrongcat = (WrongCat *)wrongcat;
	Animal		*copycat = new Animal(*cat);

	std::cout << std::endl << meta->getType() << ": ";
	meta->makeSound();
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << cat->getType() << ": ";
	cat->makeSound();
	std::cout << wrongcat->getType() << ": ";
	wrongcat->makeSound();
	std::cout << truewrongcat->getType() << ": ";
	truewrongcat->makeSound();
	std::cout << copycat->getType() << ": ";
	copycat->makeSound();
	std::cout << std::endl;
	delete meta;
	delete dog;
	delete cat;
	delete copycat;
	delete wrongcat;
	return (0);
}
