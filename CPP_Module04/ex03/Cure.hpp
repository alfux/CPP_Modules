/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:07:10 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 03:05:21 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class	Cure : public AMateria
{
	public :
		Cure(void);
		Cure(Cure const &cpy);
		~Cure(void);

		Cure	&operator=(Cure const &cpy);

		void		use(ICharacter &target);
		AMateria	*clone(void) const;
};

#endif
