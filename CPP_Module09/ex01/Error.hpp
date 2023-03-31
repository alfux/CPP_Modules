/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 04:12:18 by alfux             #+#    #+#             */
/*   Updated: 2023/03/31 05:19:16 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP
# include <cerrno>
# include <string>
# include <exception>

# define EARG "invalid argument."
# define ESYN "invalid syntax."

class	Error: public std::exception
{
	std::string	wht;

	public:
		Error(void);
		Error(Error const &cpy);
		Error(std::string const &err);
		~Error(void) _NOEXCEPT;

		Error	&operator=(Error const &cpy);

		char const	*what(void) const throw();
};

#endif
