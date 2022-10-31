/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:42:49 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 06:17:00 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private :
		Brain	*brain;

	public :
		Dog(void);
		Dog(Dog const &cpy);
		~Dog(void);

		Dog	&operator=(Dog const &cpy);

		void	makeSound(void);
};

#endif
