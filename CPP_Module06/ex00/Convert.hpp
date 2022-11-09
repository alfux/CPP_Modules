/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:10:41 by alfux             #+#    #+#             */
/*   Updated: 2022/11/09 16:50:59 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <iostream>
# include <iomanip>
# include <exception>

class	Convert
{
	private :
		struct	Unknown : std::exception
			{char const	*what(void) const throw();};

		std::string		literal;
		std::string		type;
		char			char_val;
		int				int_val;
		float			float_val;
		double			double_val;
		unsigned int	prec;

		void	findType(void);
		void	assignType(void);
		void	initVal(void);
		void	setPrec(void);

	public :
		Convert(void);
		Convert(std::string const &);
		Convert(Convert const &);
		~Convert(void);

		Convert	&operator=(Convert const &);
		Convert	&operator=(std::string const &);

		char const			&getChar(void) const;
		int const			&getInt(void) const;
		float const			&getFloat(void) const;
		double const		&getDouble(void) const;
		std::string const	&getLiteral(void) const;
		std::string const	&getType(void) const;
		std::ostream		&display(std::ostream &) const;
};

std::ostream	&operator<<(std::ostream &, Convert const &);

#endif
