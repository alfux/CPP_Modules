/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:05:35 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 03:09:01 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class	Character : public ICharacter
{
	private :
		std::string	name;
		AMateria	*inventory[4];

	public :
		Character(void);
		Character(Character const &cpy);
		Character(std::string const &name);
		~Character(void);

		Character	&operator=(Character const &cpy);
		
		std::string const	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};

#endif
