/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:01:08 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 06:22:29 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"
# include "Brain.hpp"

class	WrongCat : public WrongAnimal
{
	private :
		Brain	*brain;

	public :
		WrongCat(void);
		WrongCat(WrongCat const &cpy);
		~WrongCat(void);

		WrongCat	&operator=(WrongCat const &cpy);

		void	makeSound(void);
};

#endif
