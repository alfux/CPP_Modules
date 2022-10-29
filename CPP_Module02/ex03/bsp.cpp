/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:04:13 by alfux             #+#    #+#             */
/*   Updated: 2022/10/29 07:31:14 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	vect_ab(b - a);
	Point	vect_ac(c - a);
	Point	point_base(point - a);

	try
		{point_base = Point::inBase(point_base, vect_ab, vect_ac);}
	catch (...)
		{return (false);}
	if (point_base.getXBase() <= 0 || point_base.getYBase() <= 0
		|| Fixed(1) - point_base.getXBase() - point_base.getYBase() <= 0)
		return (false);
	return (true);
}
