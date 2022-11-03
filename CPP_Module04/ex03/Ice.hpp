/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:58:08 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 03:04:02 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class	Ice : public AMateria
{
	public :
		Ice(void);
		Ice(Ice const &cpy);
		~Ice(void);

		Ice	&operator=(Ice const &cpy);

		void		use(ICharacter &target);
		AMateria	*clone(void) const;
};

#endif
