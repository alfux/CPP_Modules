/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:34:29 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 03:09:49 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
	{std::cout << "[IMateriaSource's default constructor called]" << std::endl;}

IMateriaSource::IMateriaSource(IMateriaSource const &cpy)
{
	(void)cpy;
	std::cout << "[IMateriaSource's copy constructor called]" << std::endl;
}

IMateriaSource::~IMateriaSource(void)
	{std::cout << "[IMateriaSource's destructor called]" << std::endl;}

IMateriaSource	&IMateriaSource::operator=(IMateriaSource const &cpy)
{
	(void)cpy;
	return (*this);
}
