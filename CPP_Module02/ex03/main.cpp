/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 04:53:57 by alfux             #+#    #+#             */
/*   Updated: 2022/10/29 07:35:29 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	draw(Point const &a, Point const &b, Point const &c, Point const &p)
{
	int	i;
	int	j;
	
	for (j = 0; j < 83; j++)
		std::cout << '-';
	std::cout << std::endl;
	for (i = 0; i < 35; i++)
	{
		std::cout << '|';
		for (j = 0; j < 81; j++)
		{
			if (i - 17 == p.getX().toInt() && j - 41 == p.getY().toInt())
				std::cout << "\001\033[31m\002x\003\033[0m";
			else if ((i - 17 == a.getX().toInt() && j - 41 == a.getY().toInt())
				|| (i - 17 == b.getX().toInt() && j - 41 == b.getY().toInt())
				|| (i - 17 == c.getX().toInt() && j - 41 == c.getY().toInt()))
				std::cout << 'x';
			else
				std::cout << ' ';
		}
		std::cout << '|' << std::endl;
	}
	for (j = 0; j < 83; j++)
		std::cout << '-';
	std::cout << std::endl;
}

int	main(void)
{
	Point	a(10.f, 8.f);
	Point	b(3.f, -38.f);
	Point	c(-10.f, 15.f);
	Point	p(4.f, 5.f);
	
	draw(a, b, c, p);
	if (bsp(a, b, c, p))
		std::cout << "Yay, the G spot is in !" << std::endl;
	else
		std::cout << "Oh no... the G spot is out..." << std::endl;
	return (0);
}



















