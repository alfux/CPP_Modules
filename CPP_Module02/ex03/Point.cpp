/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:22:54 by alfux             #+#    #+#             */
/*   Updated: 2022/10/29 07:46:48 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

Point::Point(void) {}

Point::Point(float const _x, float const _y) : x(_x), y(_y) {}

Point::Point(Point const &cpy) : x(cpy.x), y(cpy.y) {}

Point::~Point(void) {}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}

Fixed	Point::getXBase(void) const
{
	return (this->x_base);
}

Fixed	Point::getYBase(void) const
{
	return (this->y_base);
}

Point	&Point::operator=(Point const &aff)
{
	this->x_base = aff.x;
	this->y_base = aff.y;
	return (*this);
}

Point	Point::operator-(Point const &start_of_vector) const
{	
	return (Point((this->x - start_of_vector.x).toFloat(),
		(this->y - start_of_vector.y).toFloat()));
}

Point	Point::inBase(Point const &p, Point const &i, Point const &j)
{
	Fixed	det((i.x * j.y) - (i.y * j.x));

	if (det == 0)
		throw (false);
	return (Point((((j.y * p.x) - (j.x * p.y)) / det).toFloat(),
		(((i.x * p.y) - (i.y * p.x)) / det).toFloat()));
}
