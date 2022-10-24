/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:06:49 by alfux             #+#    #+#             */
/*   Updated: 2022/10/24 22:59:54 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>
# include <exception>

class	Zombie
{
	private :
		std::string	name;
		static int	nbZ;

	public :
		Zombie(void);
		Zombie(std::string newname);
		void	announce(void);
		~Zombie(void);

		Zombie	&operator=(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
