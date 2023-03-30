/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:45:39 by alfux             #+#    #+#             */
/*   Updated: 2023/03/30 04:35:53 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Error.hpp>

Error::Error(void): wht(strerror(errno)) {}

Error::Error(Error const &cpy):
	std::exception(cpy),
	wht(cpy.wht) {}

Error::Error(std::string const &err): wht(err) {}

Error::~Error(void) _NOEXCEPT {}

Error	&Error::operator=(Error const &cpy)
{
	this->std::exception::operator=(cpy);
	this->wht = cpy.wht;
	return (*this);
}

char const	*Error::what(void) const throw()
{
	return (wht.c_str());
}
