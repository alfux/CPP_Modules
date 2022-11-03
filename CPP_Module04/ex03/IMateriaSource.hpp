/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:28:13 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 03:01:00 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>
# include "AMateria.hpp"

class	IMateriaSource
{
	public :
		IMateriaSource(void);
		IMateriaSource(IMateriaSource const &cpy);
		virtual	~IMateriaSource(void);

		IMateriaSource		&operator=(IMateriaSource const &cpy);

		virtual void		learnMateria(AMateria *m) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif
