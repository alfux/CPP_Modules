/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 05:52:51 by alfux             #+#    #+#             */
/*   Updated: 2022/10/31 06:24:30 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "[Brain's default constructor called]" << std::endl;
}

Brain::Brain(Brain const &cpy)
{
	std::cout << "[Brain's copy constructor called]" << std::endl;
	for (int i = 0; i < B_IMAGINATION; i++)
		*(this->ideas + i) = *(cpy.ideas + i);
}

Brain::~Brain(void)
{
	std::cout << "[Brain's destructor called]" << std::endl;
}

Brain	&Brain::operator=(Brain const &cpy)
{
	for (int i = 0; i < B_IMAGINATION; i++)
		*(this->ideas + i) = *(cpy.ideas + i);
	return (*this);
}
