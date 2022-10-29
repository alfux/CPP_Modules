/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:21:59 by alfux             #+#    #+#             */
/*   Updated: 2022/10/29 07:45:55 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class	Point
{
	private :
		Fixed const	x;
		Fixed const	y;
		Fixed		x_base;
		Fixed		y_base;

	public :
		Point(void);
		Point(float const, float const);
		Point(Point const &);
		~Point(void);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
		Fixed	getXBase(void) const;
		Fixed	getYBase(void) const;

		Point	&operator=(Point const &);
		Point	operator-(Point const &) const;

		static Point	inBase(Point const &p, Point const &i, Point const &j);
};

#endif
