/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:33:59 by alfux             #+#    #+#             */
/*   Updated: 2022/10/30 04:51:02 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(ScavTrap const &cpy);
		ScavTrap(std::string const &name);
		~ScavTrap(void);

		ScavTrap	&operator=(ScavTrap const &cpy);
		
		void	attack(std::string const &target);
		void	guardGate(void);
};

#endif
