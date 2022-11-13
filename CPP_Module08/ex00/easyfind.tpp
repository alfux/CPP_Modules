/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:10:41 by alfux             #+#    #+#             */
/*   Updated: 2022/11/13 03:19:11 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T> typename T::iterator	easyfind(T &cont, long long integer)
	{return (std::find(cont.begin(), cont.end(), integer));}

#endif
