/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:13:50 by alfux             #+#    #+#             */
/*   Updated: 2022/10/25 02:16:26 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class	HumanB
{
	private :
		Weapon		*weapon;
		std::string	name;
	
	public :
		HumanB(std::string new_name);
		void	setWeapon(Weapon &w);
		void	attack(void);
		~HumanB(void);
};

#endif
