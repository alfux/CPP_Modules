/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 03:06:59 by alfux             #+#    #+#             */
/*   Updated: 2022/11/11 03:24:44 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename t_type> void		swap(t_type &a, t_type &b)
{
	t_type	buf;

	buf = a;
	a = b;
	b = buf;
}

template <typename t_type> t_type	min(t_type a, t_type b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename t_type> t_type	max(t_type a, t_type b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
