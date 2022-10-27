/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:40:07 by alfux             #+#    #+#             */
/*   Updated: 2022/10/27 22:40:18 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class	Fixed
{
	private :
		static int const	frac;
		unsigned int		bits;

	public :
		Fixed(void);
		Fixed(Fixed const &copy);
		Fixed(int const n);
		Fixed(float const x);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		Fixed	&operator=(Fixed const &rhs);
};

std::ostream	&operator<<(std::ostream &flux, Fixed const &n);

#endif
