/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:40:07 by alfux             #+#    #+#             */
/*   Updated: 2022/10/28 04:41:23 by alfux            ###   ########.fr       */
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
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int null);
		Fixed	operator--(int null);
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;
		int		operator>(Fixed const &rhs) const;
		int		operator>=(Fixed const &rhs) const;
		int		operator<(Fixed const &rhs) const;
		int		operator<=(Fixed const &rhs) const;
		int		operator==(Fixed const &rhs) const;
		int		operator!=(Fixed const &rhs) const;

		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	min(Fixed const &a, Fixed const &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static Fixed	max(Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<(std::ostream &flux, Fixed const &n);

#endif
