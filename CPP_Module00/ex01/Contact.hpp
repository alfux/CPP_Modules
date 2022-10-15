/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:24:26 by alfux             #+#    #+#             */
/*   Updated: 2022/10/15 06:40:00 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <ctype.h>

class	Contact
{
	private :
		std::string	frst;
		std::string	last;
		std::string	nick;
		std::string	dark;

		int	isempty(std::string &str);

	public :
			Contact(void);
		int	fill(void);
		int	show(void);
		int	isempty(void);
		int	clear(void);
			~Contact(void);
};

#endif
