/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 05:49:21 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 16:46:26 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

# define B_IMAGINATION 100

class	Brain
{
	private :
		std::string	ideas[B_IMAGINATION];

	public :
		Brain(void);
		Brain(Brain const &cpy);
		~Brain(void);

		Brain	&operator=(Brain const &cpy);
};

#endif
