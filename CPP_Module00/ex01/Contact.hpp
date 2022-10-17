/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:24:26 by alfux             #+#    #+#             */
/*   Updated: 2022/10/17 06:44:51 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <iomanip>
# include <ctype.h>

class	Contact
{
	std::string	frst;
	std::string	last;
	std::string	nick;
	std::string numb;
	std::string	dark;

	int	isempty(std::string &str);
	int prntblk(std::string str);
	int	fillblk(std::string pmt, std::string &str);
	int	fillnum(std::string pmt, std::string &num);

	public :
			Contact(void);
		int	fill(void);
		int	show(void);
		int	colones(void);
		int	isempty(void);
		int	clear(void);
			~Contact(void);
};

#endif
