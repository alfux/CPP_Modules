/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:16:51 by alfux             #+#    #+#             */
/*   Updated: 2022/11/14 02:43:42 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Span.hpp"

char const	*Span::FullSpan::what(void) const throw ()
	{return ("error: cannot add to full span");}

char const	*Span::NoDistance::what(void) const throw ()
	{return ("error: cannot find distance with less than two elements");}

Span::Span(uint64_t const &max) : elem(), max_size(max), min_dist(UINT64_MAX) {}

Span::Span(Span const &cpy)
	: elem(cpy.elem), max_size(cpy.max_size), min_dist(cpy.min_dist) {}

Span::~Span(void) {}

Span	&Span::operator=(Span const &cpy)
{
	this->elem = cpy.elem;
	this->max_size = cpy.max_size;
	this->min_dist = cpy.min_dist;
	return (*this);
}

uint64_t	Span::distance(int64_t const &n, int64_t const &m)
{
	if (n > m)
		return (n - m);
	return (m - n);
}

void	Span::addNumber(int64_t const &n)
{
	t_iterator	it;
	uint64_t	dist;

	if (this->elem.size() + 1 > this->max_size)
		throw (Span::FullSpan());
	this->elem.push_back(n);
	if (this->elem.size() < 2 || this->min_dist == 0)
		return ;
	for (it = this->elem.begin(); it != std::prev(this->elem.end()); ++it)
	{
		dist = this->distance(*it, n);
		if (dist < this->min_dist)
			this->min_dist = dist;
	}
}

uint64_t	Span::shortestSpan(void) const
{
	if (this->elem.size() < 2)
		throw (Span::NoDistance());
	return (this->min_dist);
}

uint64_t	Span::longestSpan(void) const
{
	if (this->elem.size() < 2)
		throw (Span::NoDistance());
	return (*std::max_element(this->elem.begin(), this->elem.end())
		- *std::min_element(this->elem.begin(), this->elem.end()));
}
