/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:13:39 by alfux             #+#    #+#             */
/*   Updated: 2022/10/25 01:50:34 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class	Weapon
{
	private :
		std::string	type;

	public :
		Weapon(void);
		Weapon(std::string new_type);
		std::string const	&getType(void);
		void				setType(std::string new_type);
		~Weapon(void);
};

#endif
