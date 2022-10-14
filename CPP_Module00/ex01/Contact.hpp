/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:24:26 by alfux             #+#    #+#             */
/*   Updated: 2022/10/14 20:11:18 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <ctype.h>

class	Contact
{
	std::string	frst;
	std::string	last;
	std::string	nick;
	std::string	dark;

	int	isempty(std::string &str);
	public :
				Contact();
		void	fill();
		void	show();
				~Contact();
};

#endif
