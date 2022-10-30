/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:57:56 by alfux             #+#    #+#             */
/*   Updated: 2022/10/30 02:36:19 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

# define CLAPGOD ((unsigned int)(1 << 31) | ((unsigned int)(1 << 31) - 1))

class	ClapTrap
{
	private :
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;

	public :
		ClapTrap(void);
		ClapTrap(std::string const &new_name);
		ClapTrap(ClapTrap const &cpy);
		~ClapTrap(void);

		ClapTrap	&operator=(ClapTrap const &cpy);

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
