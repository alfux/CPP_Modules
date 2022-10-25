/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RStream.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:42:00 by alfux             #+#    #+#             */
/*   Updated: 2022/10/25 17:50:10 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RSTREAM_HPP
# define RSTREAM_HPP
# include <iostream>
# include <fstream>
# include <string>

class	RStream
{
	private :
		std::fstream	in;
		std::fstream	out;
		std::string		str;
	
	public :
		RStream(void);
		void	open(std::string file_name);
		void	replace(std::string s1, std::string s2);
		~RStream(void);
};

#endif
