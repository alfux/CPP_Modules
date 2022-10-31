/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:42:49 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 04:04:14 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class	Dog : public Animal
{
	public :
		Dog(void);
		Dog(Dog const &cpy);
		~Dog(void);

		Dog	&operator=(Dog const &cpy);

		void	makeSound(void);
};

#endif
