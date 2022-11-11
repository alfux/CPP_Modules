/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 03:37:34 by alfux             #+#    #+#             */
/*   Updated: 2022/11/11 17:36:35 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ITER_HPP
# define ITER_HPP

template <typename t_tab, typename t_fun>
	void	iter(t_tab *tab, size_t size, t_fun (*f)(t_tab *elm))
{
	size_t	i;

	for (i = 0; i < size; i++)
		(void)(*f)(tab + i);
}

template <typename t_arg, typename t_ret>
	t_ret	addone(t_arg *arg)
{
	*arg += '1';
	return ((t_ret)0);
}

#endif
