/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:16:23 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 01:45:59 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private :
		std::string	name;

	public :
		DiamondTrap(void);
		DiamondTrap(DiamondTrap const &cpy);
		DiamondTrap(std::string const &name);
		~DiamondTrap(void);

		DiamondTrap	&operator=(DiamondTrap const &cpy);

		void	whoAmI(void);
};

#endif
