/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 03:04:01 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 05:13:26 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <iostream>

class	WrongAnimal
{
	protected :
		std::string	type;

		WrongAnimal(std::string const &type);
	
	public :
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &cpy);
		virtual	~WrongAnimal(void);

		WrongAnimal	&operator=(WrongAnimal const &cpy);

		void			makeSound(void);
		std::string		getType(void);
};

#endif
