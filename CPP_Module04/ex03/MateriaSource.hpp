/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:43:21 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 03:10:41 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private :
		AMateria	*memory[4];

	public :
		MateriaSource(void);
		MateriaSource(MateriaSource const &cpy);
		~MateriaSource(void);

		MateriaSource	&operator=(MateriaSource const &cpy);

		void			learnMateria(AMateria *m);
		AMateria		*createMateria(std::string const &type);
};

#endif
