/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:04:01 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 04:29:51 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>

class	Animal
{
	protected :
		std::string	type;

		Animal(std::string const &type);
	
	public :
		Animal(void);
		Animal(Animal const &cpy);
		virtual	~Animal(void);

		Animal	&operator=(Animal const &cpy);

		virtual void	makeSound(void);
		std::string		getType(void);
};

#endif
