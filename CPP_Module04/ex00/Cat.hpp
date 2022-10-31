/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:01:08 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 06:17:11 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class	Cat : public Animal
{
	public :
		Cat(void);
		Cat(Cat const &cpy);
		~Cat(void);

		Cat	&operator=(Cat const &cpy);

		void	makeSound(void);
};

#endif
