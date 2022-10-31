/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:33:59 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 01:45:48 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public :
		FragTrap(void);
		FragTrap(FragTrap const &cpy);
		FragTrap(std::string const &name);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &cpy);
		
		void	highFivesGuys(void);
};

#endif
