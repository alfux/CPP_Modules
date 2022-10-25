/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:13:50 by alfux             #+#    #+#             */
/*   Updated: 2022/10/25 01:58:59 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class	HumanA
{
	private :
		Weapon		&weapon;
		std::string	name;
	
	public :
		HumanA(std::string new_name, Weapon &w);
		void	attack(void);
		~HumanA(void);
};

#endif
