/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:48:32 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 02:59:13 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

class	ICharacter;

class	AMateria
{
	protected :
		std::string const	type;

	public :
		AMateria(void);
		AMateria(AMateria const &cpy);
		AMateria(std::string const &type);
		virtual	~AMateria(void);

		AMateria	&operator=(AMateria const &cpy);

		std::string const	&getType(void) const;
		virtual void		use(ICharacter &target);
		virtual AMateria	*clone(void) const = 0;
};

#endif
