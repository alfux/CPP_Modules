/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:49:24 by alfux             #+#    #+#             */
/*   Updated: 2022/10/26 02:06:27 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class	Harl
{
	private :
		void	(Harl::*ptr[5])(void);

		void	einval(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public :
		Harl(void);
		void	complain(std::string level);
		~Harl(void);
};

#endif
